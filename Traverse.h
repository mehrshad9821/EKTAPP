/*
 * Traverse.h
 *
 * Class Definition: Abstract class for traverse binary search tree
 *                   used in order to pass function as parameter
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

#pragma once

template<class Data>
class Traverse
{
	public:
		virtual void traverse(const Data& data) const = 0;
}; // end of Traverse class
