cmake_minimum_required(VERSION 3.8)
project(sample_project)

enable_testing()

SET ( CMAKE_VERBOSE_MAKEFILE false )

SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
#
#SET ( OUTPUT_ELF "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.out")
#SET ( SRC_FILES bar.c foo.c main.c )

SET ( CMAKE_C_COMPILER "gcc" )
SET ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -g -Wall -Wconversion")
SET ( CMAKE_CXX_COMPILER "g++" )
SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wconversion")

ADD_COMPILE_OPTIONS ( -g -Wall -Wconversion )

# "Debug" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_DEBUG "-DC_FLAGS -O0 -g3" )
#SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS" )

# "Release" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_RELEASE "-DC_FLAGS -O3" )
#SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS" )

# the compiler flags for compiling C sources
MESSAGE( STATUS "CMAKE_C_FLAGS: " ${CMAKE_C_FLAGS} )

# the compiler flags for compiling C++ sources
MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )


# Choose the type of build.  Example: SET(CMAKE_BUILD_TYPE Debug)
MESSAGE( STATUS "CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE} )

# if this is set to ON, then all libraries are built as shared libraries by default.
MESSAGE( STATUS "BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS} )

# the compiler used for C files
MESSAGE( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )

# the compiler used for C++ files
MESSAGE( STATUS "CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER} )

# if the compiler is a variant of gcc, this should be set to 1
MESSAGE( STATUS "CMAKE_COMPILER_IS_GNUCC: " ${CMAKE_COMPILER_IS_GNUCC} )

# if the compiler is a variant of g++, this should be set to 1
MESSAGE( STATUS "CMAKE_COMPILER_IS_GNUCXX : " ${CMAKE_COMPILER_IS_GNUCXX} )

SET (INC_PATH_GLIB /usr/local/include/glib-2.0 /usr/local/lib/glib-2.0/include /usr/local/include/gio-unix-2.0)
SET (LIB_GLIB gio-2.0 gobject-2.0 glib-2.0)
SET (LIB_PATH_GLIB /usr/local/lib)

add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_C_STANDARD 11)
