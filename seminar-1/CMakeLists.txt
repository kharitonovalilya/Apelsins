cmake_minimum_required(VERSION 3.5)

project(seminar-1)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)

# Вариант 1: Используем FetchContent (удалите локальные catch2 файлы)
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- Создание библиотеки ---
add_library(sub_lib 
    src/sub.cpp
)

target_include_directories(sub_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Основное приложение ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sub_lib)

# --- Тестирование ---
enable_testing()

add_executable(unit_tests tests/test_sub.cpp)
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ПРАВИЛЬНАЯ СТРОКА: линкуем с sub_lib и Catch2
target_link_libraries(unit_tests PRIVATE sub_lib Catch2::Catch2WithMain)

# Регистрируем тест
add_test(NAME sub-tests COMMAND unit_tests)