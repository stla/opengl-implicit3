{-# LANGUAGE ForeignFunctionInterface #-}
module MarchingCubes.ComputeContour3d
  (computeContour3d', XYZ, Triangle)
  where
import Control.Monad ((=<<), when)
import           Foreign.C.Types       
import           Foreign.Marshal.Alloc (free, mallocBytes)
import           Foreign.Marshal.Array (peekArray)
import           Foreign.Ptr (Ptr)
import Foreign.Storable (peek, sizeOf)
import MarchingCubes.Voxel
import Data.Maybe
import Data.List.Split (chunksOf)
import Data.List (transpose)

type XYZ = (Double,Double,Double)
type Triangle = (XYZ, XYZ, XYZ)

toTriangles :: [[Double]] -> [Triangle]
toTriangles trianglesAsList = map toTriangle (chunksOf 3 trianglesAsList)
  where
    toTriangle :: [[Double]] -> Triangle
    toTriangle triangleAsList = toTriplet (map toTriplet triangleAsList)
      where
      toTriplet [x,y,z] = (x,y,z)
      toTriplet _       = undefined
    

foreign import ccall unsafe "computeContour3d" c_computeContour3d
    :: (Ptr (Ptr (Ptr CDouble)))
    -> CUInt
    -> CUInt
    -> CUInt
    -> CDouble
    -> CDouble
    -> Ptr CSize
    -> IO (Ptr (Ptr CDouble))

computeContour3d :: Voxel -> Maybe Double -> Double 
                 -> IO ((Ptr (Ptr CDouble)), Int)
computeContour3d voxel voxmax level = do
    voxelmax <- voxelMax voxel
    let max' = fromMaybe (realToFrac $ voxelmax) voxmax
    nrowsPtr <- mallocBytes (sizeOf (undefined :: CSize))
    result <- c_computeContour3d (fst voxel) 
              (fromIntegral nx) (fromIntegral ny) (fromIntegral nz) 
              (realToFrac max') (realToFrac level) nrowsPtr
    nrows <- peek nrowsPtr
    free nrowsPtr
    return (result, fromIntegral nrows)
    where
    (_, (nx,ny,nz)) = voxel 

computeContour3d' :: Voxel -> Maybe Double -> Double 
                  -> IO [Triangle]
computeContour3d' voxel voxmax level = do
    (ppCDouble, nrows) <- computeContour3d voxel voxmax level
    points <- mapM (peekArray nrows) =<< (peekArray 3 ppCDouble)
    return $ toTriangles (transpose (map (map realToFrac) points))
