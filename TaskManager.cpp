#include"TaskManager.h"
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

void TaskManager::saveTasks(){
	ofstream outputFile("tasks.txt");
	for(int i=0;i<tasks.size();i++){
		if(tasks[i].isFinished()){
			outputFile<<"1 ";
		}
		else{
			outputFile<<"0 ";
		}
		outputFile<<tasks[i].getName()<<endl;
	}
	outputFile.close();
}
void TaskManager::loadTasks(){
	ifstream inputFile("tasks.txt");
	if(!inputFile){
		return;
	}
	bool finished;
	string name;
	while (inputFile >> finished) {
		getline(inputFile >> ws, name);
		Task t(name);
		if(finished){
			t.finish();
		}
		tasks.push_back(t);
	}
	inputFile.close();
}
bool TaskManager::isValidIndex(int number){
	return number >= 1 && number <= tasks.size();
}
TaskManager::TaskManager(){
	loadTasks();
}
void TaskManager::addTask(){
		string task;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入任务名称：";
		getline(cin, task);
		Task t(task);
		tasks.push_back(t);
		saveTasks();	
}
void TaskManager::showTasks(){
	if(tasks.empty()){
		cout<<"暂无任务"<<endl;
	}
	else{
		cout<<"当前共有"<<tasks.size()<<"个任务："<<endl;
		for (int i = 0; i < tasks.size(); i++) {
			cout << i + 1 << ". ";
			if (tasks[i].isFinished()) {
				cout << "[√] ";
			} else {
				cout << "[ ] ";
			}
			cout << tasks[i].getName() << endl;
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
void TaskManager::finishTask(){
	int number;
	cout<<"请输入任务编号:";
	if(!getInput(number)){
		cout<<"请输入数字！"<<endl;
		return;
	}
	if(!isValidIndex(number)){
		cout<<"编号错误！"<<endl;
		return;
	}
	tasks[number-1].finish();
	saveTasks();
	cout<<"操作成功！"<<endl;
}
void TaskManager::showStatistics()
{   if(tasks.empty())
	{
		cout << "暂无任务" << endl;
		return;
	}	
	int finishedCount = 0;	
	for(int i = 0; i < tasks.size(); i++)
	{
		if(tasks[i].isFinished())
		{
			finishedCount++;
		}
	}	
	int total = tasks.size();
	int unfinishedCount = total - finishedCount;	
	cout << "=====任务统计=====" << endl;
	cout << "总任务：" << total << endl;
	cout << "已完成：" << finishedCount << endl;
	cout << "未完成：" << unfinishedCount << endl;
}
bool TaskManager::getInput(int& choice){
	cin >> choice;
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	return true;
}

