#include "scheduler.hpp"
#include <limits>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
int main() {
  Scheduler scheduler;


  while(true){
    std::string input;
    std::getline(std::cin, input);

    std::string command;
    std::string second_command;

    std::istringstream iss(input);
    iss >> command >> second_command;


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
  }
      return 0;
}

