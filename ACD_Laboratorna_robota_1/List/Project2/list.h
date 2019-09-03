#pragma once
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
public:
	list();
	~list();
	//Методы работы списка
	bool push_back(T data); //добавление в конец списка
	int GetSize(); //Количечтво елементов в списке
	T& operator[](const int index); //Просмотр елемента под индексом
	T pop_front();//Удаление елемента из начала списка
	void clear();//очистка списка
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
}
template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
bool list<T>::push_back(T data)
{
	if (is_empty(head))
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	return true;
}

template<typename T>
int list<T>::GetSize()
{
	int temp = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		temp++;
		current = current->pNext;
	}
	return temp;
}

template<typename T>
T & list<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
T list<T>::pop_front()
{
	if (Is_empty(head))
	{
		return 0;
	}
	else {

		Node<T> *temp = head;
		head = head->pNext;
		return temp->data;
		delete temp;
	}
}

template<typename T>
void list<T>::clear()
{
	while (GetSize())
	{
		pop_front();
	}
}

template<typename T>
bool list<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	return true;
}

template<typename T>
T list<T>::pop_back()
{
	return (removeAt(GetSize() - 1));
}

template<typename T>
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
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
	}
	return; true;
}

template<typename T>
T list<T>::removeAt(int index)
{
	if (index == 0)
	{
		return pop_front();
	}
	else
	{
		Node <T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *toNode = previous->pNext;
		previous->pNext = toNode->pNext;
		return toNode->data;
		delete toNode;
	}
}

template<typename T>
void list<T>::Print()
{
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		cout << current->data << "\t";
		current = current->pNext;

	}
}

template<typename T>
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
