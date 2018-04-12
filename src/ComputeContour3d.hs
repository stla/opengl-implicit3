{-# LANGUAGE ForeignFunctionInterface #-}
module ComputeContour3d
  where
import Control.Monad ((=<<))
import           Foreign.C.Types       
import           Foreign.Marshal.Alloc (free, mallocBytes)
import           Foreign.Marshal.Array (peekArray)
import           Foreign.Ptr (Ptr)
import Foreign.Storable (peek, sizeOf)
import Voxel
import Data.Maybe

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
                  -> IO [[CDouble]]
computeContour3d' voxel voxmax level = do
    (ppCDouble, nrows) <- computeContour3d voxel voxmax level
    mapM (peekArray nrows) =<< (peekArray 3 ppCDouble)

