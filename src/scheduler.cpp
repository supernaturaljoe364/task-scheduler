#include "scheduler.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>

void Scheduler::addTask(std::string task_name, const int& prio) {
  //std::string instead of const std::string& to support move semantics

  std::string task_name_revised;    //automatically initialized

  for(auto ch : task_name){
   task_name_revised += std::tolower(static_cast<unsigned char>(ch));  //casting to unsigned char (KEEP IN MIND)
  }

  Task task_obj(task_name_revised, prio);
  task_list.emplace_back(task_obj); //emplace_back directly pushes into vector 
                                    //without creating copy like push_back

  std::cout << "Task added.\n";
}

void Scheduler::displayTask() {
  for (const auto& task : task_list) {
    std::cout << "Name: " << task.task_name << " " << "Prio: " <<  task.priority << '\n';
  }
}

void Scheduler::removeTask(const std::string &task_name) {

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




