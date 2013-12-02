//
//  calc.cpp
//  proj5
//
//  Created by John West on 12/2/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "dlist.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// MODIFIES: std::cin
// EFFECTS: adds user input to the dl stack.
//			calls check_valid_input to ensure input is valid.
//			returns a c-string to the input.
static string take_input();

// REQUIRES: input is a pointer to a c-string
// EFFECTS: checks to see if the input is valid according to the spec
static bool check_valid_input(string * input);

int main()
{
	string input = "";

	while (strcmp(input.c_str(),"q"))
	{
		input = take_input();
	}

	return 0;
}

static string take_input()
{
	string user_input;

	cin >> user_input;

	if (check_valid_input(&user_input))
	{
		
	}
	else
	{
		cout << "Bad input\n";
	}

	return user_input;
}

static bool check_valid_input(string * input)
{
	if (strcmp(input->c_str(), "+"))
	{
		
	}
	else if (strcmp(input->c_str(), "-"))
	{
		
	}
	else if (strcmp(input->c_str(), "*"))
	{
		
	}
	else if (strcmp(input->c_str(), "/"))
	{
		
	}
	else if (strcmp(input->c_str(), "n"))
	{
		
	}
	else if (strcmp(input->c_str(), "d"))
	{
		
	}
	else if (strcmp(input->c_str(), "r"))
	{
		
	}
	else if (strcmp(input->c_str(), "p"))
	{
		
	}
	else if (strcmp(input->c_str(), "c"))
	{
		
	}
	else if (strcmp(input->c_str(), "a"))
	{
		
	}
	else if (strcmp(input->c_str(), "q"))
	{
		
	}
	else
	{
		return false;
	}

	return true;
}