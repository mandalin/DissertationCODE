# Install script for directory: /Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/Developer/VTK/VTK-Bin")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-5.6" TYPE FILE FILES
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_kbufferVP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k2FP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k2BeginFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k2EndFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k6FP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k6BeginFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkHAVSVolumeMapper_k6EndFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_FourDependentNoShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_FourDependentShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_OneComponentNoShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_OneComponentShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_TwoDependentNoShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeTextureMapper3D_TwoDependentShadeFP.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/VolumeRendering/vtkVolumeRenderingToolkit.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6" TYPE STATIC_LIBRARY FILES "/Volumes/Macintosh HD/Developer/VTK/VTK-Build2/bin/libvtkVolumeRendering.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkVolumeRendering.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkVolumeRendering.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkVolumeRendering.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-5.6" TYPE FILE FILES
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkDirectionEncoder.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkEncodedGradientEstimator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkEncodedGradientShader.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFiniteDifferenceGradientEstimator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointRayCastImage.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastCompositeGOHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastCompositeGOShadeHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastCompositeHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastCompositeShadeHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastMIPHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkFixedPointVolumeRayCastMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkGPUVolumeRayCastMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkHAVSVolumeMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkProjectedTetrahedraMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkRayCastImageDisplayHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkRecursiveSphereDirectionEncoder.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkSphericalDirectionEncoder.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeOutlineSource.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumePicker.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeProMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRayCastCompositeFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRayCastFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRayCastIsosurfaceFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRayCastMIPFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRayCastMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeRenderingFactory.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeTextureMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeTextureMapper2D.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkVolumeTextureMapper3D.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridBunykRayCastFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridHomogeneousRayIntegrator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridLinearRayIntegrator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridPartialPreIntegration.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridPreIntegration.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeRayCastFunction.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeRayCastIterator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeRayIntegrator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeRayCastMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkUnstructuredGridVolumeZSweepMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLGPUVolumeRayCastMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLHAVSVolumeMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLProjectedTetrahedraMapper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLRayCastImageDisplayHelper.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLVolumeTextureMapper2D.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VolumeRendering/vtkOpenGLVolumeTextureMapper3D.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6" TYPE FILE FILES "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Utilities/InstallOnly/vtkVolumeRenderingKit.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

