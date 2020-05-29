# CMakeLists.txt
# Generates a Makefile for SmileBASIC 
# Created on 3/19/2020
# Created by Andrew Davis
#
# Copyright (C) 2020 Andrew Davis
#
# This program is free software: you can redistribute it and/or modify   
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# include GNUInstallDirs
include(GNUInstallDirs)

# enable testing
enable_testing()

# set the minimum required version
cmake_minimum_required(VERSION 2.8.9)

# make sure that CMake uses C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS, OFF)

# set the project name
project("SmileBASIC")

# set the release type
set(CMAKE_BUILD_TYPE Release)

# load the source files for the library code
file(GLOB_RECURSE LIB_SRCS ${CMAKE_SOURCE_DIR}/src/*.cpp)

# load the main entry point file 
file(GLOB SRCS ${CMAKE_SOURCE_DIR}/src/main.cpp)

# remove main.cpp from the sources
list(FILTER LIB_SRCS EXCLUDE REGEX "main.cpp")

# set the build targets
add_library(sbasic_lib STATIC ${LIB_SRCS})  
add_executable(sbasic ${SRCS})

# link the static library with the C++ math library
target_link_libraries(sbasic_lib m)

# link the library
target_link_libraries(sbasic sbasic_lib)

# add the install target for the executable 
install(TARGETS sbasic DESTINATION $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin)

# load GoogleTest
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

# make sure GoogleTest loaded successfully
if(result)
	message(FATAL_ERROR "CMake step for GoogleTest failed: ${result}")
endif()

# build GoogleTest
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)

# make sure that GoogleTest was built successfully
if(result)
	message(FATAL_ERROR "Build step for GoogleTest failed: ${result}")
endif()

# prevent overridding Orion Engine's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add GoogleTest to the build, which defines gtest and gtest_main
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
		${CMAKE_CURRENT_BINARY_DIR}/googletest-build
		EXCLUDE_FROM_ALL)

# include the GoogleTest include files on versions below CMake 2.8.11
if(CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()

# load the test source file
file(GLOB TESTS ${CMAKE_SOURCE_DIR}/tests/main.cpp)

# create the test executable
add_executable(runTests ${TESTS})

# link it with gtest and orion
target_link_libraries(runTests gtest sbasic_lib)

# add the test to ctest
add_test(NAME SBASICTests COMMAND runTests)

# and add the documentation target
option(BUILD_DOC "Build documentation" ON)
find_package(Doxygen)
if (DOXYGEN_FOUND)
	# set input and output files
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	# request to configure the file
	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("Doxygen build started")

	# add the target
	add_custom_target(docs ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating documentation with Doxygen"
		VERBATIM)
else (DOXYGEN_FOUND)
	message("Doxygen needs to be installed to generate documentation")
endif (DOXYGEN_FOUND)

# end of file
