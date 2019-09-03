
#include<iostream>



using namespace std;
template<typename T>
class list
{
private:
	template<typename T>
	class Node
	{
	public:
		Node * pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	list();
	~list();
	//Методы работы списка
	bool push_back(T data); //добавление в конец списка
	int GetSize(); //Количечтво елементов в списке
	T pop_front();//Удаление елемента из начала списка
	bool push_front(T data);//Добавление елемента в начало списка
	T pop_back();//Удаление елемента из конца списка
	bool insert(T value, int index);//Добавление списка в любой участок списка
	T removeAt(int index); // Удаление елемента из любого участка списка
	void Print();
	bool is_empty(Node<T> *temp);
};

template<typename T>
list<T>::list()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}
template<typename T>
list<T>::~list()
{
}

template<typename T>//OK
bool list<T>::push_back(T data)
{
	if (is_empty(head))
	{
		head = new Node<T>(data);
		head->pNext = head;
		tail = head;
	}
	else
	{
		Node<T> *current = this->head;
		while (current != tail)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
		current->pNext->pNext = head;
		tail = current->pNext;
	}
	size++;
	return true;
}

template<typename T>//OK
bool list<T>::push_front(T data)
{
	if (is_empty(head))
	{
		head = new Node<T>(data);
		head->pNext = head;
		tail = head;
	}
	else
	{
		Node<T> *current = this->head;
		while (current != tail)
		{
			current = current->pNext;
		}
		head = new Node<T>(data, head);
		tail->pNext = head;
	}
	size++;
	return true;
}

template<typename T>//OK
bool list<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node <T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		if(previous == tail)
		{
			push_back(data);
			return true;
		}
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
	}
	size++;
	return true;
}

template<typename T>//OK
int list<T>::GetSize()
{
	return size;
}

template<typename T>//OK
T list<T>::pop_front()
{
	if (is_empty(head))
	{
		return 0;
	}
	else if(size==1)
	{
		T temp = head->data;
		head = nullptr;
		tail = nullptr;
		return temp;
	}
	else {
		T temp = 0;
		temp = head->data;
		head = head->pNext;
		tail->pNext = head;
		return temp;
	}
	size--;
}




template<typename T>//OK
T list<T>::pop_back()
{
	if (size == 0)
	{
		return 0;
	}
	return removeAt(size - 1);
}



template<typename T>//OK
T list<T>::removeAt(int index)
{
	T temp;
	if(index>size-1)
	{
		cout << "вы вышли за перделы списка" << endl;
	}
	else if (index == 0)
	{
		temp= pop_front();
		size++;
	}
	else
	{
		Node <T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		temp = previous->data;
		previous->pNext = previous->pNext->pNext;
	}
	size--;
	return temp;
}

template<typename T>//OK
void list<T>::Print()
{
	Node<T> *current = head;
	if(head == tail || head == nullptr )
	{
		cout << "Empty" << endl;
		return;
	}
	do
	{
		cout << current->data << "\t";
		current = current->pNext;

		
	}
	while (current != head);
}

template<typename T> //OK
bool list<T>::is_empty(Node<T> *temp)
{
	if (temp == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
