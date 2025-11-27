#include "../Serializer.hpp"

int main(void) {
	std::cout << "---- Test 1: Valid serialization " << std::endl;

	Data my_data;
	my_data._id = 42;
	my_data._name = "TestData";
	my_data._value = 3.14;

	uintptr_t raw = Serializer::serialize(&my_data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original address:	" << &my_data << std::endl;
	std::cout << "Serialized:		0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "Deserialized:		" << ptr << std::endl;

	// Verify
	if (ptr == &my_data) {
	    std::cout << "Success: Pointers match!" << std::endl;
	    std::cout << "Data accessible: " << ptr->_name << std::endl;
	} else {
	    std::cout << "Failure: Pointers don't match" << std::endl;
	}

	std::cout << "---- Test 2: Invalid address " << std::endl;

	// Deserialize garbage value
	uintptr_t garbage = 12345;
	Data* bad_ptr = Serializer::deserialize(garbage);

	std::cout << "Garbage value:	" << garbage << std::endl;
	std::cout << "Deserialized:		" << bad_ptr << std::endl;
	std::cout << "Original address:	" << &my_data << std::endl;

	if (bad_ptr != &my_data) {
		std::cout << "As expected: Invalid pointer differs from original" << std::endl;
	}

	return 0;
}