cmake_minimum_required(VERSION 3.16)

project(6502 VERSION 0.1)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)




add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/cpu.cpp
  src/memory.cpp
  src/asmb.cpp
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build/bin"
)

add_subdirectory(vendor/fmt)
add_subdirectory(vendor/FTXUI)

target_include_directories(${PROJECT_NAME} 
  PUBLIC vendor/fmt/include
  PUBLIC vendor/FTXUI/include
)

target_link_directories(${PROJECT_NAME} 
  PRIVATE vendor/fmt/src
  PRIVATE vendor/FTXUI/src
)

target_link_libraries(${PROJECT_NAME}
  fmt
  ftxui::screen
  ftxui::dom 
  ftxui::component
)