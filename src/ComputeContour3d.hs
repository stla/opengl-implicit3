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
    -> Ptr CUInt
    -> IO (Ptr (Ptr CDouble))

computeContour3d :: (Ptr (Ptr (Ptr CDouble))) -> Int -> Maybe Double -> Double 
                 -> IO ((Ptr (Ptr CDouble)), Int)
computeContour3d vox n voxmax level = do
    voxelmax <- voxelMax vox n
    let max' = fromMaybe (realToFrac $ voxelmax) voxmax
    nrowsPtr <- mallocBytes (sizeOf (undefined :: CUInt))
    result <- c_computeContour3d vox n' n' n' (realToFrac max') (realToFrac level) nrowsPtr
    nrows <- peek nrowsPtr
    --free nrowsPtr
    return (result, fromIntegral nrows)
    where
    n' = fromIntegral n 

computeContour3d' :: (Ptr (Ptr (Ptr CDouble))) -> Int -> Maybe Double -> Double 
                  -> IO [[CDouble]]
computeContour3d' vox n voxmax level = do
    (ppCDouble, nrows) <- computeContour3d vox n voxmax level
    mapM (peekArray nrows) =<< (peekArray 3 ppCDouble)

