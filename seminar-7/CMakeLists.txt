cmake_minimum_required(VERSION 3.5)

project(seminar-7)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# --- Create lib ---
add_library(seminar7_lib 
    src/podcast_episode.cpp
    src/playlist.cpp
    src/videoclip.cpp
)

target_include_directories(seminar7_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Main Application ---
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE seminar7_lib)