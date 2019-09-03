#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
private:
	template<typename T>
	class Node
	{
	public:
		Node * pNext;
		Node *pRev;
		T data;
		Node(T data = T(), Node *pNext = nullptr, Node *pRev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pRev = pRev;
		}
	};
	Node<T> *head;
	Node<T> *tail;
	int size;

public:
	List();
	~List();
	void print();
	bool is_empty(Node<int> *temp);
	void push_back(T data); //добавление в конец списка
	int get_size(); // оличечтво елементов в списке
	T& operator[](const int index); //ѕросмотр елемента под индексом
	T pop_front();//”даление елемента из начала списка
	T pop_back();//”даление елемента из конца списка
	void clear();//очистка списка
	void push_front(T data);//ƒобавление елемента в начало списка
	void insert(T value, int index);//ƒобавление списка в любой участок списка
	T remove_at(int index); // ”даление елемента из любого участка списка
};


template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = -1;
}
template<typename T>
List<T>::~List()
{
	clear();
}
template<typename T>
void List<T>::print() {

	Node<T> *current = this->head;
	while (current != nullptr)
	{
		cout << current->data << "\t";
		current = current->pNext;

	}

}

template<typename T>
bool List<T>::is_empty(Node<int>* temp)
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
void List<T>::push_back(T data)
{
	Node<T> *temp = new Node<T>;
	temp->pNext = nullptr;
	temp->data = data;
	if (head != nullptr) //если список не пуст
	{
		temp->pRev = tail;
		tail->pNext = temp;
		tail = temp;
	}
	else//если пустой
	{
		temp->pRev = nullptr;
		head = tail = temp;
	}
	size++;
}

template<typename T>
int List<T>::get_size()
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
T & List<T>::operator[](const int index)
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
T List<T>::pop_front()
{
	if(head == tail)//если один елемент
	{
		Node<T> *temp = head;
		head->pNext = nullptr;
		head = nullptr;
		size--;
		return temp->data;
	}
	else
	{
		Node<T> *temp = head;
		head = head->pNext;
		head->pRev = nullptr;
		size--;
		return temp->data;
	}
}

template<typename T>
T List<T>::pop_back()
{
	Node<T> *temp = tail;
	tail = tail->pRev;
	tail->pNext = nullptr;
	size--;
	return temp->data;
}

template<typename T>
void List<T>::clear()
{
	while (head)
	{
		tail = head->pNext;
		delete head;
		head = tail;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<int> *temp = new Node<int>;
	temp->pRev = nullptr;
	temp->data = data;
	temp->pNext = head;
	if(head == nullptr)
	{
		head->pRev = temp;
	}
	else if(size ==0)
	{
		head = tail = temp;
	}
	else
	{
		head = temp;
	}
	size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if(index == 0)
	{
		pop_front();
	}
	else if(index == size)
	{
		pop_back();
	}
	else
	{
		int i = 0;

		Node<T>* Ins = head;

		while (i < index)
		{

			Ins = Ins->pNext;
			i++;
		}

		Node<T> * PrevIns = Ins->pRev;
		Node<T> * temp = new Node<T>;
		temp->data= value;

		if (PrevIns != nullptr && size != 0)
			PrevIns->pNext = temp;

		temp->pNext = Ins;
		temp->pRev= PrevIns;
		Ins->pRev = temp;

		size++;

	}
}

template<typename T>
T List<T>::remove_at(int index)
{
	if(index ==0)
	{
		pop_front();
	}
	else if(index==size)
	{
		pop_back();
	}
	else
	{
		Node<T> *temp = head, *temp2;
		for (int i = 0; i < index; i++)
		{
			temp = temp->pNext;
		}
		temp2 = temp;
		temp2->pRev->pNext = temp->pNext;
		temp2->pNext->pRev = temp->pRev;
		size--;
		return temp->data;
	}
}




int main()
{

	List<int> instance;
	instance.push_back(4534);
	instance.push_back(34534);
	instance.push_back(345345);
	instance.push_back(123);

	instance.push_front(123456789);
	instance.push_back(123);
	instance.push_front(123456789);
	instance.print();
	cout << "" << endl;
	cout << instance.pop_front() << endl;
	cout << instance.pop_front() << endl;
	cout << instance.pop_front() << endl;
	cout << instance.pop_front() << endl;
	instance.print();
	cout << "" << endl;

	cout << instance.pop_back() << endl;
	instance.print();
	cout << "" << endl;

	instance.push_back(4534);
	instance.push_back(34534);
	instance.push_back(345345);
	instance.push_back(123);
	instance.print();
	cout << "" << endl;

	instance.insert(9999999, 2);

	instance.print();
	cout << "" << endl;
	
	cout << instance.remove_at(3) << endl;

	instance.print();

	system("pause");
	return 0;
}