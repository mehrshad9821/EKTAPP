/*
 * Entry.cpp
 *
 * Class Definition: Entry of a dictionary
 *                   in which the data are 2 members of string data type.
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin
 */

#include <cstring>
#include "Entry.h"

Entry::Entry()
{	
}

Entry::Entry(string english, string klingon)
{
	this->english = english;
	this->klingon = klingon;	
}

bool Entry::operator<(const Entry& Entry) const
{
	return strcasecmp(english.c_str(), Entry.english.c_str())<0;
}

bool Entry::operator<=(const Entry& Entry) const
{
	return strcasecmp(english.c_str(), Entry.english.c_str())<=0;
}

bool Entry::operator==(const Entry& Entry) const
{
	return strcasecmp(english.c_str(), Entry.english.c_str())==0;
}

string Entry::getEnglishWord() const
{
	return english;
}

string Entry::getKlingonWord() const
{
	return klingon;
}
