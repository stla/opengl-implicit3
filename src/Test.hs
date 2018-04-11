module Test
  where 
import Foreign.C.Types
import Foreign
import Voxel
import ComputeContour3d

f :: (Double, Double, Double) -> Double
f (x,y,z) = x + y + z 

vox :: IO (Ptr (Ptr (Ptr CDouble)))
vox = voxel f ((0,2),(0,2),(0,2)) 4

contour3d :: IO ((Ptr (Ptr CDouble)), Int)
contour3d = do
    voxl <- vox
    computeContour3d voxl 2 (Just 100) 1

-- test :: IO [[CDouble]]
-- test = do 
--     vox <- voxel f ((0,2),(0,2),(0,2)) 4
--     computeContour3d' vox 4 (Just 100) 1
  