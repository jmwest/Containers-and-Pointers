//
//  call.cpp
//  proj5
//
//  Created by John West on 12/5/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "dlist.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

// A struct that contains the four elements of an event as:
//		an unsigned int for the timestamp,
//		a string for the name,
//		a string for the status, and
//		an unsigned int for the duration.
// The default constructor sets the Event to be:
//		timestamp = 0,
//		name = "",
//		status = "none",
//		duration = 0.
struct Event {
public:
	Event()
	: timestamp(0), name(""), status("none"), duration(0)
	{
		assert(timestamp == 0);
		assert(strcmp(name.c_str(), "") == 0);
		assert(strcmp(status.c_str(), "none") == 0);
		assert(duration == 0);
	}

	unsigned int timestamp;
	string name;
	string status;
	unsigned int duration;
};

//
static void print_tick(int tick);

// REQUIRES: name is an initialized string
//			 status is an initialized string
//			 status is either "none", "silver", "gold", or "platinum"
static void print_call_from_client(const string * name, const string * status);

//
static void print_answering_call(const string * name);

int main()
{
	Dlist<Event*> event_list;
	Dlist<Event*> not_special;
	Dlist<Event*> silver;
	Dlist<Event*> gold;
	Dlist<Event*> platinum;
	int events = 0;
	int time = 0;
	int duration_remaining = 0;
	int calls_answered = 0;
	bool calls_left = true;

	cin >> events;

	for (int i = 0; i < events; i++)
	{
		Event *event = new Event;

		cin >> event->timestamp >> event->name >> event->status >> event->duration;

		event_list.insertBack(event);

		delete event; event = 0;
	}

	while (calls_left)
	{
		print_tick(time);

		bool callers = false;
		Event *first_queue;

		if (!event_list.isEmpty())
		{
			callers = true;
			first_queue = event_list.removeFront();
		}

		while (callers)
		{
			if (first_queue->timestamp == time)
			{
				if (!strcmp(first_queue->status.c_str(), "none"))
				{
					not_special.insertBack(first_queue);
				}
				else if (!strcmp(first_queue->status.c_str(), "silver"))
				{
					silver.insertBack(first_queue);
				}
				else if (!strcmp(first_queue->status.c_str(), "gold"))
				{
					gold.insertBack(first_queue);
				}
				else if (!strcmp(first_queue->status.c_str(), "platinum"))
				{
					platinum.insertBack(first_queue);
				}

				print_call_from_client(&first_queue->name, &first_queue->status);

				delete first_queue; first_queue = 0;

				first_queue = event_list.removeFront();
			}
			else
			{
				event_list.insertFront(first_queue);
				callers = false;
			}
		}

		first_queue = 0;

		if (duration_remaining == 0)
		{
			Event *next_call;

			if (!platinum.isEmpty())
			{
				next_call = platinum.removeFront();
				print_answering_call(&next_call->name);
				duration_remaining = next_call->duration;

				delete next_call; next_call = 0;
			}
			else if (!gold.isEmpty())
			{
				next_call = gold.removeFront();
				print_answering_call(&next_call->name);
				duration_remaining = next_call->duration;
				
				delete next_call; next_call = 0;
			}
			else if (!silver.isEmpty())
			{
				next_call = silver.removeFront();
				print_answering_call(&next_call->name);
				duration_remaining = next_call->duration;
				
				delete next_call; next_call = 0;
			}
			else if (!not_special.isEmpty())
			{
				next_call = not_special.removeFront();
				print_answering_call(&next_call->name);
				duration_remaining = next_call->duration;
				
				delete next_call; next_call = 0;
			}
		}

		if ((calls_answered == events) and (duration_remaining == 0) and (event_list.isEmpty()))
		{
			calls_left = false;
		}
		else if (duration_remaining > 0)
		{
			duration_remaining--;
		}

		time++;
	}

	return 0;
}

static void print_tick(int tick)
{
	cout << "Starting tick #" << tick << endl;

	return;
}

static void print_call_from_client(const string * name, const string * status)
{
	cout << "Call from " << *name << " a ";

	if (!strcmp(status->c_str(), "none"))
	{
		cout << "regular member\n";
	}
	else if (!strcmp(status->c_str(), "silver"))
	{
		cout << "silver member\n";
	}
	else if (!strcmp(status->c_str(), "gold"))
	{
		cout << "gold member\n";
	}
	else if (!strcmp(status->c_str(), "platinum"))
	{
		cout << "platinum member\n";
	}

	return;
}

static void print_answering_call(const string * name)
{
	cout << "Answering call from " << *name << endl;

	return;
}
