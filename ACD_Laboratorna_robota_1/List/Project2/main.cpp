#include<iostream>
#include<string>
#include <cstdlib>
#include "list.h"
#include "Stack.h"
#include "queue.h"
using namespace std;






int main()
{
	setlocale(LC_ALL, "ru");
	queue<int> stack;
	for (int i = 0; i < 3; i++)
	{
		stack.push_back(i);
	}

	stack.Print();
	cout << "" << endl;
	cout << stack.pop_front() << endl;
	stack.Print();
	cout << "" << endl;
	cout << stack.pop_front() << endl;
	stack.Print();
	cout << "" << endl;
	cout << stack.pop_front() << endl;
	stack.Print();
	cout << "" << endl;
	cout << stack.pop_front() << endl;
	stack.Print();
	cout << "" << endl;





	system("pause");
	return 0;
}