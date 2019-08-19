project (Traffic_Program)
cmake_minimum_required (VERSION 3.15)




set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT "/home/john/Desktop/External_Libs/boost_1_70_0")
set(BOOST_INCLUDEDIR "/home/john/Desktop/External_Libs/boost_1_70_0/boost")

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

