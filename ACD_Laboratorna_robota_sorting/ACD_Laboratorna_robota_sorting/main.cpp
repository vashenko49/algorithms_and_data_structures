#include<iostream>
#include "ASD_sort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Размер массива > "; cin >> n;
	int A[] = { 1,8,6,5,10,9,7,2,3 };
	ASD_sort asd_sort;

	asd_sort.Print(A, n);
	cout << "" << endl;
	asd_sort.mersort3(A, n+1);
	asd_sort.Print(A, n);

	
	return 0;
}