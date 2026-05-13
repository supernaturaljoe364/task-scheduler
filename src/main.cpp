#include "scheduler.hpp"
#include <functional>
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
int main() {

  while(true){
    std::string input;
    std::getline(std::cin, input);

    Scheduler scheduler;

    std::istringstream iss(input);

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

    if(commands.find(input) != commands.end()){
      //command found!
      
    }
    else std::cout << "Invalid Command.\n";
    
  
/*
    if (command == "add") {
    if (second_command == "task") {
      std::string task;
      std::cout << "Enter a task: ";
      std::getline(std::cin, task);

      uint32_t priority;
      std::cout << "Enter priority of task: ";
      std::cin >> priority;

      //to remove the '\n' in input buffer if the user decides to do an operation using std::getline
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      scheduler.addTask(task, priority);
    }
  }
    if(command == "exit") break;
    if(command == "show"){
      if(second_command == "tasks"){
          scheduler.displayTask();
      }
    }


    if(command == "remove"){
      if(second_command == "task"){
        std::string task_name;

        std::cout << "Enter task: ";
        std::getline(std::cin, task_name);
       
       scheduler.removeTask(task_name); 
      }
    }

    if(command == "sort"){
      if(second_command == "tasks"){
        
        char ch;
        std::cout << "Sort By (N)ame or (P)riority? : ";
        std::cin >> ch;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          
        if(ch == 'N') scheduler.sortTasksName();
        else if (ch == 'P') scheduler.sortTasksPrio();
        else continue;

      }
    }

    if(command == "save"){
      if(second_command == "tasks"){
        scheduler.saveTasksFile();

      }
    }

    if(command == "clear"){
      scheduler.clearFile();
    }
    
    if(command == "load"){
      if(second_command == "tasks"){
        scheduler.loadTaskFile();
      }
    }
  */
  }
      return 0;
}

