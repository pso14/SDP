#pragma once
#include "DynamicArray.h"

template<typename T>
class Stack
{
	DynamicArray<T> data;
public:
	Stack() :data() {}
	size_t size() { return data.getSize(); }
	void pop() { data.pop_back(); }
	void push(T val) { data.push_back(val); }

	T& top() { return data.getAt(data.getSize() - 1); }
	const T& top()const { return data.getAt(data.getSize() - 1); }
	bool isEmpty() { return data.isEmpty(); }
	void print() { data.print(); }
};
