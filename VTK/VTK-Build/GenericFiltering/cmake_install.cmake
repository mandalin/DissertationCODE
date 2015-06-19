# Install script for directory: /Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6" TYPE STATIC_LIBRARY FILES "/Volumes/Macintosh HD/Developer/VTK/VTK-Build2/bin/libvtkGenericFiltering.a")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkGenericFiltering.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkGenericFiltering.a")
    EXECUTE_PROCESS(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6/libvtkGenericFiltering.a")
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-5.6" TYPE FILE FILES
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericContourFilter.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericGeometryFilter.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericClip.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericProbeFilter.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericDataSetTessellator.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericCutter.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericGlyph3DFilter.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericStreamTracer.h"
    "/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/GenericFiltering/vtkGenericOutlineFilter.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-5.6" TYPE FILE FILES "/Volumes/Macintosh HD/Volumes/Macintosh HD/Developer/VTK/VTK-Build/Utilities/InstallOnly/vtkGenericFilteringKit.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")

