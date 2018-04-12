module Test
  where 
import Foreign.C.Types
import Foreign
import Voxel
import ComputeContour3d

f :: (Double, Double, Double) -> Double
f (x,y,z) = x*x + y*y + z*z 

vox :: IO Voxel
vox = makeVoxel f ((-2,2),(-2,2),(-2,2)) (5,5,5)

contour3d :: IO ((Ptr (Ptr CDouble)), Int)
contour3d = do
    voxl <- vox
    computeContour3d voxl (Just 100) 1

test :: IO [[CDouble]]
test = do 
    vox <- makeVoxel f ((-2,2),(-2,2),(-2,2)) (80,80,80)
    computeContour3d' vox (Just 100) 1
  