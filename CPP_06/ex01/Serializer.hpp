#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"


class Serializer{
	private:

	public:
	Serializer();
	Serializer(const Serializer &other);
	Serializer& operator=(const Serializer &other);
	virtual ~Serializer() = 0;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif