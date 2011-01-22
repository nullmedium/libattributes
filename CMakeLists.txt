cmake_minimum_required (VERSION 2.6)
project (libsettable)

find_package(Boost 1.42 COMPONENTS system unit_test_framework)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS})

add_subdirectory(examples)

enable_testing()

add_subdirectory(unittest)
