#include"Task.h"
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

Task::Task(string n):name(n),finished(false){}
void Task::finish(){
	finished=true;
}
bool Task::isFinished() const {
	return finished;
}
string Task::getName() const{
	return name;
}
