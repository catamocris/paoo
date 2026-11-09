cmake_minimum_required(VERSION 3.10)

project(tema2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(inc)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

add_library(student STATIC 
    src/student.cpp
    src/course.cpp
)

target_link_libraries(${PROJECT_NAME} student)