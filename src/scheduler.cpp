#include "scheduler.hpp"
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
void Scheduler::addTask(std::string task_name, const int& prio) {
  //std::string instead of const std::string& to support move semantics
  
  for(auto& ch : task_name){
    ch = std::tolower(static_cast<unsigned char>(ch));
  }

  const std::string& task_name_copy = task_name;     //string_view forsomereason doesn't read the 1st character
  task_list.emplace_back(std::move(task_name), prio); //emplace_back directly pushes into vector 
  std::cout << "Task added.\n";

}

void Scheduler::displayTask() const{
  for (const auto& task : task_list) {
    std::cout << "Name: " << task.task_name << " | " << "Prio: " <<  task.priority << '\n';
  }
}

void Scheduler::displayTaskFile() const{

  std::ifstream file_text("task_file.txt");
  std::string lines;

  if(!file_text.is_open()){
    std::cout << "Failed to open file."<< '\n';
  }

  else{
    //check to see if file is empty using fs::filesize("filename", errorcode);
    if(file_text.peek() == std::ifstream::traits_type::eof()){
      std::cout << "File is empty!" << '\n';
    }
    else{
      //open the file and read from it.
      while(std::getline(file_text, lines)){
        std::cout << lines << '\n';
      }
    }
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

void Scheduler::saveTasksFile(){
  std::ofstream file_write("task_file.txt", std::ios::app);
  if(!file_write.is_open()){
    std::cout << "File writing failed." << '\n';
  }
  else{

    for(auto& task : task_list){
      file_write << task.task_name << " | " << task.priority << '\n';
    }

    std::cout << "Tasks Saved successfully." << '\n'; 
  }
}

void Scheduler::resetFile(){ 
  //remove all contents inside the file.
  //overwrite?
  std::ofstream reset_file("task_file.txt");
  std::cout << "File contents deleted." << '\n';
}

