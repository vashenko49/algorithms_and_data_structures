#include<iostream>
#include <cstdlib>
#include <cstdio>
#include"Hash_Table.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Hash_Table<int, string> hash_table;
	hash_table.add(1, "kek");
	hash_table.add(2, "lol");
	hash_table.add(3, "chebyrek");
	hash_table.add(4, "pou");
	hash_table.add(5, "gogo");
	hash_table.add(6, "spsp");
	hash_table.add(7, "asfd");

	hash_table.add(3, "chebyrekyyy");
	hash_table.add(3, "chebyrekooo");
	hash_table.add(3, "chebyrekaaa");
	hash_table.add(3, "chebyrekeee");

	string temp = hash_table.remove(1);

	hash_table.add(3, "reboot_chebyrekeee");

	string temp2 = hash_table.get_data(4);
	system("pause");
	return 0;
}