//
//  calc.cpp
//  proj5
//
//  Created by John West on 12/2/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "dlist.h"
#include <cstdlib>
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

//
static bool compare_char_to_nums(char elem);

// REQUIRES: dlist is a pointer to an initialized Dlist
//
static bool check_divides_by_zero(const Dlist<double> * dlist);

//
static void print_not_enough_operands();

//
static void print_divide_by_zero();

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
		else
		{
			good_input = true;
		}
	}

	return user_input;
}

static bool check_valid_input(string * input)
{
	if (   check_input_is_operation(input)
		or check_input_is_number(input))
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
	if (compare_char_to_nums(input->at(0)))
	{
		if (input->size() == 1)
		{
			return true;
		}
		else if (input->at(1) == '.')
		{
			for (unsigned int i = 2; i < input->size(); i++)
			{
				if (!compare_char_to_nums(input->at(i)))
				{
					return false;
				}
			}

			return true;
		}
		cout << input->at(1) << endl;

	}

	return false;
}

static void run_operation(Dlist<double> * dlist, string * input)
{
	if (!strcmp(input->c_str(), "+"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			double operand_one = dlist->removeFront();
			double operand_two = dlist->removeFront();
			double result = operand_one + operand_two;

			dlist->insertFront(result);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "-"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			double operand_one = dlist->removeFront();
			double operand_two = dlist->removeFront();
			double result = operand_two - operand_one;
			
			dlist->insertFront(result);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "*"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			double operand_one = dlist->removeFront();
			double operand_two = dlist->removeFront();
			double result = operand_one * operand_two;
			
			dlist->insertFront(result);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "/"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			if (!check_divides_by_zero(dlist))
			{
				double operand_one = dlist->removeFront();
				double operand_two = dlist->removeFront();
				double result = operand_two / operand_one;
				
				dlist->insertFront(result);
			}
			else
			{
				print_divide_by_zero();
			}
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "n"))
	{
		if (check_stack_has_enough_operands(dlist, 1))
		{
			double operand_one = dlist->removeFront();
			double result = operand_one * -1;
			
			dlist->insertFront(result);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "d"))
	{
		if (check_stack_has_enough_operands(dlist, 1))
		{
			double operand_one = dlist->removeFront();
			double operand_two = operand_one;
			
			dlist->insertFront(operand_one);
			dlist->insertFront(operand_two);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "r"))
	{
		if (check_stack_has_enough_operands(dlist, 2))
		{
			double operand_one = dlist->removeFront();
			double operand_two = dlist->removeFront();
			
			dlist->insertFront(operand_one);
			dlist->insertFront(operand_two);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "p"))
	{
		if (check_stack_has_enough_operands(dlist, 1))
		{
			double operand_one = dlist->removeFront();

			cout << operand_one << endl;
			
			dlist->insertFront(operand_one);
		}
		else
		{
			print_not_enough_operands();
		}
	}
	else if (!strcmp(input->c_str(), "c"))
	{
		while (!dlist->isEmpty())
		{
			dlist->removeFront();
		}
	}
	else if (!strcmp(input->c_str(), "a"))
	{
		Dlist<double> copy = *dlist;

		while (!copy.isEmpty())
		{
			cout << copy.removeFront() << " ";
		}

		cout << endl;
	}

	return;
}

static bool check_stack_has_enough_operands(const Dlist<double> * dlist, int operands_needed)
{
	int stack_size = 0;
	Dlist<double> copy = *dlist;

	while (!copy.isEmpty())
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

static bool check_divides_by_zero(const Dlist<double> * dlist)
{
	Dlist<double> copy = *dlist;

	if (!copy.isEmpty())
	{
		double divisor = copy.removeFront();

		if ( (divisor * 1) == 0)
		{
			return true;
		}
	}

	return false;
}

static bool compare_char_to_nums(char elem)
{
	if (   (elem == '0')
		or (elem == '1')
		or (elem == '2')
		or (elem == '3')
		or (elem == '4')
		or (elem == '5')
		or (elem == '6')
		or (elem == '7')
		or (elem == '8')
		or (elem == '9'))
	{
		return true;
	}

	return false;
}

static void print_not_enough_operands()
{
	cout << "Not enough operands\n";

	return;
}

static void print_divide_by_zero()
{
	cout << "Divide by zero\n";

	return;
}

