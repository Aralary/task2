cmake_minimum_required(VERSION 3.18.4)
project(m_transpose_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/m_transpose.c)

target_include_directories(m_transpose_lib
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers
        )
set(M_TRANSPOSE_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(M_TRANSPOSE_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)