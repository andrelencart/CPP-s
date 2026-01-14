#include "../Array.hpp"

#include <iostream>

int main(void)
{
	std::cout << "---- Test 1: Empty Array" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	std::cout << std::endl;

	std::cout << "---- Test 2: Array with size" << std::endl;
	Array<int> numbers(5);
	std::cout << "Numbers array size: " << numbers.size() << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "Numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---- Test 3: Copy Constructor" << std::endl;
	Array<int> copy(numbers);
	std::cout << "Copy size: " << copy.size() << std::endl;

	numbers[0] = 999;
	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << " (should be 0, not 999)" << std::endl;
	std::cout << std::endl;

	std::cout << "---- Test 4: Assignment Operator" << std::endl;
	Array<int> assigned(10);
	assigned = numbers;
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	std::cout << std::endl;

	std::cout << "---- Test 5: Out of Bounds Exception" << std::endl;
	try
	{
		std::cout << "Trying to access index 100..." << std::endl;
		numbers[100] = 42;
		std::cout << "index 4 = " << numbers[100] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---- Test 6: String Array" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	std::cout << "Strings: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		 std::cout << strings[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}