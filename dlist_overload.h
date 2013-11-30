//
//  dlist_overload.h
//  proj5
//
//  Created by John West on 11/29/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#ifndef proj5_dlist_overload_h
#define proj5_dlist_overload_h

#include "dlist.h"
#include <iostream>

template <typename T>
std::ostream& operator<< (std::ostream& os, const Dlist<T> & dl)
{
	Dlist<T> dlist = dl;

	os << "( ";

	while (!dlist.isEmpty())
	{
		os << dlist.removeFront() << " ";
	}

	os << ")" << std::endl;

	return os;
}

#endif
