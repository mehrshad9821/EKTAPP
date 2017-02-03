/*
 * Entry.h
 *
 * Class Definition: Entry of a dictionary
 *                   in which the data are 2 members of string data type.
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

#pragma once
#include <string>

using namespace std;

class Entry
{
	string english;
	string klingon;
	
public:
	Entry();
	Entry(string english, string klingon);
	
	

	bool operator<(const Entry& Entry) const;
	bool operator<=(const Entry& Entry) const;
	bool operator==(const Entry& Entry) const;

	string getEnglishWord() const;
	string getKlingonWord() const;
}; // end Entry
