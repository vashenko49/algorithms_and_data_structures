#pragma once

template<typename Tkey, typename Tdata>
class Hash_Table
{
private:
	template<typename Tkey, typename Tdata>
	class Node
	{
	public:
		Node * pNext;
		Tkey key;
		Tdata data;
		Node(Tkey key = Tkey(), Tdata data = Tdata(), Node *pNext = nullptr)
		{
			this->key = key;
			this->data = data;
			this->pNext = pNext;

		}
	};
	Node< Tkey, Tdata > *head;
	Node<Tkey, Tdata> *Hash_Table_muss[150];
	int GetIndex(Tkey key);

public:

	Hash_Table();

	bool add(Tkey key, Tdata data); //Добавление нового узла (пары ключ-значение)
	Tdata remove(Tkey tkey);
	Tdata get_data(Tkey tkey);
	~Hash_Table();

};

template<typename Tkey, typename Tdata>
inline Hash_Table<Tkey, Tdata>::Hash_Table()
{
	head = nullptr;
}

template<typename Tkey, typename Tdata>
inline bool Hash_Table<Tkey, Tdata>::add(Tkey key, Tdata data)
{
	bool answer = true;
	int index = GetIndex(key);
	if(Hash_Table_muss[index]==nullptr)
	{
		Hash_Table_muss[index] = new Node<Tkey, Tdata>(key, data);
	}
	else
	{
		Node<Tkey, Tdata> *temp = Hash_Table_muss[index];
		while (temp->pNext!=nullptr)
		{
			temp=temp->pNext;
		}
		temp->pNext = new Node<Tkey, Tdata>(key, data);
	}
	return answer;
}

template<typename Tkey, typename Tdata>
inline Tdata Hash_Table<Tkey, Tdata>::remove(Tkey tkey)
{
	Tdata answer;
	Node<Tkey, Tdata> *temp = Hash_Table_muss[GetIndex(tkey)];
	if (temp == nullptr)
	{
		return nullptr;
	}
	else if(temp->pNext == nullptr)
	{
		answer = temp->data;
		delete temp;
		Hash_Table_muss[GetIndex(tkey)] = nullptr;
	}
	else
	{
		while (temp->pNext->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		answer = temp->pNext->data;
		delete temp->pNext;
		temp->pNext = nullptr;

	}
	return answer;
}

template<typename Tkey, typename Tdata>
inline Tdata Hash_Table<Tkey, Tdata>::get_data(Tkey tkey)
{
	Tdata answer;
	Node<Tkey, Tdata> *temp = Hash_Table_muss[GetIndex(tkey)];
	if (temp == nullptr)
	{
		return nullptr;
	}
	else if (temp->pNext == nullptr)
	{
		answer = temp->data;
	}
	else
	{
		while (temp->pNext->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		answer = temp->pNext->data;
	}
	return answer;
}

template<typename Tkey, typename Tdata>
inline int Hash_Table<Tkey, Tdata>::GetIndex(Tkey key)
{
	int N = 150; double A = 0.618033;
	int h = N * fmod(key*A, 1);
	return h;
}

template<typename Tkey, typename Tdata>
inline Hash_Table<Tkey, Tdata>::~Hash_Table()
{
}
