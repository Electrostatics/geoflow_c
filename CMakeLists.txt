cmake_minimum_required(VERSION 3.8)

enable_testing()

set(CMAKE_VERBOSE_MAKEFILE on)

include(ExternalProject)

project(geoflow_c CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

option(ENABLE_GEOFLOW_APBS "geoflow APBS" OFF)
if(ENABLE_GEOFLOW_APBS)
    add_definitions(-DGEOFLOW_APBS)
    include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_BINARY_DIR}/src
        ${FETK_INSTALL_PREFIX}/include
	)
endif()

set(CMAKE_CXX_STANDARD 11)

SET(geoflow_standalone_CMAKE_DIR "${geoflow_standalone_SOURCE_DIR}/cmake")

set(GOOGLE_LIBS -L$(GMOCK_HOME)/osx -L$(GMOCK_HOME)/osx/gtest 
           -lgtest -lgmock)

set(GOOGLE_INCLUDE -I$(GMOCK_HOME)/include 
	   -I$(GMOCK_HOME)/gtest/include -std=c++11)


#
# Find or install Boost
#
find_package(Boost)
if (NOT Boost_FOUND)
   	ExternalProject_add(boost
		URL http://downloads.sourceforge.net/project/boost/boost/1.60.0/boost_1_60_0.tar.gz
		PREFIX ${CMAKE_BINARY_DIR}/boost
		CONFIGURE_COMMAND ""
		INSTALL_COMMAND ""
		BUILD_COMMAND "")
	ExternalProject_Get_Property(boost source_dir)
	include_directories(${source_dir})
else()
	include_directories(${Boost_INCLUDE_DIRS})
endif()

#
# Find or install Eigen
#
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src/cmake)
find_package(Eigen3)
if (NOT EIGEN3_FOUND)
   	ExternalProject_add(eigen3
		URL https://gitlab.com/libeigen/eigen/-/archive/3.3.5/eigen-3.3.5.tar.gz
		CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR})

	ExternalProject_Get_Property(eigen3 source_dir)
	include_directories(${source_dir})
else()
	include_directories(${EIGEN3_INCLUDE_DIR})
endif()

#
#  add the src dir
#
add_subdirectory(src)

#
#  make testing optional
#
option(ENABLE_TESTS "Tests" OFF)
#if(ENABLE_TESTS)
#  add_subdirectory(test)
#endif()
