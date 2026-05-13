#include "scheduler.hpp"
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>



void Scheduler::addTask(std::string task_name, const int& prio) {
  //std::string instead of const std::string& to support move semantics
  
  for(auto& ch : task_name){
    ch = std::tolower(static_cast<unsigned char>(ch));
  }

  task_list.emplace_back(std::move(task_name), prio); //emplace_back directly pushes into vector 
  std::cout << "Task added.\n";

  Scheduler::displayTask();


}

void Scheduler::displayTask() const{
  for (const auto& task : task_list) {
    std::cout << "Name: " << task.task_name << " | " << "Prio: " <<  task.priority << '\n';
  }
}

void Scheduler::loadTaskFile(){

  std::ifstream file_text("task_file.txt");

  std::string line;

  if(!file_text.is_open()){
    std::cout << "Failed to open file."<< '\n';
  }

  else{
    if(file_text.peek() == std::ifstream::traits_type::eof()){
      std::cout << "File is empty!" << '\n';
    }
    else{
      //read each line inside file, then 
      while(std::getline(file_text, line)){
        std::istringstream iss(line);
        std::string task_name;
        std::string priority_text;
        int priority = 0;

        std::getline(iss, task_name, '|');
        std::getline(iss, priority_text);

        priority = priority*10 + (std::stoi(priority_text));

        task_list.emplace_back(std::move(task_name), priority);

        std::cout << "Tasks loaded from file." << '\n';
      }
    }
  }
}

        
/*manual parsing code my dumbass made (i didn't know the above thing was possible)
        bool occ = false;
        for(auto ch : line){
          if(ch == '|'){
            //delim has occurred,
            occ = true;
            //remove whitespace by locating lastnonws and removing the trailingws
            auto lastNonSpace = task_name.find_last_not_of(" ");    
            task_name = task_name.erase(lastNonSpace + 1);
            continue;
            
          }
          if(!occ){
            ch = std::tolower(static_cast<unsigned char>(ch));
            task_name+=ch;
          }
          if(occ){
            //read each number, parse to int, add to it.
            priority = priority*10 + (static_cast<int>(static_cast<unsigned char>(ch) - '0'));
          }
        }

        //by the time the line is completed, we append it to task_list

        task_list.emplace_back(std::move(task_name), priority);
      }



    }
  }
}
*/


void Scheduler::removeTask(std::string task_name) {


  for(auto& ch: task_name){
    ch = std::tolower(static_cast<unsigned char> (ch));
  }

  auto it = std::find_if(task_list.begin(), task_list.end(),
      [&](const Task& task){
        return task.task_name == task_name;
      });

  if(it != task_list.end()){
     task_list.erase(it);
     std::cout << "Task deleted." << '\n';
  }  
  else std::cout << "Task Not Found!" << '\n';
}

void Scheduler::sortTasksName(){

  std::sort(task_list.begin(), task_list.end(), 
      [](const Task& a, const Task& b){
          //sort by name
          return a.task_name < b.task_name;
      });
}

void Scheduler::sortTasksPrio(){
  std::sort(task_list.begin(), task_list.end(), 
      [](const Task& a, const Task& b){
          return a.priority < b.priority;

      });
}

void Scheduler::saveTasksFile(){

  //not appending to file, we overwrite it with the contents inside vector
  std::ofstream file_write("task_file.txt");
  if(!file_write.is_open()){
    std::cout << "File writing failed." << '\n';
  }
  else{

    for(auto& task : task_list){
      file_write << task.task_name << "|" << task.priority << '\n';
    }

    std::cout << "Tasks Saved successfully." << '\n'; 
  }
}

void Scheduler::clearFile(){ 
  //remove all contents inside the file.
  //overwrite?
  std::ofstream clear_file("task_file.txt");
  std::cout << "File contents deleted." << '\n';
}


