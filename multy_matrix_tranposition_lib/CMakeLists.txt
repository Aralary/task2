cmake_minimum_required(VERSION 3.18.4)
project(th_m_transpose_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/sources/th_m_transpose.c)

target_include_directories(th_m_transpose_lib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
set(TH_M_TRANSPOSE_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(TH_M_TRANSPOSE_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)