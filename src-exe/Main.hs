module Main
  where 
import Foreign.C.Types
import Foreign
import Voxel
import ComputeContour3d

f :: (Double, Double, Double) -> Double
f (x,y,z) = x*x + y*y + z*z 

vox :: IO (Ptr (Ptr (Ptr CDouble)))
vox = voxel f ((-2,2),(-2,2),(-2,2)) 30

contour3d :: IO ((Ptr (Ptr CDouble)), Int)
contour3d = do
    voxl <- vox
    computeContour3d voxl 30 Nothing 1

test :: IO [[CDouble]]
test = do 
    vox <- voxel f ((-2,2),(-2,2),(-2,2)) 30
    computeContour3d' vox 3 (Just 100) 1

main :: IO ()
main = do
    c <- test
    print $ c