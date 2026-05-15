#include "scheduler.hpp"
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
int main() {

    
    std::string input;
    Scheduler scheduler;

    std::string task_name;
    std::string priority;
    char option;
    
    std::unordered_map<std::string, std::function<void(std::istringstream&)>> commands = {


      { 
        "add task" , [&](std::istringstream& iss){
          
          iss >> task_name >> priority;

          scheduler.addTask(task_name, std::stoi(priority));
        }
      },

      {
        "show tasks" , [&](std::istringstream& iss){
          scheduler.displayTask();
        }
      },

      {
        "sort tasks" , [&](std::istringstream& iss){

          char option;
          iss >> option;

          if(option == 'N') return scheduler.sortTasksName();
          else if(option == 'P') return scheduler.sortTasksPrio();
        }
      },

      {
        "load tasks" , [&](std::istringstream& iss){
          scheduler.loadTaskFile();
        }
      },

      {
        "save tasks" , [&](std::istringstream& iss){
          scheduler.saveTasksFile();
        }
      },

      {
        "remove task", [&](std::istringstream& iss){

          iss >> task_name;
          scheduler.removeTask(task_name);
        }
      },

      {
        "clear", [&](std::istringstream& iss){
          scheduler.clearFile();
        }
      },

      {
        "exit", [&](std::istringstream& iss){
         std::exit(0); 
        }
      }
    };
  while(true){

    std::string input;

    std::string command;
    std::string second_command;
    std::string full_command;

    std::getline(std::cin, input);
    std::istringstream iss(input);
    iss >> command >> second_command;

    if(second_command == ""){
      full_command = command;
    }
    else full_command = command + " " + second_command;
  
    if(commands.find(full_command) != commands.end()){
      //command found!
      commands[full_command](iss);
    }
    else std::cout << "Invalid Command.\n";
  }
}

