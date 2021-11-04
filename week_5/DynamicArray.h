#pragma once
#include <iostream>
#include <cassert>
using namespace std;
template<typename T>
class DynamicArray
{
	const int expansionFactor = 2;
	size_t size;
	size_t capacity;
	T* data;

	void resize();
	void copyFrom(const DynamicArray& other);
public:
	DynamicArray(int initCapacity = 16);
	DynamicArray(const DynamicArray& other);
	const DynamicArray& operator=(const DynamicArray& other)
	{
		if (this != &other)
		{
			copyFrom(other);
		}
	}

	~DynamicArray();

	void push_back(const T& newValue);
	void pop_back();

	void insertAt(const T& newValue, int position);
	void removeAt(int position);
	T& getAt(int position);
	const T& getAt(int position) const;

	T& operator[](int position)
	{
		return getAt(position);
	}
	const T& operator[](int position) const
	{
		return getAt(position);
	}
	size_t getSize();
	bool isEmpty();
	void print();
	void clear();
	/*
	struct iterator
	{
	private:
		T* ptr;
		iterator(T* ptr) :ptr(ptr) {}
		friend struct DynamicArray;
	public:
		T& operator*();
		iterator operator++();
		iterator operator++(int);
		bool operator!=(const iterator&)const;
	};

	iterator begin()
	{
		return iterator(data);
	}
	iterator end();
	{
		return iterator(data + count);
	}
	*/
};

template<typename T>
inline void DynamicArray<T>::resize()
{
	T* newData = new T[capacity * expansionFactor];
	for (size_t i = 0; i < size; ++i)
	{
		newData[i] = data[i];
	}
	capacity *= expansionFactor;
	delete[] data;
	data = newData;
}

template<typename T>
inline void DynamicArray<T>::copyFrom(const DynamicArray& other)
{
	T* newData = new T[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		newData[i] = other.data[i];
	}
	delete[] data;
	data = newData;
	size = other.size;
	capacity = other.capacity;
}

template<typename T>
inline DynamicArray<T>::DynamicArray(int initCapacity)
{
	size = 0;
	capacity = (initCapacity == 0) ? 16 : initCapacity;
	data = new T[capacity];
}

template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	copyFrom(other);
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] data;
}

template<typename T>
inline void DynamicArray<T>::push_back(const T& newValue)
{
	insertAt(newValue, size);
}

template<typename T>
inline void DynamicArray<T>::pop_back()
{
	if (size > 0)
	{
		size--;
	}
}

template<typename T>
inline void DynamicArray<T>::insertAt(const T& newValue, int position)
{
	if (size == capacity)
	{
		resize();
	}
	//shift the elements right so that you can fit the new element
	for (int i = size - 1; i > position; --i)//??? is this a valid shift #todo
	{
		data[i] = data[i - 1];
	}
	data[position] = newValue;
	size++;

}

template<typename T>
inline void DynamicArray<T>::removeAt(int position)
{
	for (size_t i = position; i < size - 1; i++)//??? is this a valid shift #todo
	{
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
inline T& DynamicArray<T>::getAt(int position) { return data[position]; }

template<typename T>
inline const T& DynamicArray<T>::getAt(int position) const { return data[position]; }

template<typename T>
inline size_t DynamicArray<T>::getSize() { return size; }

template<typename T>
inline bool DynamicArray<T>::isEmpty() { return size == 0; }

template<typename T>
inline void DynamicArray<T>::print()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template<typename T>
inline void DynamicArray<T>::clear() { size = 0; }
