#pragma once
#include <string>
#include <vector>
#include <utility>

class Task {
  friend class Scheduler; //encapsulation
  std::string task_name;
  int priority;

  public:
    Task(std::string string, const int& prio) : 
      task_name(std::move(string)), //const std::string& won't let you move!
      priority(prio) {};
};

class Scheduler {

  std::vector<Task> task_list;
public:

  void addTask(std::string string, const int& prio);   //yes i know, string& instead of string because i don't wanna create a copy
  void displayTask() const;
  void removeTask(std::string task_name);
  void sortTasksName();
  void sortTasksPrio();
  void displayTaskFile() const;
  void saveTasksFile();
  void resetFile();
};
