/*
 * Node.cpp
 *
 * Class Definition: Node of binary search tree

 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

// Description: constructor
template<class Data>
Node<Data>::Node()
{
	left = NULL;
	right = NULL;
}

// Description: parametrized constructor
template<class Data>
Node<Data>::Node(const Data& data)
{
	this->data = data;

	left = NULL;
	right = NULL;
}

// Description: destructor
template<class Data>
Node<Data>::~Node()
{
	if (left)
		delete left;

	if (right)
		delete right;
}

// Description: Returns data of current node
// Postcondition: returned data
template<class Data>
const Data& Node<Data>::getData() const
{
	return data;
}

// Description: Returns left child node of current node
template<class Data>
Node<Data>* Node<Data>::getLeft() const
{
	return left;
}

// Description: Returns right child node of current node
template<class Data>
Node<Data>* Node<Data>::getRight() const
{
	return right;
}

// Description: Sets left child node of current node
// Postconditions: updated left child node member
template<class Data>
void Node<Data>::setLeft(const Node<Data>* node)
{
	left = (Node<Data>*)node;
}

// Description: Sets right child node of current node
// Postconditions: updated right child node member
template<class Data>
void Node<Data>::setRight(const Node<Data>* node)
{
	right = (Node<Data>*)node;
}