cmake_minimum_required(VERSION 3.18.4)
project(task2 C)

set(CMAKE_C_STANDARD 11)



add_subdirectory(matrix_tranposition_lib)
add_subdirectory(multy_matrix_tranposition_lib)

message("M_TRANSPOSE_LIB_LIBRARIES = ${M_TRANSPOSE_LIB_LIBRARIES}")
message("M_TRANSPOSE_LIB_INCLUDE_DIRS = ${M_TRANSPOSE_LIB_INCLUDE_DIRS}")
message("TH_M_TRANSPOSE_LIB_LIBRARIES = ${TH_M_TRANSPOSE_LIB_LIBRARIES}")
message("TH_M_TRANSPOSE_LIB_INCLUDE_DIRS = ${TH_M_TRANSPOSE_LIB_INCLUDE_DIRS}")

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Werror -Wpedantic")
add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
target_include_directories(${PROJECT_NAME} PUBLIC ${M_TRANSPOSE_LIB_INCLUDE_DIRS} ${TH_M_TRANSPOSE_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${M_TRANSPOSE_LIB_LIBRARIES} ${TH_M_TRANSPOSE_LIB_LIBRARIES})

add_subdirectory(test)
