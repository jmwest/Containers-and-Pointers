//
//  dlist_test00.cpp
//  proj5
//
//  Created by John West on 11/29/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "dlist.h"
#include "dlist_overload.h"

#include <iostream>

using namespace std;

template <typename T>
void print_lists(const Dlist<T> *l, const Dlist<T> *d);

int main()
{
	Dlist<int> list;
	// ( )
	Dlist<int> dl;
	// ( )

	print_lists(&list, &dl);
	assert(list.isEmpty());
	assert(dl.isEmpty());

	list.insertFront(1);
	// ( 1 )
	// ( )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(dl.isEmpty());

	list.insertBack(2);
	// ( 1 2 )
	// ( )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(dl.isEmpty());

	list.insertBack(3);
	dl.insertBack(4);
	// ( 1 2 3 )
	// ( 4 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeBack();
	// ( 1 2 )
	// ( 4 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.insertBack(4);
	// ( 1 2 4 )
	// ( 4 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.insertBack(8);
	// ( 1 2 4 8 )
	// ( 4 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	dl = list;
	// ( 1 2 4 8 )
	// ( 1 2 4 8 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeFront();
	// ( 2 4 8 )
	// ( 1 2 4 8 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.insertFront(1);
	// ( 1 2 4 8 )
	// ( 1 2 4 8 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeFront();
	// ( 2 4 8 )
	// ( 1 2 4 8 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeFront();
	// ( 4 8 )
	// ( 1 2 4 8 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeFront();
	dl.removeBack();
	// ( 8 )
	// ( 1 2 4 )

	print_lists(&list, &dl);
	assert(!list.isEmpty());
	assert(!dl.isEmpty());

	list.removeFront();
	dl.removeBack();
	// ( )
	// ( 1 2 )

	print_lists(&list, &dl);
	assert(list.isEmpty());
	assert(!dl.isEmpty());

	dl.insertFront(7);
	// ( )
	// ( 7 1 2 )

	print_lists(&list, &dl);
	assert(list.isEmpty());
	assert(!dl.isEmpty());

	Dlist<int> ctor(dl);
	// ( )
	// ( 7 1 2 )
	// ( 7 1 2 )

	print_lists(&dl, &ctor);
	assert(list.isEmpty());
	assert(!dl.isEmpty());
	assert(!ctor.isEmpty());

	ctor.removeBack();
	dl.insertFront(3);
	// ( )
	// ( 3 7 1 2 )
	// ( 7 1 )

	print_lists(&dl, &ctor);
	assert(list.isEmpty());
	assert(!dl.isEmpty());
	assert(!ctor.isEmpty());

	return 0;
}

template <typename T>
void print_lists(const Dlist<T> *l, const Dlist<T> *d)
{
	cout << *l << *d;

	return;
}
