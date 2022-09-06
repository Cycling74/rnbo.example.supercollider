cmake_minimum_required(VERSION 3.8)
project(RnboSaw)

set(CMAKE_CXX_STANDARD 11)
set(SC_PATH "${CMAKE_CURRENT_LIST_DIR}/third-party/supercollider")

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
