/*
 * EKTApp.cpp
 *
 * Definition: EKTApp, which, when given an English word, prints the given English along with its Klingon translation. 
 * Bonus part has also been implemented.                   
 *
 * Created on: Jul 15th 2016
 * Author: Mehrshad Matin 
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

#include "Entry.h"
#include "BinarySearchTree.h"
#include "DisplayData.h"

void readDataFile(BinarySearchTree<Entry>& dictionary);
void translate(BinarySearchTree<Entry>& dictionary);
void buildBalancedTree(Entry* Entrys[], int first, int last, BinarySearchTree<Entry>& dictionary);

int main(int argc, char* argv[])
{
	BinarySearchTree<Entry> dictionary;

	readDataFile(dictionary);

	if (argc>1)
	{
		string arg = argv[1];
		if (arg=="display")
		{
			DisplayData dd;
			dictionary.inOrder(&dd);
			return 0;
		}
	}
	translate(dictionary);
	return 0;
}

void merge(Entry* entries[], int first, int mid, int last)
{
	Entry** temp = new Entry*[last + 1];

	// initializes the local indices to indicate the subarrays
	int first1 = first;
	int last1 = mid;
	int first2 = mid+1;
	int last2 = last;

	int index = first1;
	while((first1 <= last1) && (first2 <= last2))
	{
		if ((*(entries[first1])) <= (*(entries[first2])))
		{
			temp[index] = entries[first1];
			first1++;
		}
		else
		{
			temp[index] = entries[first2];
			first2++;
		}
		index++;
	}

	// Finish off first subarray, if necessary
	while(first1<=last1)
	{
		temp[index] = entries[first1];
		index++;
		first1++;
	}

	// Finish off second subarray, if necessary
	while(first2<=last2)
	{
		temp[index] = entries[first2];
		index++;
		first2++;
	}

	for(index = first; index <= last; index++)
	{
		entries[index] = temp[index];
	}

	delete temp;
}

// Sort Entrys in order to build balanced trees
void mergeSort(Entry* entries[], int first, int last)
{
	if (first < last)
	{
		// sort each half
		int mid = first + (last - first) / 2;

		// sort left half
		mergeSort(entries, first, mid);

		// sort right half
		mergeSort(entries, mid+1, last);

		// Merge two sorted halves
		merge(entries, first, mid, last);
	}
}

// "populate the translator" by reading each pair of words from this data file....
void readDataFile(BinarySearchTree<Entry>& dictionary)
{
	string line;
	int n = 0;

	char* filename = (char*)"dataFile.txt";
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		cout << "Reading from a file:" << endl;
		// Calculate number of entries
		while ( getline (myfile, line) )
		{
			n++;
		}
		
		// Read file fron beginning again
		myfile.clear();
		myfile.seekg(0);
		
		// read data
		Entry** entries = new Entry*[n]; 
		int i = 0;
		while ( getline (myfile, line) )
		{
			string english, klingon;

			stringstream ss(line);

			getline(ss, english, ':');
			getline(ss, klingon);
			entries[i] = new Entry(english, klingon);
			i++;
		}

		// sort array in order to build balanced tree
		mergeSort(entries, 0, n-1);

		// Building balanced tree itself
		buildBalancedTree(entries, 0, n-1, dictionary);

		myfile.close();
		delete entries;
	}
	else cout << "Unable to open file";
}

void translate(BinarySearchTree<Entry>& dictionary)
{
	string aLine;

	cout << "Reading from cin:" << endl;

	stringstream ss(aLine);
	string english;

	while(getline(cin, aLine))
	{		
		ss << aLine << endl;
	}
	
	while(getline(ss, english))
	{
		Entry e(english, "");
		if (dictionary.contains(e))
			cout << english << ":" << e.getKlingonWord() << endl;
		else
			cout << english << ":<not found>" << endl;
	}
}

void buildBalancedTree(Entry* entries[], int first, int last, BinarySearchTree<Entry>& dictionary)
{
	if (first<=last)
	{
		int mid = first + (last - first) / 2;
		
		dictionary.insert(*entries[mid]);
		buildBalancedTree(entries, first, mid-1, dictionary);
		buildBalancedTree(entries, mid+1, last, dictionary);
	}	
}
