SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/${CMAKE_BUILD_TYPE})

SET(TEST_SOURCE_FILES gtest_main.cc app/example_test_algorithm.cpp app/example_test_algorithm1.cpp)
SET(CUT_FILES ../src/app/example_algorithm1.c ../src/app/example_algorithm1.h)


INCLUDE_DIRECTORIES(include)

LINK_DIRECTORIES ( ${CMAKE_CURRENT_SOURCE_DIR}/lib )

MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR}/lib )

ADD_EXECUTABLE(run_all_the_tests ${TEST_SOURCE_FILES} ${CUT_FILES})

TARGET_LINK_LIBRARIES(run_all_the_tests libgmock.a pthread)