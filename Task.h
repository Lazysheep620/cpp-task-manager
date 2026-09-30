#ifndef TASK_H
#define TASK_H
#include<string>
using std::string;

class Task {
private:
	string name;
	bool finished;
public:
	Task(string n);
	void finish();
	bool isFinished() const;
	string getName() const;
};

#endif
