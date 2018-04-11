{-# LANGUAGE ForeignFunctionInterface #-}
module Voxel
  where
import           Foreign.C.Types       
-- import           Foreign.Marshal.Alloc (free, mallocBytes)
-- import           Foreign.Marshal.Array (peekArray, pokeArray)
import           Foreign.Ptr           (FunPtr, Ptr, freeHaskellFunPtr)
-- import           Foreign.Storable      (poke, peek, sizeOf)

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
    -> IO (Ptr (Ptr (Ptr CDouble)))

fun2cfun :: ((Double,Double,Double) -> Double) -> CFunction
fun2cfun f x y z = do
    return $ realToFrac (f (realToFrac x, realToFrac y, realToFrac z))

voxel :: ((Double,Double,Double) -> Double)
      -> ((Double,Double),(Double,Double),(Double,Double))
      -> Int
      -> IO (Ptr (Ptr (Ptr CDouble)))
voxel fun ((xm,xM),(ym,yM),(zm,zM)) n = do
    funPtr <- (functionPtr (fun2cfun fun))
    result <- c_voxel funPtr (realToFrac xm) (realToFrac xM)
                             (realToFrac ym) (realToFrac yM) 
                             (realToFrac zm) (realToFrac zM)
                             (fromIntegral n)
    freeHaskellFunPtr funPtr
    return result
