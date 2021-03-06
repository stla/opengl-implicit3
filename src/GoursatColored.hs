module GoursatColored
  ( main )
  where
import           Data.IORef
import           Graphics.Rendering.OpenGL.GL  hiding (color)
import           Graphics.UI.GLUT              hiding (Triangle, color)
import           MarchingCubes
import           MarchingCubes.Utils.Triangles (triangleNorm2Center)
import           Utils.OpenGL
import           Utils.Palettes

data Context = Context
    {
      contextRot1      :: IORef GLfloat
    , contextRot2      :: IORef GLfloat
    , contextRot3      :: IORef GLfloat
    , contextZoom      :: IORef Double
    , contextVoxel     :: IORef Voxel
    , contextTriangles :: IORef ([Triangle], Double)
    , contextColors    :: IORef [Color4 GLfloat]
    }

fGoursat :: Double -> Double -> XYZ -> Double
fGoursat a b (x,y,z) =
  x4 + y4 + z4 + a*x2y2z2*x2y2z2 + b*x2y2z2
  where
  x2 = x*x
  y2 = y*y
  z2 = z*z
  x2y2z2 = x2+y2+z2
  x4 = x2*x2
  y4 = y2*y2
  z4 = z2*z2

voxel :: Double -> Double -> IO Voxel
voxel a b = makeVoxel (fGoursat a b) ((-3,3),(-3,3),(-3,3))
                      (200, 200, 200)

trianglesGoursat :: Voxel -> Double -> IO ([Triangle], Double)
trianglesGoursat vxl l = computeContour3d''' vxl Nothing l False

funColor :: Int -> Double -> Triangle -> Color4 GLfloat
funColor colormap dmax triangle = palette !! j
  where
    d = triangleNorm2Center triangle
    j = floor (d*255/dmax)
    palettes = ["inferno", "magma", "plasma", "viridis", "cviridis"]
    palette = colorRamp' (palettes !! colormap) 256

display :: Context -> DisplayCallback
display context = do
  clear [ColorBuffer, DepthBuffer]
  r1 <- get (contextRot1 context)
  r2 <- get (contextRot2 context)
  r3 <- get (contextRot3 context)
  (triangles, _) <- get (contextTriangles context)
  colors <- get (contextColors context)
  zoom <- get (contextZoom context)
  (_, size) <- get viewport
  loadIdentity
  resize zoom size
  rotate r1 $ Vector3 1 0 0
  rotate r2 $ Vector3 0 1 0
  rotate r3 $ Vector3 0 0 1
  renderPrimitive Triangles $ mapM_ drawTriangle (zip triangles colors)
  swapBuffers
  where
    drawTriangle (triangle, color) = do
      let ((v1,v2,v3), norm) = fromTriangle triangle
      materialDiffuse FrontAndBack $= color
      normal norm
      vertex v1
      vertex v2
      vertex v3

resize :: Double -> Size -> IO ()
resize zoom s@(Size w h) = do
  viewport $= (Position 0 0, s)
  matrixMode $= Projection
  loadIdentity
  perspective 45.0 (w'/h') 1.0 100.0
  lookAt (Vertex3 0 0 (-10+zoom)) (Vertex3 0 0 0) (Vector3 0 1 0)
  matrixMode $= Modelview 0
  where
    w' = realToFrac w
    h' = realToFrac h

keyboard :: IORef GLfloat -> IORef GLfloat -> IORef GLfloat -- rotations
         -> IORef Double -> IORef Double -- parameters a and b
         -> IORef Double -- isolevel
         -> IORef Voxel
         -> IORef ([Triangle], Double)
         -> IORef [Color4 GLfloat]
         -> IORef Int -- color palette
         -> IORef Double -- zoom
         -> KeyboardCallback
keyboard rot1 rot2 rot3 a b l voxelRef trianglesRef colorsRef p zoom c _ = do
  case c of
    'e' -> rot1 $~! subtract 2
    'r' -> rot1 $~! (+ 2)
    't' -> rot2 $~! subtract 2
    'y' -> rot2 $~! (+ 2)
    'u' -> rot3 $~! subtract 2
    'i' -> rot3 $~! (+ 2)
    'm' -> zoom $~! (+ 1)
    'l' -> zoom $~! subtract 1
    'f' -> do
             a $~! (+ 0.02)
             a' <- get a
             b' <- get b
             vxl <- voxel a' b'
             writeIORef voxelRef vxl
             l' <- get l
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'v' -> do
             a $~! subtract 0.02
             a' <- get a
             b' <- get b
             vxl <- voxel a' b'
             writeIORef voxelRef vxl
             l' <- get l
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'g' -> do
             b $~! (+ 0.03)
             a' <- get a
             b' <- get b
             vxl <- voxel a' b'
             writeIORef voxelRef vxl
             l' <- get l
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'b' -> do
             b $~! subtract 0.03
             a' <- get a
             b' <- get b
             vxl <- voxel a' b'
             writeIORef voxelRef vxl
             l' <- get l
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'h' -> do
             l $~! (+ 0.25)
             l' <- get l
             vxl <- get voxelRef
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'n' -> do
             l $~! subtract 0.25
             l' <- get l
             vxl <- get voxelRef
             triangles <- trianglesGoursat vxl l'
             writeIORef trianglesRef triangles
             p' <- get p
             writeIORef colorsRef $ map (funColor p' (snd triangles)) (fst triangles)
    'p' -> do
             p $~! (\i -> (i+1) `mod` 5)
             p' <- get p
             (triangles, d2max) <- get trianglesRef
             writeIORef colorsRef $ map (funColor p' d2max) triangles
    'q' -> leaveMainLoop
    _   -> return ()
  postRedisplay Nothing

main :: IO ()
main = do
  _ <- getArgsAndInitialize
  _ <- createWindow "Goursat surface"
  windowSize $= Size 500 500
  initialDisplayMode $= [RGBAMode, DoubleBuffered, WithDepthBuffer]
  clearColor $= white
  materialAmbient FrontAndBack $= black
  lighting $= Enabled
  lightModelTwoSide $= Enabled
  light (Light 0) $= Enabled
  position (Light 0) $= Vertex4 0 0 (-100) 1
  ambient (Light 0) $= black
  diffuse (Light 0) $= white
  specular (Light 0) $= white
  depthFunc $= Just Less
  shadeModel $= Smooth
  rot1 <- newIORef 0.0
  rot2 <- newIORef 0.0
  rot3 <- newIORef 0.0
  zoom <- newIORef 0.0
  a <- newIORef (-0.27)
  b <- newIORef (-0.5)
  l <- newIORef 2.0
  vxl <- voxel (-0.27) (-0.5)
  voxelRef <- newIORef vxl
  triangles <- trianglesGoursat vxl 2.0
  trianglesRef <- newIORef triangles
  colorsRef <- newIORef (map (funColor 0 (snd triangles)) (fst triangles))
  pRef <- newIORef 0
  displayCallback $= display Context {contextRot1 = rot1,
                                      contextRot2 = rot2,
                                      contextRot3 = rot3,
                                      contextZoom = zoom,
                                      contextVoxel = voxelRef,
                                      contextTriangles = trianglesRef,
                                      contextColors = colorsRef}
  reshapeCallback $= Just (resize 0)
  keyboardCallback $= Just (keyboard rot1 rot2 rot3 a b l voxelRef trianglesRef colorsRef pRef zoom)
  idleCallback $= Nothing
  putStrLn "*** Goursat surface ***\n\
        \    To quit, press q.\n\
        \    Scene rotation:\n\
        \        e, r, t, y, u, i\n\
        \    Zoom: l, m\n\
        \    Increase/decrease parameters:\n\
        \        f, v, g, b\n\
        \    Increase/decrease isolevel:\n\
        \        h, n\n\
        \    Change color palette: p (this takes a while...) \n\
        \"
  mainLoop
