project (Traffic_Program)
#set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required

cmake_minimum_required (VERSION 3.14.5)



set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_BUILD_TYPE DEBUG)

set(MathGL2_NO_SYSTEM_PATHS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mathgl-2.4.4-mingw.win64)

set(MATHGL2_INCLUDE_DIR "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mathgl-2.4.4-mingw.win64\\include")
set(MATHGL2_LIBRARY "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mathgl-2.4.4-mingw.win64\\lib")
set(MATHGL2_ROOT "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mathgl-2.4.4-mingw.win64")
find_package(MathGL2)
message(STATUS "MathGL2 library status: ${MathGL2_FOUND}")
include_directories("${MATHGL2_INCLUDE_DIR}")
#message(STATUS "MathGL2 include dir: ${MATHGL2_INCLUDE_DIR}")
#message(STATUS "MathGL2 libraries dir: ${MATHGL2_LIBRARY}")
#message(STATUS "MathGL2 root: ${MATHGL2_ROOT}")


set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\boost_1_70_0")
set(BOOST_INCLUDEDIR "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\boost_1_70_0\\boost")
find_package(Boost)

include_directories("${Boost_INCLUDE_DIRS}")
#message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost library status: ${Boost_FOUND}")

set(GSL_ROOT "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\gsl-2.2.1_mingw-6.2.0\\gsl-2.2.1-shared")
set(GSL_INCLUDE_DIR "${GSL_ROOT}\\include")
#set(GSL_LIBRARY "${GSL_ROOT}\\lib")
find_package(GSL REQUIRED)
include_directories("${GSL_INCLUDE_DIR}")
message(STATUS "GSL library status: ${GSL_FOUND}")

#set(CONCPP_ROOT "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mysql-connector-c++-8.0.17-winx64")
#set(CONCPP_INCLUDE "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mysql-connector-c++-8.0.17-winx64\\include")
#set(CONCPP_LIB_DIR "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mysql-connector-c++-8.0.17-winx64\\lib64")
#set(CONCPP_STATIC_LIB_DIR "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\mysql-connector-c++-8.0.17-winx64\\lib64")

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})


	add_executable(traffic_program DataParser.cpp TrafficDataObject.cpp)
	target_link_libraries(traffic_program ${Boost_LIBRARIES} ${MathGL2_LIBRARIES} ${GSL_LIBRARIES})
endif()

