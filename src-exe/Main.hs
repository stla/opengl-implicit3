module Main
  where 
import Foreign.C.Types
import Foreign
import MarchingCubes.Voxel
import MarchingCubes.ComputeContour3d

f :: (Double, Double, Double) -> Double
f (x,y,z) = x*x + y*y + z*z 

vox :: IO Voxel
vox = makeVoxel f ((-2,2),(-2,2),(-2,2)) (5,5,5)

-- contour3d :: IO ((Ptr (Ptr CDouble)), Int)
-- contour3d = do
--     voxl <- vox
--     computeContour3d voxl (Just 12) 1

test :: IO [Triangle]
test = do 
    vox <- makeVoxel f ((-2,2),(-2,2),(-2,2)) (5,5,5)
    computeContour3d' vox (Just 100) 1

main :: IO ()
main = do
    c <- test
    print $ c