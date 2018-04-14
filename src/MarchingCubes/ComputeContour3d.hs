{-# LANGUAGE ForeignFunctionInterface #-}
module MarchingCubes.ComputeContour3d
  (computeContour3d, computeContour3d', computeContour3d'', XYZ, Triangle)
  where
import           Control.Monad         (when, (=<<))
import           Foreign.C.Types
import           Foreign.Marshal.Alloc (free, mallocBytes)
import           Foreign.Marshal.Array (peekArray)
import           Foreign.Ptr           (Ptr)
import           Foreign.Storable      (peek, sizeOf)
import           MarchingCubes.Voxel
-- import Data.Maybe
import           Data.List             (transpose)
import           Data.List.Split       (chunksOf)
import           Data.Tuple.Extra      (fst3, snd3, thd3)

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
    :: Ptr (Ptr (Ptr CDouble))
    -> CUInt
    -> CUInt
    -> CUInt
    -> CDouble
    -> CDouble
    -> Ptr CSize
    -> IO (Ptr (Ptr CDouble))

computeContour3d :: Voxel -> Maybe Double -> Double
                 -> IO (Ptr (Ptr CDouble), Int)
computeContour3d voxel voxmax level = do
    max' <- maybe (voxelMax voxel) return voxmax
    -- voxelmax <- voxelMax voxel
    -- let max' = fromMaybe (realToFrac $ voxelmax) voxmax
    let (_, (nx,ny,nz), _) = voxel
    nrowsPtr <- mallocBytes (sizeOf (undefined :: CSize))
    result <- c_computeContour3d (fst3 voxel)
              (fromIntegral nx) (fromIntegral ny) (fromIntegral nz)
              (realToFrac max') (realToFrac level) nrowsPtr
    nrows <- peek nrowsPtr
    free nrowsPtr
    return (result, fromIntegral nrows)

computeContour3d' :: Voxel -> Maybe Double -> Double
                  -> IO [Triangle]
computeContour3d' voxel voxmax level = do
    (ppCDouble, nrows) <- computeContour3d voxel voxmax level
    points <- mapM (peekArray nrows) =<< peekArray 3 ppCDouble
    return $ toTriangles (transpose (map (map realToFrac) points))

computeContour3d'' :: Voxel -> Maybe Double -> Double
                   -> IO [Triangle]
computeContour3d'' voxel voxmax level = do
  triangles <- computeContour3d' voxel voxmax level
  let nxyz = snd3 voxel
  let xyzbounds = thd3 voxel
  return $ map (rescale xyzbounds nxyz) triangles
    where
    rescale ((xm,xM),(ym,yM),(zm,zM)) (nx,ny,nz) ((x1,y1,z1),(x2,y2,z2),(x3,y3,z3)) =
        ((sx x1, sy y1, sz z1), (sx x2, sy y2, sz z2), (sx x3, sy y3, sz z3))
        where
        s a b n u = a + (b-a) * u / fromIntegral (n-1)
        sx = s xm xM nx
        sy = s ym yM ny
        sz = s zm zM nz

