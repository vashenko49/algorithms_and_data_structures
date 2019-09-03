#pragma once
#include<iostream>
#include <cstdlib>
#include <iterator>
#include <functional>
using namespace std;

#pragma region  ����� ��� �������� ������ �����

template<typename Tkey, typename Tdata> // ����� ��� �������� ������ �����
class Hash_Table_List_Array_Node
{
private:
	template<typename Tkey, typename Tdata> // ����� ��� �������� ���� ���� ����-��������
	class Node
	{
	public:
		Node * pNext;
		Node *pRev;
		Tkey key;
		Tdata data;
		Node(Tkey key = Tkey(), Tdata data = Tdata(), Node *pNext = nullptr, Node *pRev = nullptr)
		{
			this->key = key;
			this->data = data;
			this->pNext = pNext;
			this->pRev = pRev;

		}
	};
	Node< Tkey, Tdata > *head;
	Node< Tkey, Tdata> *tail;
	int size;


#pragma region ������ ������ ������
	void push_back(Tkey key, Tdata data); //���������� � ����� ������
	void push_front(Tkey key, Tdata data);
	void pop_back();
	void pop_front();
#pragma endregion 



public:


	Hash_Table_List_Array_Node();
	~Hash_Table_List_Array_Node();



#pragma region ������ ��� �������� ������ �����
	bool add(Tkey key, Tdata data); //���������� ������ ���� (���� ����-��������)
	bool updated(Tkey key, Tdata data); //���������� �������� �� �����
	bool GetValue(Tkey key); // �������� �� ������� �� �����
	bool Remove(Tkey key); //�������� ���� �� �����
	void clear();

#pragma endregion 

};

template<typename Tkey, typename Tdata>
Hash_Table_List_Array_Node<Tkey, Tdata>::Hash_Table_List_Array_Node()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename Tkey, typename Tdata>
Hash_Table_List_Array_Node<Tkey, Tdata>::~Hash_Table_List_Array_Node()
{
}


#pragma region ���������� ������� ������ ������
template<typename Tkey, typename Tdata>
void Hash_Table_List_Array_Node<Tkey, Tdata>::push_back(Tkey key, Tdata data)
{
	Node<Tkey,Tdata> *temp = new Node<Tkey,Tdata>;
	temp->pNext = nullptr;
	temp->data = data;
	temp->key = key;
	if (head != nullptr) //���� ������ �� ����
	{
		temp->pRev = tail;
		tail->pNext = temp;
		tail = temp;
	}
	else//���� ������
	{
		temp->pRev = nullptr;
		head = tail = temp;
	}
	size++;
}

template<typename Tkey, typename Tdata>
void Hash_Table_List_Array_Node<Tkey, Tdata>::push_front(Tkey key, Tdata data)
{
	Node<Tkey, Tdata> *temp = new Node<Tkey, Tdata>;
	temp->pRev = nullptr;
	temp->data = data;
	temp->key = key;
	temp->pNext = head;
	if (head == nullptr)
	{
		head->pRev = temp;
	}
	else if (size == 0)
	{
		head = tail = temp;
	}
	else
	{
		head = temp;
	}
	size++;
}

template<typename Tkey, typename Tdata>
inline void Hash_Table_List_Array_Node<Tkey, Tdata>::pop_back()
{
	Node<Tkey, Tdata> *temp = tail;
	tail = tail->pRev;
	tail->pNext = nullptr;
	size--;

}

template<typename Tkey, typename Tdata>
inline void Hash_Table_List_Array_Node<Tkey, Tdata>::pop_front()
{
	Node<Tkey, Tdata> *temp = head;
	if (head == tail)//���� ���� �������
	{		
		head->pNext = nullptr;
		head = nullptr;
		size--;

	}
	else
	{
		head = head->pNext;
		head->pRev = nullptr;
		size--;

	}
}
#pragma endregion 

#pragma region ���������� ������� ��� �������� ������ �����

template<typename Tkey, typename Tdata>
bool Hash_Table_List_Array_Node<Tkey, Tdata>::add(Tkey key, Tdata data)
{
	bool answer = true;
	Node<Tkey, Tdata> *current = head;
	while (current != nullptr)
	{
		if(current->key == key)
		{
			cout << "������� ������ ����� �������� � ������ �� ������ �������" <<endl;
			
		}
		current = current->pNext;
	}
	push_back(key, data);
	return answer;
}

template<typename Tkey, typename Tdata>
inline bool Hash_Table_List_Array_Node<Tkey, Tdata>::updated(Tkey key, Tdata data)
{
	bool answer = false;
	Node<Tkey, Tdata> *current;
	current = head;
	while (current != nullptr)
	{
		if(current->key==key)
		{
			answer = true;
			current->data = data;
			break;;
		}
		current = current->pNext;

	}

	return answer;
}

template<typename Tkey, typename Tdata>
inline bool Hash_Table_List_Array_Node<Tkey, Tdata>::GetValue(Tkey key)
{
	bool answer = false;
	Node<Tkey, Tdata> *current;
	current = head;
	while (current != nullptr)
	{
		if (current->key == key)
		{
			answer = true;
			break;;
		}
		current = current->pNext;

	}
	return answer;
}

template<typename Tkey, typename Tdata>
inline bool Hash_Table_List_Array_Node<Tkey, Tdata>::Remove(Tkey key)
{
	bool answer = false;
	Node<Tkey, Tdata> *temp = head, *temp2;
	while (temp != nullptr)
	{
		if (temp->key == key)
		{
			if (key == 0)
			{
				pop_front();
			}
			else if(head == tail)
			{
				head->pNext = nullptr;	//�������� ��� ��� �����
				head->key = 0;
				head = nullptr;
				
				size--;

				
			}
			else if (temp->pNext == nullptr)
			{
				pop_back();
			}
			else
			{
				temp2 = temp;
				temp2->pRev->pNext = temp->pNext;
				temp2->pNext->pRev = temp->pRev;
				size--;
			}
			answer = true;
			break;
		}
		temp = temp->pNext;

	}
	return answer;
}

template<typename Tkey, typename Tdata>
inline void Hash_Table_List_Array_Node<Tkey, Tdata>::clear()
{
	while (head)
	{
		tail = head->pNext;
		delete head;
		head = tail;
	}
}
#pragma endregion 

#pragma endregion 

#pragma region �������� ������� ����������� HashTableArray �������� � �������� ����� (����-���� �������� )
template<typename Tkey, typename Tdata>
class HashTableArray
{
private:
	//const double _fil = 0.75;// ���� ���������� ������� ��������� 75% - ������ �������������.     

	//int _maxSize;	// ������������ ���������� ���������  

	int _count;	// ���������� ��������� � ��� ������� 

	Hash_Table_List_Array_Node<Tkey, Tdata> array_node_[150]; //������ ������ 150 �� ��� ������� ������������
	public:

	HashTableArray();
	~HashTableArray();
	int GetIndex(Tkey key);
	int Capacity();
	void add(Tkey kkey, Tdata ddata);
	void remove(Tkey tkey);
};

#pragma region ���������� ������� �������� ������� ����������� HashTableArray �������� � �������� ����� (����-���� �������� )
template<typename Tkey, typename Tdata>
inline HashTableArray<Tkey, Tdata>::HashTableArray()
{
}

template<typename Tkey, typename Tdata>
inline void HashTableArray<Tkey, Tdata>::add(Tkey kkey, Tdata ddata)
{
	int index = GetIndex(kkey);
	array_node_[index].add(kkey, ddata);
	_count++;
}

template<typename Tkey, typename Tdata>
inline void HashTableArray<Tkey, Tdata>::remove(Tkey tkey)
{
	_count--;
	int index = GetIndex(tkey);
	array_node_[index].Remove(tkey);

}



template<typename Tkey, typename Tdata>
inline HashTableArray<Tkey, Tdata>::~HashTableArray()
{
}

template<typename Tkey, typename Tdata>
inline int HashTableArray<Tkey, Tdata>::GetIndex(Tkey key)
{
int N = 150; double A = 0.618033;
int h = N * fmod(key*A, 1);
return h;
}

template<typename Tkey, typename Tdata>
inline int HashTableArray<Tkey, Tdata>::Capacity()
{
	return 150;
}
#pragma endregion 

#pragma endregion 
