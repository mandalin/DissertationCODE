# Install script for directory: /Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6" TYPE STATIC_LIBRARY FILES "/Volumes/Macintosh HD/Developer/VTK/VTK-Build2/bin/libvtkmetaio.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkmetaio.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkmetaio.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkmetaio.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-5.6/vtkmetaio" TYPE FILE FILES
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/localMetaConfiguration.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaArray.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaArrow.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaBlob.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaCommand.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaContour.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaDTITube.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaEllipse.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaEvent.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaForm.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaGaussian.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaGroup.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaImage.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaImageTypes.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaImageUtils.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaITKUtils.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaLandmark.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaLine.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaMesh.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaObject.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaOutput.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaScene.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaSurface.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaTransform.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaTube.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaTubeGraph.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaTypes.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaUtils.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/Utilities/vtkmetaio/metaVesselTube.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

