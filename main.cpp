#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class TaskManager{
private:
	vector<string> tasks;
	void saveTasks(){
		ofstream outputFile("tasks.txt");
		
		for(int i=0;i<tasks.size();i++){
			outputFile<<tasks[i]<<endl;
		}
		
		outputFile.close();
	}
	void loadTasks(){
		ifstream inputFile("tasks.txt");
		string savedTask;
		
		while(getline(inputFile,savedTask)){
			tasks.push_back(savedTask);
		}
		
		inputFile.close();
	}
public:
	TaskManager(){
		loadTasks();
	}
	void addTask(){
		string task;
		cin.ignore();
		cout<<"请输入一个任务：";
		getline(cin,task);
		tasks.push_back(task);
		saveTasks();
	}
	void showTasks(){
		if(tasks.empty()){cout<<"暂无任务"<<endl;}
		else{
			cout<<"当前共有"<<tasks.size()<<"个任务："<<endl;
			for(int i=0;i<tasks.size();i++){
				cout<<i+1<<". "<<tasks[i]<<endl;
			}
		}
	}
	void deleteTask(){
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
};
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
