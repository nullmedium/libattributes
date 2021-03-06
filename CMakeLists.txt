cmake_minimum_required (VERSION 2.6)
project (libsettable)


if (NOT ${tests})
	set(enable_tests "off")
else()
	set(enable_tests "on")
endif()

if (${enable_tests} STREQUAL "on")
	find_package(Boost 1.42 COMPONENTS system unit_test_framework)
else()
	find_package(Boost)
endif()

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS})

add_subdirectory(examples)

find_program(doxygen_path doxygen)

if (EXISTS ${doxygen_path})
	add_custom_target(doc ${doxygen_path} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif()

if (${enable_tests} STREQUAL "on")
	enable_testing()
	add_subdirectory(unittest)
endif()
