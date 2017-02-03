/*
 * BinarySearchTree.cpp
 *
 * Class Definition: Binary search tree template class

 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

// Description: constructor
template<class Data>
BinarySearchTree<Data>::BinarySearchTree()
{
	root = NULL;
}

// Description: destructor
template<class Data>
BinarySearchTree<Data>::~BinarySearchTree()
{
	// Remove nodes
	if (root)
		delete root;
}

// Description: Inserts data into tree
// Postcondition: inserted data if it was not inserted before 
template<class Data>
void BinarySearchTree<Data>::insert(const Data& data)
{
	if (!root)
	{
		root = new Node<Data>(data);
	}
	else
	{
		Node<Data>* node = root;
		while(node)
		{
			if (data < node->getData())
			{
				if (node->getLeft())
					node = node->getLeft();
				else
				{
					node->setLeft(new Node<Data>(data));
					break;
				}
			}
			else if (node->getData() == data)
			{
				break;
			}
			else 
			{
				if (node->getRight())
					node = node->getRight();
				else
				{
					node->setRight(new Node<Data>(data));
					break;
				}
			}
		}
	}	
}

// Description: Checks tree contains specified data
// Postcondition: returns true, if found, and data parameter is updated by tree data
template<class Data>
bool BinarySearchTree<Data>::contains(Data& data) const
{
	Node<Data>* node = root;
	while(node)
	{
		if (data < node->getData())
		{
			node = node->getLeft();			
		}
		else if (node->getData() == data)
		{
			data = node->getData();
			return true;
		}
		else 
		{			
			node = node->getRight();			
		}
	}

	return false;
}

// Description: Traverse binary search tree in-order
// Precondition: traverse is not null
// Postcondition: each node is visited in order and traverse is called on each node
template<class Data>
void BinarySearchTree<Data>::inOrder(const Traverse<Data>* traverse)
{
	inOrder(root, traverse);
}

// Description: Recursive version of traverse binary search tree in-order
// Precondition: traverse is not null
// Postcondition: each node is visited in order and traverse is called on each node
template<class Data>
void BinarySearchTree<Data>::inOrder(Node<Data>* node, const Traverse<Data>* traverse)
{
	if (node)
	{
		inOrder(node->getLeft(), traverse);
		traverse->traverse(node->getData());
		inOrder(node->getRight(), traverse);
	}
}
