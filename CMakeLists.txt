cmake_minimum_required(VERSION 3.10)

project(task-scheduler)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
    scheduler

    src/main.cpp
    src/scheduler.cpp
)

target_include_directories(scheduler PRIVATE include)
