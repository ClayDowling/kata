cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(life LANGUAGES C)

include(FetchContent)
include(CTest)

FetchContent_Declare(
	unity
	GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
	GIT_TAG v2.5.2
)

set(UNITY_EXTENSION_FIXTURE on)
FetchContent_MakeAvailable(unity)

add_subdirectory(test)

set(APP_SOURCE
	unit.c unit.h)


add_executable(${PROJECT_NAME}
	main.c
	${APP_SOURCE}
	)
