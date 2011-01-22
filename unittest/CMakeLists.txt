cmake_minimum_required (VERSION 2.6)

link_directories(${Boost_LIBRARY_DIRS})

add_executable(unittest unittest.cpp)

target_link_libraries(unittest ${Boost_LIBRARIES})

add_test(unittest unittest)
