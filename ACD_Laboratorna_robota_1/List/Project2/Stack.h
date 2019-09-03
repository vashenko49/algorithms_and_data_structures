#pragma once

template<typename T>
class Stack
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
	Stack();
	~Stack();
	//Методы работы стека
	bool is_empty(Node<T>* temp);
	bool push_front(T data);//Добавление елемента в начало списка
	T pop_front();//Удаление елемента из начала списка
	int GetSize(); //Количечтво елементов в стека
	void clear();//очистка стека
	void Print();



};

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
bool Stack<T>::is_empty(Node<T>* temp)
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

template<typename T>
bool Stack<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	return true;
}

template<typename T>
T Stack<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	return temp->data;
	delete temp;
}

template<typename T>
int Stack<T>::GetSize()
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
void Stack<T>::clear()
{
	while (GetSize())
	{
		pop_front();

	}
}


template<typename T>
void Stack<T>::Print()
{
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		cout << current->data << "\t";
		current = current->pNext;
	}
}
