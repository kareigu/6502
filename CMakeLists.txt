cmake_minimum_required(VERSION 3.16)

project(6502 VERSION 0.1)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)




add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/cpu.cpp
  src/memory.cpp
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin"
)

add_subdirectory(vendor/fmt)

target_include_directories(${PROJECT_NAME} 
  PUBLIC vendor/fmt/include
)

target_link_directories(${PROJECT_NAME} 
  PRIVATE vendor/fmt/src
)

target_link_libraries(${PROJECT_NAME}
  fmt
)