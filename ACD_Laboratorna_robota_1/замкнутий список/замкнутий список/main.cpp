#include<iostream>
#include<string>
#include <cstdlib>
#include "list.h"

using namespace std;






int main()
{
	list<int> listl_list;
	listl_list.push_back(5);
	listl_list.push_back(7);
	listl_list.push_back(8);
	listl_list.push_back(78);

	listl_list.Print();



	return 0;
}