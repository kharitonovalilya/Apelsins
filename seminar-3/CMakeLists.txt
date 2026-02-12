cmake_minimum_required(VERSION 3.5)

project(seminar-3)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)

# --- Fetch Catch2 Dependency ---
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- Create lib ---
add_library(seminar3_lib 
    src/logic.cpp
    src/input_and_print.cpp
)

target_include_directories(seminar3_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE seminar3_lib)

# --- Testing ---
enable_testing()

# Tests for step
add_executable(test_step tests/test_step.cpp)
target_include_directories(test_step PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_step PRIVATE seminar3_lib Catch2::Catch2WithMain)
add_test(NAME step-tests COMMAND test_step)

# Tests for count_infected
add_executable(test_count_infected tests/test_count_infected.cpp)
target_include_directories(test_count_infected PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_count_infected PRIVATE seminar3_lib Catch2::Catch2WithMain)
add_test(NAME count_infected-tests COMMAND test_count_infected)

# Tests for neighbour_vir
add_executable(test_neighbour_vir tests/test_neighbour_vir.cpp)
target_include_directories(test_neighbour_vir PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_neighbour_vir PRIVATE seminar3_lib Catch2::Catch2WithMain)
add_test(NAME neighbour_vir-tests COMMAND test_neighbour_vir)