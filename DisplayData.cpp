/*
 * DisplayData.cpp
 *
 * Class Definition: Class for traverse binary search tree, and display data
 *                   used in order to pass function as parameter
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin 
 */

#include <iostream>
#include "DisplayData.h"
using namespace std;

// Description: This function is called each time when new new node is visited
void DisplayData::traverse(const Entry& data) const
{
	cout << data.getEnglishWord() << ":" << data.getKlingonWord() << endl;
}
