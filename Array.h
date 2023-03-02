#pragma once
#include <functional>
#include <typeinfo>
#include "bad_range.h"
#include "bad_length.h"

template<typename T>
class Array
{
public:
	Array(size_t size = 0);
	Array(size_t size, const T &element);
	Array(const Array &other);
	bool empty() const;
	size_t size() const;
	size_t capacity() const;
	void push_front(const T &element);
	void pop_front();
	void push_back(const T &element);
	void pop_back();
	size_t find(const T &element) const;
	size_t find(std::function<bool(T)> predicate) const;
	void insert(size_t index, const T &element);
	void insert(size_t first, size_t last, const T &element);
	void insert(size_t index, const Array<T> &array);
	void erase(size_t index);
	void erase(size_t first, size_t last);
	void clear();
	void resize(size_t new_size);
	Array<T> &operator=(const Array<T> &right);
	T &operator[](size_t index) const;
	~Array();
private:
	size_t _size, _capacity;
	T *_data;
};



template<typename T>
Array<T>::Array(size_t size) : _size(size), _capacity(1)
{
	if (size < 0)
	{
		throw bad_length();
	}
	while (_capacity <= _size)
	{
		_capacity *= 2;
	}
	_data = new T[_capacity];
}

template<typename T>
Array<T>::Array(size_t size, const T &element) : _size(size), _capacity(1)
{
	if (size < 0)
	{
		throw bad_length();
	}
	while (_capacity <= _size)
	{
		_capacity *= 2;
	}
	_data = new T[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = element;
	}
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size), _capacity(other._capacity)
{
	_data = new T[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
bool Array<T>::empty() const
{
	return !_size;
}

template<typename T>
size_t Array<T>::size() const
{
	return _size;
}

template<typename T>
size_t Array<T>::capacity() const
{
	return _capacity;
}

template<typename T>
void Array<T>::push_front(const T &element)
{
	push_back(element);
	T buf;
	for (size_t i = _size - 1; i > 0; --i)
	{
		buf = _data[i - 1];
		_data[i - 1] = _data[i];
		_data[i] = buf;
	}
}

template<typename T>
void Array<T>::pop_front()
{
	T buf;
	for (size_t i = 0; i < _size - 1; ++i)
	{
		buf = _data[i + 1];
		_data[i + 1] = _data[i];
		_data[i] = buf;
	}
	pop_back();
}

template<typename T>
void Array<T>::push_back(const T &element)
{
	resize(_size + 1);
	_data[_size - 1] = element;
}

template<typename T>
void Array<T>::pop_back()
{
	resize(_size - 1);
}

template<typename T>
size_t Array<T>::find(const T &element) const
{
	size_t i = 0;
	for (; i < _size; ++i)
	{
		if (_data[i] == element)
		{
			break;
		}
	}
	return i;
}

template<typename T>
size_t Array<T>::find(std::function<bool(T)> predicate) const
{
	size_t i = 0;
	for (; i < _size; ++i)
	{
		if (predicate(_data[i]))
		{
			break;
		}
	}
	return i;
}

template<typename T>
void Array<T>::insert(size_t index, const T &element)
{
	if (index > _size)
	{
		throw bad_range();
	}
	resize(_size + 1);
	for (size_t i = _size - 1; i > index; --i)
	{
		_data[i] = _data[i - 1];
	}
	_data[index] = element;
}

template<typename T>
void Array<T>::insert(size_t first, size_t last, const T &element)
{
	if (first > _size || last < first)
	{
		throw bad_range();
	}
	resize(_size + last - first);
	for (size_t i = _size - 1; i > last; --i)
	{
		_data[i] = _data[i - last + first - 1];
	}
	for (size_t i = first; i < last; ++i)
	{
		_data[i] = element;
	}
}

template<typename T>
void Array<T>::insert(size_t index, const Array<T> &array)
{
	if (index > _size)
	{
		throw bad_range();
	}
	resize(_size + array._size);
	for (size_t i = _size - 1; i > index; --i)
	{
		_data[i] = _data[i - array._size - 1];
	}
	for (size_t i = index; i < index + array._size; ++i)
	{
		_data[i] = array._data[i - index];
	}
}

template<typename T>
void Array<T>::erase(size_t index)
{
	if (index < 0 || index >= _size)
	{
		throw bad_range();
	}
	for (size_t i = index; i < _size - 1; ++i)
	{
		_data[i] = _data[i + 1];
	}
	resize(_size - 1);
}

template<typename T>
void Array<T>::erase(size_t first, size_t last)
{
	if (first < 0 || first >= _size || last < 0 || last >= _size || last < first)
	{
		throw bad_range();
	}
	for (size_t i = first; i < _size - 1; ++i)
	{
		_data[i] = _data[i + last - first + 1];
	}
	resize(_size - last + first);
}

template<typename T>
void Array<T>::clear()
{
	_size = 0;
	_capacity = 1;
	delete[] _data;
	_data = new T[_capacity];
}

template<typename T>
void Array<T>::resize(size_t new_size)
{
	if (new_size == 0)
	{
		clear();
		return;
	}
	if (new_size == _size)
	{
		return;
	}
	size_t new_capacity = _capacity;

	while (new_capacity / 2 > new_size)
	{
		new_capacity /= 2;
	}
	while (new_capacity <= new_size)
	{
		new_capacity *= 2;
	}
	if (new_capacity != _capacity)
	{
		_capacity = new_capacity;
		T *new_data = new T[new_capacity];
		for (size_t i = 0; i < new_size; ++i)
		{
			if (i < _size)
			{
				new_data[i] = _data[i];
			}
		}
		delete[] _data;
		_data = new_data;
	}
	for (size_t i = _size; i < new_size; ++i)
	{
		if (typeid(T) == typeid(int8_t) || typeid(T) == typeid(int16_t) || typeid(T) == typeid(int32_t) || typeid(T) == typeid(long) || typeid(T) == typeid(int64_t) ||
			typeid(T) == typeid(uint8_t) || typeid(T) == typeid(uint16_t) || typeid(T) == typeid(uint32_t) || typeid(T) == typeid(unsigned long) || typeid(T) == typeid(uint64_t) ||
			typeid(T) == typeid(float_t) || typeid(T) == typeid(double_t) || typeid(T) == typeid(bool))
		{
			_data[i] = 0;
		}
	}
	_size = new_size;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &right)
{
	if (right._capacity != _capacity)
	{
		_capacity = right._capacity;
		delete[] _data;
		_data = new T[_capacity];
	}
	_size = right._size;
	for (size_t i = 0; i < _size; ++i)
	{
		_data[i] = right._data[i];
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](size_t index) const
{
	if (index >= _size)
	{
		throw bad_range();
	}
	return _data[index];
}

template<typename T>
Array<T>::~Array()
{
	delete[] _data;
	_data = nullptr;
}
