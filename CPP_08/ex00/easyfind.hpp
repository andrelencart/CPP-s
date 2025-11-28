#pragma once

#include <iostream>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int value){
	for (typename T::iterator i = container.begin(); i != container.end ; i++){
		if (*i == value)
			return (i);
	}
	throw std::runtime_error("Value not found!!");
}
