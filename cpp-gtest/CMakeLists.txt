cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(life)

include(FetchContent)
include(CTest)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(test)

set(APP_SOURCE
	unit.cpp unit.h)


add_executable(${PROJECT_NAME}
	main.cpp
	${APP_SOURCE}
	)
