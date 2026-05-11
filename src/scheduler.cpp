#include "scheduler.hpp"
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

void Scheduler::addTask(std::string task_name, const int& prio) {
  //std::string instead of const std::string& to support move semantics


  for(auto& ch : task_name){
    ch = std::tolower(static_cast<unsigned char>(ch));
  }


  task_list.emplace_back(std::move(task_name), prio); //emplace_back directly pushes into vector 

  std::cout << "Task added.\n";
}

void Scheduler::displayTask() const{
  for (const auto& task : task_list) {
    std::cout << "Name: " << task.task_name << " " << "Prio: " <<  task.priority << '\n';
  }
}

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




