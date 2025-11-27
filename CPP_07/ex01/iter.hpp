#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T* array, const size_t array_len, F func){

	for (size_t i = 0; i < array_len; i++)
		func(array[i]);
}

template <typename T, typename F>
void	iter(T const* array, const size_t array_len, F func){

	for (size_t i = 0; i < array_len; i++)
		func(array[i]);
}
