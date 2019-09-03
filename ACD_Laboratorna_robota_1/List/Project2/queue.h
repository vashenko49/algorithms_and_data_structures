#pragma once

template<typename T>
class queue
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
	queue();
	~queue();
	bool Is_empty(Node<T> *temp);
	bool push_back(T data); //добавление в конец очереди
	T pop_front();//Удаление елемента из начала очерди
	void clear();//очистка очереди
	void Print(); //Печать очереди
	int GetSize(); //Количечтво елементов в очереди



};
template<typename T>
queue<T>::queue()
{
}

template<typename T>
queue<T>::~queue()
{
	clear();
}

template<typename T>
bool queue<T>::Is_empty(Node<T>* temp)
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
bool queue<T>::push_back(T data)
{
	if (Is_empty(head))
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
T queue<T>::pop_front()
{
	if(Is_empty(head))
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
void queue<T>::clear()
{
	while (GetSize())
	{
		pop_front();
	}
}

template<typename T>
void queue<T>::Print()
{
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		cout << current->data << "\t";
		current = current->pNext;
	}
}

template<typename T>
int queue<T>::GetSize()
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

