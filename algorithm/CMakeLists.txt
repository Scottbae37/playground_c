add_subdirectory(test)

add_library(InsertionSort src/InsertionSort.cpp)
target_include_directories(InsertionSort PUBLIC inc)

add_library(BubbleSort src/BubbleSort.cpp)
target_include_directories(BubbleSort PUBLIC inc)

add_executable(algo_main main.cpp)