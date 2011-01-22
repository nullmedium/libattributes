cmake_minimum_required (VERSION 2.6)
project (libsettable)

find_package(Boost)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIRS})

add_subdirectory(examples)
