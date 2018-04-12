{-# LANGUAGE ForeignFunctionInterface #-}
module MarchingCubes.Voxel
  (makeVoxel, voxelMax, Voxel)
  where
import Control.Monad ((=<<))
import           Foreign.C.Types       
-- import           Foreign.Marshal.Alloc (free, mallocBytes)
import           Foreign.Marshal.Array (peekArray)
import           Foreign.Ptr           (FunPtr, Ptr, freeHaskellFunPtr)
-- import           Foreign.Storable      (poke, peek, sizeOf)

type Voxel = (Ptr (Ptr (Ptr CDouble)), (Int,Int,Int))

type CFunction = CDouble -> CDouble -> CDouble -> IO CDouble

foreign import ccall safe "wrapper" functionPtr :: CFunction -> IO (FunPtr CFunction)

foreign import ccall safe "voxel" c_voxel
    :: FunPtr CFunction
    -> CDouble
    -> CDouble
    -> CDouble
    -> CDouble
    -> CDouble
    -> CDouble
    -> CUInt
    -> CUInt
    -> CUInt
    -> IO (Ptr (Ptr (Ptr CDouble)))

fun2cfun :: ((Double,Double,Double) -> Double) -> CFunction
fun2cfun f x y z = do
    return $ realToFrac (f (realToFrac x, realToFrac y, realToFrac z))

makeVoxel :: ((Double,Double,Double) -> Double)
          -> ((Double,Double),(Double,Double),(Double,Double))
          -> (Int, Int, Int)
          -> IO Voxel
makeVoxel fun ((xm,xM),(ym,yM),(zm,zM)) (nx, ny, nz) = do
    funPtr <- (functionPtr (fun2cfun fun))
    result <- c_voxel funPtr (realToFrac xm) (realToFrac xM)
                             (realToFrac ym) (realToFrac yM) 
                             (realToFrac zm) (realToFrac zM)
                             (fromIntegral nx) (fromIntegral ny) (fromIntegral nz)
    freeHaskellFunPtr funPtr
    return (result, (nx,ny,nz))

voxel2tripleList :: Voxel -> IO [[[CDouble]]]
voxel2tripleList (pppCDouble, (nx,ny,nz)) = 
    mapM (mapM (peekArray nz)) =<< (mapM (peekArray ny) =<< ((peekArray nx) pppCDouble))
    --- where n' = n-1

voxelMax :: Voxel -> IO CDouble
voxelMax voxel = do 
    tripleList <- voxel2tripleList voxel
    return $ maximum (concat . concat $ tripleList)    

test_fVoxel :: (Double,Double,Double) -> Double
test_fVoxel (x,y,z) = x+y+z