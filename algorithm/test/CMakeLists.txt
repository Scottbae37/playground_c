FIND_PACKAGE(GTest REQUIRED)

INCLUDE(GoogleTest)

add_executable(run_all_tests
        CppStl_Test.cpp
        Sorting_Test.cpp
        MergeSort_Test.cpp
        Graph_Test.cpp)

target_link_libraries(run_all_tests
        PUBLIC GTest::GTest
        PUBLIC GTest::Main
        PUBLIC InsertionSort
        PUBLIC BubbleSort)