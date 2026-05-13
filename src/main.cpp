#include "scheduler.hpp"
#include <functional>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
int main() {

    Scheduler scheduler;

    std::string task_name;
    int priority;
    char option;
    
    std::unordered_map<std::string, std::function<void()>> commands = {


      { 
        "add task" , [&](){
          std::cout << "Enter a task: ";
          std::getline(std::cin, task_name);

          std::cout << "Enter priority of task: ";
          std::cin >> priority;

          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          scheduler.addTask(task_name, priority);
        }
      },

      {
        "show tasks" , [&](){
          scheduler.displayTask();
        }
      },

      {
        "sort tasks" , [&](){

          std::cout << "Sort by (N)ame or (P)riority? :";
          std::cin >> option;

          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          if(option == 'N') return scheduler.sortTasksName();
          else if(option == 'P') return scheduler.sortTasksPrio();
        }
      },

      {
        "load tasks" , [&](){
          scheduler.loadTaskFile();
        }
      },

      {
        "save tasks" , [&](){
          scheduler.saveTasksFile();
        }
      },

      {
        "remove task", [&](){
          std::cout << "Enter the task: ";
          std::getline(std::cin, task_name);

          scheduler.removeTask(task_name);
        }
      },

      {
        "clear", [&](){
          scheduler.clearFile();
        }
      },

      {
        "exit", [&](){
         //i really don't know how to dea with this.
        }
      }
    };
  while(true){

    std::string input;
    std::getline(std::cin, input);


    if(commands.find(input) != commands.end()){
      //command found!
      commands[input]();      //because commands[input] is callable, and we use std::function<void()>, this works
    }
    else std::cout << "Invalid Command.\n";
  }
      return 0;
}

