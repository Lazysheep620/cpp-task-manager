#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include"Task.h"
#include<vector>
#include<string>

class TaskManager{
private:
	std::vector<Task> tasks;
	
	void saveTasks();
	void loadTasks();
public:
	TaskManager();
	
	void addTask();
	void showTasks();
	void deleteTask();
	void finishTask();
};
#endif

