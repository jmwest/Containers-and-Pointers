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

template <typename T>
Dlist<T>::Dlist()                                   // ctor
: first(0), last(0)
{
	assert(first == 0);
	assert(last == 0);
}

//EFFECTS:  returns true if the list is empty
template <typename T>
bool Dlist<T>::isEmpty() const
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
template <typename T>
void Dlist<T>::insertFront(const T &datum)
{
	Node *node = new Node;

	node->next = first;
	node->prev = 0;
	node->datum = datum;

	first = node;

	return;
}

//MODIFIES: this
//EFFECTS:  inserts v into the back of the list
template <typename T>
void Dlist<T>::insertBack(const T &datum)
{
	Node *node = new Node;

	node->next = 0;
	node->prev = last;
	node->datum = datum;

	last = node;

	return;
}

//REQUIRES: list is not empty
//MODIFIES: this
//EFFECTS:  removes the item at the front of the list
template <typename T>
T Dlist<T>::removeFront()
{
	assert(!isEmpty());

	Node *node = first;
	T datum = first->datum;

	first = first->next;

	delete node; node = 0;

	return datum;
}

//REQUIRES: list is not empty
//MODIFIES: this
//EFFECTS:  removes the item at the back of the list
template <typename T>
T Dlist<T>::removeBack()
{
	assert(!isEmpty());

	Node *node = last;
	T datum = last->datum;

	if (first == last)
	{
		first = 0;
		last = 0;
	}
	else
	{
		last->prev->next = 0;
	}

	delete node; node = 0;

	return datum;
}

template <typename T>
Dlist<T>::Dlist(const Dlist &l)                     // copy ctor
: first(0), last(0)
{
	copyAll(l);
}

template <typename T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &l)          // assignment
{
	if (this != &l)
	{
		removeAll();
		copyAll(l);
	}

	return *this;
}

template <typename T>
Dlist<T>::~Dlist()
{
	removeAll();
}

//MODIFIES: this
//EFFECTS:  copies all nodes from l to this
template <typename T>
void Dlist<T>::copyAll(const Dlist<T> &l)
{
	Node *node = l.first;

	while (node)
	{
		insertBack(node->datum);

		node = node->next;
	}

	return;
}

//MODIFIES: this
//EFFECTS:  removes all nodes
template <typename T>
void Dlist<T>::removeAll()
{
	while (!isEmpty())
	{
		removeFront();
	}

	return;
}

/* this must be at the end of the file */
#endif /* __DLIST_H__ */