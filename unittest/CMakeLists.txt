cmake_minimum_required (VERSION 2.6)

link_directories(${Boost_LIBRARY_DIRS})

add_executable(AttributesTest AttributesTest.cpp)
target_link_libraries(AttributesTest ${Boost_LIBRARIES})
add_test(AttributesTest AttributesTest)

add_executable(String2typeTest String2typeTest.cpp)
target_link_libraries(String2typeTest ${Boost_LIBRARIES})
add_test(String2typeTest String2typeTest)
