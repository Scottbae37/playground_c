SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/${CMAKE_BUILD_TYPE} )
SET (SOURCE_FILES app/example_tcMain.c app/example_tcMain.h app/example_algorithm1.c app/example_algorithm1.h)

LINK_DIRECTORIES ( ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(tc_executable ${SOURCE_FILES})