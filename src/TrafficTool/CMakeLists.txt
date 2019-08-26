project (Traffic_Program)
set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required

cmake_minimum_required (VERSION 3.14.5)




set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\boost_1_70_0")
set(BOOST_INCLUDEDIR "C:\\Users\\johnm\\Desktop\\TrafficTool\\libs\\boost_1_70_0\\boost")

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_BUILD_TYPE DEBUG)


find_package(Boost 1.70.0)


include_directories("${Boost_INCLUDE_DIRS}")
message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")




if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable(traffic_program DataParser.cpp TrafficDataObject.cpp)
	target_link_libraries(traffic_program ${Boost_LIBRARIES})
endif()
#add_executable(traffic_program DataParser.cpp TrafficDataObject.cpp)

