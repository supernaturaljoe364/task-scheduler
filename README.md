# Task Scheduler

Task Scheduler is a CLI-tool that allows users to add, remove, view, sort, save and load tasks. This software makes use of STL containers & algorithms, **designed for learning purposes and not for production-grade use.** 

This project was built with CMake and Git. 

## Features.
- Add tasks with priorities
- Remove tasks
- Display tasks
- Sort tasks alphabetically
- Sort tasks by priority
- Task storage using vector
- Task saving using files
- Load tasks from files
- STL usage (std::find_if, std::sort)
- Lambda functions for driver code and comparators
- CMake system

## Tech Stack
- Modern C++ \(C++17\)
- CMake

## Installation

If you wish to try out this software, follow these steps: 

- Clone repository 

`git clone https://github.com/supernaturaljoe364/task-scheduler.git` 

`cd task-scheduler`

- Build using CMake  

`cmake -B build`  

`cmake --build build`

- Run  

`./build/scheduler`

## Commands

`add task <task_name> <priority>` -> add task  

`remove task <task_name>` -> remove task with task_name  

`show tasks` -> show all tasks inside the task vector  

`sort tasks N` -> sort tasks by name  

`sort tasks P` -> sort tasks by priority 

`save tasks` -> save tasks to file  

`load tasks` -> load tasks from file. \(This results in overwriting of data inside the file\)

`exit` -> exit program 

## Concepts practice

This project focuses on learning and applying:

- Classes and object-oriented design
- Constructors and initializer lists
- Move semantics
- STL containers
- STL algorithms
- Lambdas and predicates
- Command dispatch using `std::function` 
- File I/O
- Parsing and serialization
- Iterators
- Encapsulation
- CMake-based project organization

## Motivation

The goal of this project is not only to build a CLI utility, but to use projects as a tool for developing deeper understanding of modern C++ and systems-oriented software development.
