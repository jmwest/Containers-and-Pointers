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
// EFFECTS: calls check_valid_input to ensure input is valid.
//			returns a string of the input.
static string take_input();

// REQUIRES: input is a pointer to an initialized string
// EFFECTS: checks to see if the input is valid according to the spec
//			calls check_input_is_operation()
//			calls check_input_is_number()
static bool check_valid_input(string * input);

// REQUIRES: input is a pointer to an initialized string
static bool check_input_is_operation(string * input);

// REQUIRES: input is a pointer to an initialized string
static bool check_input_is_number(string * input);

// REQUIRES: dlist is a pointer to an initialized Dlist
//			 input is a pointer to an initialized string
static void run_operation(Dlist<double> * dlist, string * input);

// REQUIRES: dlist is a pointer to an initialized Dlist
static bool check_stack_has_enough_operands(const Dlist<double> * dlist, int operands_needed);

static void print_not_enough_operands();

int main()
{
	string input = "";
	Dlist<double> stack;

	while (strcmp(input.c_str(),"q"))
	{
		input = take_input();

		if (check_input_is_operation(&input))
		{
			run_operation(&stack, &input);
		}
		else if (check_input_is_number(&input))
		{
			double number = atof(input.c_str());
			stack.insertFront(number);
		}

		
	}

	return 0;
}

static string take_input()
{
	string user_input;
	bool good_input = false;

	while (!good_input)
	{
		cin >> user_input;

		if (!check_valid_input(&user_input))
		{
			cout << "Bad input\n";
		}
	}

	return user_input;
}

static bool check_valid_input(string * input)
{
	if (check_input_is_operation(input) or check_input_is_number(input))
	{
		return true;
	}

	return false;
}

static bool check_input_is_operation(string * input)
{
	if (   (!strcmp(input->c_str(), "+"))
		or (!strcmp(input->c_str(), "-"))
		or (!strcmp(input->c_str(), "*"))
		or (!strcmp(input->c_str(), "/"))
		or (!strcmp(input->c_str(), "n"))
		or (!strcmp(input->c_str(), "d"))
		or (!strcmp(input->c_str(), "r"))
		or (!strcmp(input->c_str(), "p"))
		or (!strcmp(input->c_str(), "c"))
		or (!strcmp(input->c_str(), "a"))
		or (!strcmp(input->c_str(), "q")) )
	{
		return true;
	}

	return false;
}

static bool check_input_is_number(string * input)
{
	if ((atoi(&input->at(0)) >= 0) and (atoi(&input->at(0)) < 10))
	{
		if (strcmp(&input->at(1), "."))
		{
			if (input->size() <= 4)
			{
				return true;
			}
		}
		else if (input->size() == 1)
		{
			return true;
		}
	}

	return false;
}

static void run_operation(Dlist<double> * dlist, string * input)
{
	if (strcmp(input->c_str(), "+"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			
		}
		else
		{
			
		}
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

	return;
}

static bool check_stack_has_enough_operands(const Dlist<double> * dlist, int operands_needed)
{
	int stack_size = 0;
	Dlist<double> copy = *dlist;

	while (copy.isEmpty())
	{
		copy.removeBack();
		stack_size++;
	}

	if (stack_size >= operands_needed)
	{
		return true;
	}

	return false;
}

static void print_not_enough_operands()
{
	

	return;
}
