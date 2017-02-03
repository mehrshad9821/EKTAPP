/*
 * Node.h
 *
 * Class Definition: Node of binary search tree

 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

#pragma once

template<class Data>
class Node
{		
		Data data;
		Node<Data>* left;
		Node<Data>* right;
	public:
		// Constructors and destructor
		Node();
		Node(const Data& data);
		~Node();

		const Data& getData() const;
		Node<Data>* getLeft() const;
		Node<Data>* getRight() const;
		void setLeft(const Node<Data>* node);
		void setRight(const Node<Data>* node);
}; // end of Node

#include "Node.cpp"
