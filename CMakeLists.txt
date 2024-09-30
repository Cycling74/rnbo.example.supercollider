cmake_minimum_required(VERSION 3.8)
project(RnboSaw)

set(CMAKE_CXX_STANDARD 11)
set(SC_PATH "${CMAKE_CURRENT_LIST_DIR}/third-party/supercollider")
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/rnbo-export/rnbo)
include_directories(${CMAKE_CURRENT_LIST_DIR}/rnbo-export/rnbo/common)
include_directories(${CMAKE_CURRENT_LIST_DIR}/rnbo-export/rnbo/src)
include_directories(${SC_PATH}/include/plugin_interface)
include_directories(${SC_PATH}/include/common)

set(BUILD_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/rnbo-export/rnbo_source.cpp
    ${CMAKE_CURRENT_LIST_DIR}/rnbo-export/rnbo/RNBO.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/RnboSaw.cpp
)

set(CMAKE_SHARED_MODULE_PREFIX "")
if(APPLE OR WIN32)
    set(CMAKE_SHARED_MODULE_SUFFIX ".scx")
endif()

add_library(RnboSaw MODULE
    ${BUILD_SOURCES}
)

if (APPLE)
  set(INSTALL_BASE "$ENV{HOME}/Library/Application Support/SuperCollider/Extensions/")
elseif (UNIX)
  set(INSTALL_BASE "$ENV{HOME}/.local/share/SuperCollider/Extensions/")
endif()

if (INSTALL_BASE) 
  install(
    FILES ${CMAKE_CURRENT_LIST_DIR}/src/RnboSaw.sc 
    DESTINATION ${INSTALL_BASE}/classes/
  )
  install(
    FILES ${CMAKE_CURRENT_LIST_DIR}/src/RnboSaw.schelp
    DESTINATION ${INSTALL_BASE}/HelpSource/Classes/
  )
  install(
    TARGETS RnboSaw
    DESTINATION ${INSTALL_BASE}/plugins/
  )
endif()
