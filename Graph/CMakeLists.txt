cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(graph CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
  ${CMAKE_SOURCE_DIR}/../UnionFindSet
)


aux_source_directory(
  ${CMAKE_SOURCE_DIR} DIR_SRC
  )

add_executable(graph
  ${DIR_SRC}
  ${CMAKE_SOURCE_DIR}/UnionFindSet/UnionFindSet.cpp

  )


target_link_libraries(
  graph
  )
