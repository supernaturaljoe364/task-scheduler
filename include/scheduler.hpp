#pragma once
#include <string>
#include <vector>

class Task {
public:
  std::string task_name;
  int priority;
};

class Scheduler {

  std::vector<Task> task_list;
public:

  void addTask(const std::string &task_name, const int &prio);
  void displayTask();
  void removeTask(const std::string &task_name);
  void sortTasksName();
  void sortTasksPrio();
};
