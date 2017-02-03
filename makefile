all: EKTApp

EKTApp: Entry.h Entry.cpp Node.h Node.cpp Traverse.h BinarySearchTree.h BinarySearchTree.cpp DisplayData.h DisplayData.cpp EKTApp.cpp
	g++ -Wall Entry.cpp DisplayData.cpp EKTApp.cpp -o EKTApp