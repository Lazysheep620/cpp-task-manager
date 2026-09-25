#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	vector<string> tasks;
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
			string task;
			cout<<"请输入一个任务：";
			cin.ignore();
			getline(cin,task);
			tasks.push_back(task);
			cout<<"当前共有"<<tasks.size()<<"个任务"<<endl;
		}
		else if(choice==2){
			for(int i=0;i<tasks.size();i++){
				cout<<i+1<<". "<<tasks[i]<<endl;
			}
		}
		else if(choice==3){
			int number;
			cout << "请输入要删除的任务编号：";
			cin>>number;
			if (number >= 1 && number <= tasks.size()) {
				tasks.erase(tasks.begin() + number - 1);
				cout << "删除成功！" << endl;
			}
			else {
				cout << "任务编号不存在！" << endl;
			}
		}
	}
	return 0;
}
