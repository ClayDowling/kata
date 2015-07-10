cmake_minimum_required(VERSION 2.8)
project (legancyrescue)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_definitions("-std=c++11")

set (LIBRARY_SOURCE
	legacyrescue.cpp
	)

add_library(legacy STATIC ${LIBRARY_SOURCE})

#add_subdirectory (gtest)
#add_subdirectory (test)

set (legacyrescue_SOURCE
	legacyrescue.cpp
	${LIBRARY_SOURCE}
	)

add_executable(legacyrescue ${legacyrescue_SOURCE})

