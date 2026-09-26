#include"TaskManager.h"
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

void TaskManager::saveTasks(){
	ofstream outputFile("tasks.txt");
	for(int i=0;i<tasks.size();i++){
		outputFile<<tasks[i]<<endl;
	}
	outputFile.close();
}
void TaskManager::loadTasks(){
	ifstream inputFile("tasks.txt");
	if(!inputFile){
		return;
	}
	string savedTask;
	while(getline(inputFile,savedTask)){
		tasks.push_back(savedTask);
	}
	inputFile.close();
}
TaskManager::TaskManager(){
	loadTasks();
}
void TaskManager::addTask(){
	string task;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"请输入一个任务：";
	getline(cin,task);
	tasks.push_back(task);
	saveTasks();
}
void TaskManager::showTasks(){
	if(tasks.empty()){
		cout<<"暂无任务"<<endl;
	}
	else{
		cout<<"当前共有"<<tasks.size()<<"个任务："<<endl;
		for(int i=0;i<tasks.size();i++){
			cout<<i+1<<". "<<tasks[i]<<endl;
		}
	}
}
void TaskManager::deleteTask(){
	int number;
	cout << "请输入要删除的任务编号：";
	cin>>number;
	if (number >= 1 && number <= tasks.size()) {
		tasks.erase(tasks.begin() + number - 1);
		saveTasks();
		cout << "删除成功！" << endl;
		cout<<"当前剩余"<<tasks.size()<<"个任务"<<endl;
	}
	else {
		cout << "任务编号不存在！" << endl;
	}
}

