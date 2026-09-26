#include<iostream>
#include "TaskManager.h"
using namespace std;

int main(){
	TaskManager manager;
	int choice;
	while(true){
		cout<<"===== Task Manager =====" <<endl;
		cout << "1. 添加任务" << endl;
		cout << "2. 查看任务" << endl;
		cout << "3. 删除任务" << endl;
		cout << "4. 退出" << endl;
		cin>>choice;
		if(choice==4){break;}
		else if(choice==1){
			manager.addTask();
		}
		else if(choice==2){
			manager.showTasks();
		}
		else if(choice==3){
			manager.deleteTask();
		}
	}
	return 0;
}
