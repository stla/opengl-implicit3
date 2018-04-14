module MarchingCubes.Test
  where
import           Foreign
import           Foreign.C.Types
import           MarchingCubes.ComputeContour3d
import           MarchingCubes.Utils.Triangles  (Triangle, XYZ)
import           MarchingCubes.Voxel

f :: XYZ -> Double
f (x,y,z) = x*x + y*y + z*z

vox :: IO Voxel
vox = makeVoxel f ((-2,2),(-2,2),(-2,2)) (5,5,5)

-- contour3d :: IO ((Ptr (Ptr CDouble)), Int)
-- contour3d = do
--     voxl <- vox
--     computeContour3d voxl (Just 100) 1

test :: IO [Triangle]
test = do
    vox <- makeVoxel f ((-2,2),(-2,2),(-2,2)) (50,50,50)
    computeContour3d' vox (Just 100) 1

