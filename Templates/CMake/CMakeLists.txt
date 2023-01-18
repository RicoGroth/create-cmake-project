cmake_minimum_required(VERSION 3.10)
project(<PROJECT_NAME>)
add_executable(${CMAKE_PROJECT_NAME} 
    src/main.cpp
)
set(VCPKG_PATH <VCPKG_PATH>/scripts/buildsystems/vcpkg.cmake)
include(${VCPKG_PATH})

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/configuration.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/configuration.hpp
)
