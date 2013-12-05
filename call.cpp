//
//  call.cpp
//  proj5
//
//  Created by John West on 12/5/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "dlist.h"
#include <string>

using namespace std;

struct Event {
public:
	Event()
	: timestamp(0), name(""), status("none"), duration(0) {}

	unsigned int timestamp;
	string name;
	string status;
	unsigned int duration;
};

int main()
{
	Dlist<Event> event_list;

	return 0;
}
