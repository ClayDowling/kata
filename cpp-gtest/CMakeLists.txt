cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(romannumeral)

add_subdirectory(googletest)
add_subdirectory(test)

set(APP_SOURCE
		RomanNumeral.cpp RomanNumeral.h)


add_executable(${PROJECT_NAME}
	main.cpp
	${APP_SOURCE}
	)
