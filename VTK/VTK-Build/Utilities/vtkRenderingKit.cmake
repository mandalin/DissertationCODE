# Directory containing class headers.
SET(VTK_RENDERING_HEADER_DIR "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Rendering")

# Classes in vtkRendering.
SET(VTK_RENDERING_CLASSES
  "vtkAbstractMapper3D"
  "vtkAbstractPicker"
  "vtkAbstractPropPicker"
  "vtkAbstractVolumeMapper"
  "vtkActorCollection"
  "vtkActor"
  "vtkAreaPicker"
  "vtkMapArrayValues"
  "vtkAssembly"
  "vtkAxisActor2D"
  "vtkCamera"
  "vtkCameraActor"
  "vtkCameraInterpolator"
  "vtkCellCenterDepthSort"
  "vtkCellPicker"
  "vtkChooserPainter"
  "vtkClipPlanesPainter"
  "vtkCoincidentTopologyResolutionPainter"
  "vtkColorMaterialHelper"
  "vtkCompositePainter"
  "vtkCompositePolyDataMapper2"
  "vtkCompositePolyDataMapper"
  "vtkCullerCollection"
  "vtkCuller"
  "vtkDataSetMapper"
  "vtkDataTransferHelper"
  "vtkDefaultPainter"
  "vtkDisplayListPainter"
  "vtkDistanceToCamera"
  "vtkDynamic2DLabelMapper"
  "vtkDummyGPUInfoList"
  "vtkExporter"
  "vtkFollower"
  "vtkFrameBufferObject"
  "vtkFrustumCoverageCuller"
  "vtkGenericRenderWindowInteractor"
  "vtkGenericVertexAttributeMapping"
  "vtkGPUInfo"
  "vtkGPUInfoList"
  "vtkGraphicsFactory"
  "vtkGraphMapper"
  "vtkGraphToGlyphs"
  "vtkHardwareSelector"
  "vtkHardwareSelectionPolyDataPainter"
  "vtkHierarchicalPolyDataMapper"
  "vtkImageActor"
  "vtkImageMapper"
  "vtkImageViewer2"
  "vtkImageViewer"
  "vtkImagingFactory"
  "vtkImporter"
  "vtkInteractorEventRecorder"
  "vtkInteractorObserver"
  "vtkInteractorStyle"
  "vtkInteractorStyleFlight"
  "vtkInteractorStyleImage"
  "vtkInteractorStyleJoystickActor"
  "vtkInteractorStyleJoystickCamera"
  "vtkInteractorStyleRubberBand2D"
  "vtkInteractorStyleRubberBand3D"
  "vtkInteractorStyleRubberBandPick"
  "vtkInteractorStyleRubberBandZoom"
  "vtkInteractorStyleSwitch"
  "vtkInteractorStyleTerrain"
  "vtkInteractorStyleTrackballActor"
  "vtkInteractorStyleTrackballCamera"
  "vtkInteractorStyleTrackball"
  "vtkInteractorStyleUnicam"
  "vtkInteractorStyleUser"
  "vtkIVExporter"
  "vtkLabeledDataMapper"
  "vtkLabeledTreeMapDataMapper"
  "vtkLabelHierarchy"
  "vtkLabelHierarchyAlgorithm"
  "vtkLabelHierarchyIterator"
  "vtkLabelHierarchyCompositeIterator"
  "vtkLabelPlacer"
  "vtkLabelPlacementMapper"
  "vtkLabelRenderStrategy"
  "vtkLabelSizeCalculator"
  "vtkLeaderActor2D"
  "vtkLightActor"
  "vtkLightCollection"
  "vtkLight"
  "vtkLightingHelper"
  "vtkLightingPainter"
  "vtkLightKit"
  "vtkLineIntegralConvolution2D"
  "vtkLinesPainter"
  "vtkLODActor"
  "vtkLODProp3D"
  "vtkMapperCollection"
  "vtkMapper"
  "vtkOBJExporter"
  "vtkObserverMediator"
  "vtkOOGLExporter"
  "vtkPainter"
  "vtkPainterDeviceAdapter"
  "vtkPainterPolyDataMapper"
  "vtkParallelCoordinatesActor"
  "vtkParallelCoordinatesInteractorStyle"
  "vtkPicker"
  "vtkPixelBufferObject"
  "vtkPointPicker"
  "vtkPointSetToLabelHierarchy"
  "vtkPointsPainter"
  "vtkPOVExporter"
  "vtkPolyDataMapper2D"
  "vtkPolyDataMapper"
  "vtkPolyDataPainter"
  "vtkPolygonsPainter"
  "vtkPrimitivePainter"
  "vtkProp3DCollection"
  "vtkProp3D"
  "vtkProperty"
  "vtkPropPicker"
  "vtkQuadricLODActor"
  "vtkQuaternionInterpolator"
  "vtkRenderedAreaPicker"
  "vtkRendererCollection"
  "vtkRenderer"
  "vtkRendererDelegate"
  "vtkRendererSource"
  "vtkRenderPass"
  "vtkRenderState"
  "vtkRenderWindowCollection"
  "vtkRenderWindow"
  "vtkRenderWindowInteractor"
  "vtkRepresentationPainter"
  "vtkScalarBarActor"
  "vtkScalarsToColorsPainter"
  "vtkScaledTextActor"
  "vtkScenePicker"
  "vtkSelectVisiblePoints"
  "vtkShader"
  "vtkShaderDeviceAdapter"
  "vtkShaderProgram"
  "vtkStandardPolyDataPainter"
  "vtkSurfaceLICDefaultPainter"
  "vtkSurfaceLICPainter"
  "vtkTDxInteractorStyle"
  "vtkTDxInteractorStyleCamera"
  "vtkTDxInteractorStyleSettings"
  "vtkTesting"
  "vtkTestingInteractor"
  "vtkTestingObjectFactory"
  "vtkTextActor3D"
  "vtkTextActor"
  "vtkTextMapper"
  "vtkTextProperty"
  "vtkTexture"
  "vtkTexturedActor2D"
  "vtkTextureObject"
  "vtkTransformInterpolator"
  "vtkTStripsPainter"
  "vtkTupleInterpolator"
  "vtkViewTheme"
  "vtkVisibilitySort"
  "vtkVolumeCollection"
  "vtkVolume"
  "vtkVolumeProperty"
  "vtkVRMLExporter"
  "vtkWindowToImageFilter"
  "vtkWorldPointPicker"
  "vtkVisibleCellSelector"
  "vtkIdentColoredPainter"
  "vtkCoreGraphicsGPUInfoList"
  "vtkFreeTypeUtilities"
  "vtkCameraPass"
  "vtkClearZPass"
  "vtkDefaultPass"
  "vtkDepthPeelingPass"
  "vtkGaussianBlurPass"
  "vtkImageProcessingPass"
  "vtkLightsPass"
  "vtkGLSLShaderDeviceAdapter2"
  "vtkOpaquePass"
  "vtkOpenGLActor"
  "vtkOpenGLCamera"
  "vtkOpenGLClipPlanesPainter"
  "vtkOpenGLCoincidentTopologyResolutionPainter"
  "vtkOpenGLDisplayListPainter"
  "vtkOpenGLExtensionManager"
  "vtkOpenGLHardwareSupport"
  "vtkOpenGLImageActor"
  "vtkOpenGLImageMapper"
  "vtkOpenGLLight"
  "vtkOpenGLLightingPainter"
  "vtkOpenGLPainterDeviceAdapter"
  "vtkOpenGLPolyDataMapper"
  "vtkOpenGLPolyDataMapper2D"
  "vtkOpenGLProperty"
  "vtkOpenGLRenderWindow"
  "vtkOpenGLRenderer"
  "vtkOpenGLRepresentationPainter"
  "vtkOpenGLScalarsToColorsPainter"
  "vtkOpenGLState"
  "vtkOpenGLTexture"
  "vtkOverlayPass"
  "vtkRenderPassCollection"
  "vtkSequencePass"
  "vtkShader2"
  "vtkShader2Collection"
  "vtkShaderProgram2"
  "vtkShadowMapPass"
  "vtkSobelGradientMagnitudePass"
  "vtkTextureUnitManager"
  "vtkTranslucentPass"
  "vtkUniformVariables"
  "vtkVolumetricPass"
  "vtkGLSLShader"
  "vtkGLSLShaderDeviceAdapter"
  "vtkGLSLShaderProgram"
  "vtkFreeTypeLabelRenderStrategy"
  "vtkOpenGLFreeTypeTextMapper"
  "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Rendering/vtkgl"
  "vtkCocoaRenderWindowInteractor.mm"
  "vtkCocoaRenderWindow.mm"
  "vtkCocoaGLView.mm")

# Abstract classes in vtkRendering.
SET(VTK_RENDERING_CLASSES_ABSTRACT
  "vtkAbstractMapper3D"
  "vtkAbstractPicker"
  "vtkAbstractPropPicker"
  "vtkAbstractVolumeMapper"
  "vtkCuller"
  "vtkExporter"
  "vtkGPUInfoList"
  "vtkImporter"
  "vtkInteractorObserver"
  "vtkLabelHierarchyIterator"
  "vtkLabelRenderStrategy"
  "vtkMapper"
  "vtkPainter"
  "vtkPolyDataPainter"
  "vtkPrimitivePainter"
  "vtkProp3D"
  "vtkRendererDelegate"
  "vtkRenderPass"
  "vtkRenderState"
  "vtkShader"
  "vtkShaderDeviceAdapter"
  "vtkShaderProgram"
  "vtkTDxInteractorStyle"
  "vtkVisibilitySort"
  "vtkImageProcessingPass"
  "vtkOpenGLRenderWindow"
  "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Rendering/vtkgl")

# Wrap-exclude classes in vtkRendering.
SET(VTK_RENDERING_CLASSES_WRAP_EXCLUDE
  "vtkLightingHelper"
  "vtkRenderState"
  "vtkTestingInteractor"
  "vtkTestingObjectFactory"
  "vtkFreeTypeUtilities"
  "vtkOpenGLState"
  "vtkShader2"
  "vtkShader2Collection"
  "vtkShaderProgram2"
  "vtkTextureUnitManager"
  "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Rendering/vtkgl"
  "vtkCocoaGLView.mm")

# Set convenient variables to test each class.
FOREACH(class ${VTK_RENDERING_CLASSES})
  SET(VTK_CLASS_EXISTS_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_RENDERING_CLASSES_ABSTRACT})
  SET(VTK_CLASS_ABSTRACT_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_RENDERING_CLASSES_WRAP_EXCLUDE})
  SET(VTK_CLASS_WRAP_EXCLUDE_${class} 1)
ENDFOREACH(class)