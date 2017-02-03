/*
 * BinarySearchTree.h
 *
 * Class Definition: Binary search tree template class

 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */


#pragma once

#include "Node.h"
#include "Traverse.h"

template<class Data>
class BinarySearchTree
{	
	Node<Data>* root;
	void inOrder(Node<Data>* root, const Traverse<Data>* traverse);
public:
	// Constructors and destructor
	BinarySearchTree();
	~BinarySearchTree();

	void insert(const Data& data);	
	bool contains(Data& data) const;

	void inOrder(const Traverse<Data>* traverse);
}; // end of BinarySearchTree class

#include "BinarySearchTree.cpp"