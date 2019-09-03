#include<iostream>
#include <cstdlib>
#include <cstdio>
#include"HashTableArray.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	HashTableArray<int, string>  hash_table;
	hash_table.add(1, "kek");
	hash_table.add(2, "lol");
	hash_table.add(3, "chebyrek");
	hash_table.add(4, "pou");
	hash_table.add(5, "gogo");
	hash_table.add(6, "spsp");
	hash_table.add(7, "asfd");



	system("pause");
	return 0;
}