//
//  dlist.h
//  proj5
//
//  Created by John West on 11/29/13.
//  Copyright (c) 2013 John West. All rights reserved.
//
// copy this file to "dlist.h" and then modify it where specified below
#ifndef __DLIST_H__
#define __DLIST_H__
#include <cstddef>
#include <cassert>

/*****************************************
 * Do not modify the class declarations! *
 *****************************************/
template <typename T>
class Dlist {
	//OVERVIEW: a doubly-linked list
public:
	
	//EFFECTS:  returns true if the list is empty
	bool isEmpty() const;
	
	//MODIFIES: this
	//EFFECTS:  inserts v into the front of the list
	void insertFront(const T &datum);
	
	//MODIFIES: this
	//EFFECTS:  inserts v into the back of the list
	void insertBack(const T &datum);
	
	//REQUIRES: list is not empty
	//MODIFIES: this
	//EFFECTS:  removes the item at the front of the list
	T removeFront();
	
	//REQUIRES: list is not empty
	//MODIFIES: this
	//EFFECTS:  removes the item at the back of the list
	T removeBack();
	
	Dlist();                                   // ctor
	Dlist(const Dlist &l);                     // copy ctor
	Dlist &operator=(const Dlist &l);          // assignment
	~Dlist();                                  // dtor
	
private:
	struct Node {                              // A private type
		Node   *next;
		Node   *prev;
		T      datum;
	};
	
	Node   *first; // The pointer to the first node (0 if none)
	Node   *last;  // The pointer to the last node (0 if none)
	
	//MODIFIES: this
	//EFFECTS:  copies all nodes from l to this
	void copyAll(const Dlist &l);
	
	//MODIFIES: this
	//EFFECTS:  removes all nodes
	void removeAll();
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/


/***************************************
 * Member function implementations here
 ***************************************/

Dlist::Dlist()                                   // ctor
: first(0), last(0)
{
	assert(first == 0);
	assert(last == 0);
}

//EFFECTS:  returns true if the list is empty
bool Dlist::isEmpty() const
{
	if ((first == 0) and (last == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//MODIFIES: this
//EFFECTS:  inserts v into the front of the list
void Dlist::insertFront(const T &datum)
{
	Node node = new Node;

	node.prev = 0;

	if (isEmpty())
	{
		node.next = 0;
		first = &node;
		last = &node;

		node.datum = datum;
	}
	else
	{
		
	}

	return;
}

//MODIFIES: this
//EFFECTS:  inserts v into the back of the list
void Dlist::insertBack(const T &datum)
{
	

	return;
}

//REQUIRES: list is not empty
//MODIFIES: this
//EFFECTS:  removes the item at the front of the list
T Dlist::removeFront();

//REQUIRES: list is not empty
//MODIFIES: this
//EFFECTS:  removes the item at the back of the list
T Dlist::removeBack();

Dlist::Dlist(const Dlist &l);                     // copy ctor
Dlist::Dlist &operator=(const Dlist &l);          // assignment
Dlist::~Dlist();

//MODIFIES: this
//EFFECTS:  copies all nodes from l to this
void copyAll(const Dlist &l)
{
	

	return;
}

//MODIFIES: this
//EFFECTS:  removes all nodes
void removeAll()
{
	

	return;
}

/* this must be at the end of the file */
#endif /* __DLIST_H__ */