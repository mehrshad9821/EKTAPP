/*
 * DisplayData.h
 *
 * Class Definition: Class for traverse binary search tree, and display data
 *                   used in order to pass function as parameter
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */


#pragma once

#include "Traverse.h"
#include "Entry.h"

class DisplayData : public Traverse<Entry>
{
	public:
		virtual void traverse(const Entry& data) const;
}; // end of DisplayData
