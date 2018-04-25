module Spiral
  ( main )
  where
import           Data.IORef
import           Graphics.Rendering.OpenGL.GL
import           Graphics.UI.GLUT
import           MarchingCubes
import           Utils.OpenGL
import           Utils.Misc

data Context = Context
    {
      contextRot1      :: IORef GLfloat
    , contextRot2      :: IORef GLfloat
    , contextRot3      :: IORef GLfloat
    , contextZoom      :: IORef Double
    , contextVoxel     :: IORef Voxel
    , contextTriangles :: IORef [NTriangle]
    }

blue :: Color4 GLfloat
blue = Color4 0 0 1 1

fSpiral :: Double -> Double -> Double -> XYZ -> Double
fSpiral a b c (x,y,z) = - (min (1 - r'') (b - min r2' r''))
  where
    x2 = x*x
    y2 = y*y
    z2 = z*z
    r = sqrt(x2+z2)
    th = atan2 z x
    r' = r + a * th / 2 / pi
    r2 = modulo r' a - a * 0.5
    r2' = if c == 1
      then sqrt(r2 * r2 + y2)
      else if c /= 0
        then (abs r2 ** temp + abs y ** temp) ** (1/temp)
        else max (abs r2) (abs y)
      where
      temp = 2/c
    r'' = sqrt (x2+y2+z2)

voxel :: Double -> Double -> Double -> IO Voxel
voxel a b c = makeVoxel (fSpiral a b c)
                        ((-1,1),(-0.2,0.2),(-1,1))
                        (200, 100, 200)

trianglesSpiral :: Voxel -> IO [NTriangle]
trianglesSpiral vxl = do
  triangles <- computeContour3d'' vxl Nothing 0.0 True
  return $ map fromTriangle triangles

display :: Context -> DisplayCallback
display context = do
  clear [ColorBuffer, DepthBuffer]
  r1 <- get (contextRot1 context)
  r2 <- get (contextRot2 context)
  r3 <- get (contextRot3 context)
  triangles <- get (contextTriangles context)
  zoom <- get (contextZoom context)
  (_, size) <- get viewport
  loadIdentity
  resize zoom size
  rotate (r1+90) $ Vector3 1 0 0
  rotate r2 $ Vector3 0 1 0
  rotate r3 $ Vector3 0 0 1
  renderPrimitive Triangles $ do
    materialDiffuse FrontAndBack $= blue
    mapM_ drawTriangle triangles
  swapBuffers
  where
    drawTriangle ((v1,v2,v3), norm) = do
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
  lookAt (Vertex3 0 0 (-4+zoom)) (Vertex3 0 0 0) (Vector3 0 1 0)
  matrixMode $= Modelview 0
  where
    w' = realToFrac w
    h' = realToFrac h

keyboard :: IORef GLfloat -> IORef GLfloat -> IORef GLfloat -- rotations
         -> IORef Double -> IORef Double -> IORef Double -- parameters a, b and c
         -> IORef Voxel
         -> IORef [NTriangle]
         -> IORef Double -- zoom
         -> KeyboardCallback
keyboard rot1 rot2 rot3 a b c voxelRef trianglesRef zoom char _ = do
  case char of
    'e' -> rot1 $~! subtract 2
    'r' -> rot1 $~! (+ 2)
    't' -> rot2 $~! subtract 2
    'y' -> rot2 $~! (+ 2)
    'u' -> rot3 $~! subtract 2
    'i' -> rot3 $~! (+ 2)
    'm' -> zoom $~! (+ 1)
    'l' -> zoom $~! subtract 1
    'f' -> do
             a $~! (+ 0.025)
             a' <- get a
             b' <- get b
             c' <- get c
             vxl <- voxel a' b' c'
             writeIORef voxelRef vxl
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'v' -> do
             a $~! subtract 0.025
             a' <- get a
             b' <- get b
             c' <- get c
             vxl <- voxel a' b' c'
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'g' -> do
             b $~! (+ 0.1)
             a' <- get a
             b' <- get b
             c' <- get c
             vxl <- voxel a' b' c'
             writeIORef voxelRef vxl
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'b' -> do
             b $~! subtract 0.1
             a' <- get a
             b' <- get b
             c' <- get c
             vxl <- voxel a' b' c'
             writeIORef voxelRef vxl
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'h' -> do
             c $~! (+ 1)
             c' <- get c
             a' <- get a
             b' <- get b
             vxl <- voxel a' b' c'
             writeIORef voxelRef vxl
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'n' -> do
             c $~! subtract 1
             c' <- get c
             a' <- get a
             b' <- get b
             vxl <- voxel a' b' c'
             writeIORef voxelRef vxl
             triangles <- trianglesSpiral vxl
             writeIORef trianglesRef triangles
    'q' -> leaveMainLoop
    _   -> return ()
  postRedisplay Nothing


main :: IO ()
main = do
  _ <- getArgsAndInitialize
  _ <- createWindow "Spiral"
  windowSize $= Size 500 500
  initialDisplayMode $= [RGBAMode, DoubleBuffered, WithDepthBuffer]
  clearColor $= black
  materialAmbient FrontAndBack $= white
  lighting $= Enabled
  lightModelTwoSide $= Enabled
  light (Light 0) $= Enabled
  position (Light 0) $= Vertex4 0 0 (-100) 1
  ambient (Light 0) $= black
  diffuse (Light 0) $= white
  specular (Light 0) $= black
  depthFunc $= Just Less
  shadeModel $= Smooth
  rot1 <- newIORef 0.0
  rot2 <- newIORef 0.0
  rot3 <- newIORef 0.0
  zoom <- newIORef 0.0
  a <- newIORef 0.3
  b <- newIORef 0.1
  c <- newIORef 2.0
  vxl <- voxel 0.3 0.1 2.0
  voxelRef <- newIORef vxl
  triangles <- trianglesSpiral vxl
  trianglesRef <- newIORef triangles
  displayCallback $= display Context {contextRot1 = rot1,
                                      contextRot2 = rot2,
                                      contextRot3 = rot3,
                                      contextZoom = zoom,
                                      contextVoxel = voxelRef,
                                      contextTriangles = trianglesRef}
  reshapeCallback $= Just (resize 0)
  keyboardCallback $= Just (keyboard rot1 rot2 rot3 a b c voxelRef trianglesRef zoom)
  idleCallback $= Nothing
  putStrLn "*** Spiral ***\n\
        \    To quit, press q.\n\
        \    Scene rotation:\n\
        \        e, r, t, y, u, i\n\
        \    Zoom: l, m\n\
        \    Increase/decrease parameters:\n\
        \        f, v, g, b, h, n\n\
        \"
  mainLoop
