#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include<vector>
#include<string>

class TaskManager{
private:
	std::vector<std::string> tasks;
	
	void saveTasks();
	void loadTasks();
public:
	TaskManager();
	
	void addTask();
	void showTasks();
	void deleteTask();
};
#endif

