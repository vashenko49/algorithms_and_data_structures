#pragma once
template<typename  T>
class Grahp
{
	template<typename  T>
	class Node
	{
	public:
		Node *communic;
		T data;
		Node(T data = T(), int number_of_link = 1,Node* communic = nullptr)
		{
			this->data = data;
			communic = new Node[number_of_link];
		}
	};

	Node<T> *root;
public:
	Grahp();
	bool add_to_graph(T data, int number_of_link);
	~Grahp();
};

template <typename T>
Grahp<T>::Grahp()
{

}

template<typename T>
bool Grahp<T>::add_to_graph(T data, int number_of_link)
{
	Node<T>*current = new Node<T>;


	return false;
}

template <typename T>
Grahp<T>::~Grahp()
{

}
