#include <iostream>
#include <fstream>

template <typename T>
class heap {

public:
	typedef T			value_type;
	typedef	T&			reference;
	typedef size_t		size_type;
	typedef	T*			pointer;
	
	heap(const size_type& size = 100000);
	~heap();

	reference	operator [] (size_type n);

	void		heapify(void);
	void		push(const value_type& val);
	void		pop(void);

private:
	size_type	_size;
	pointer		_data;
};

template <typename T>
heap<T>::heap(const size_type& size) {
	_data = new value_type[size];
	_size = 0;
}

template <typename T>
heap<T>::~heap() {
	delete [] _data;
}

template <typename T>
typename heap<T>::reference heap<T>::operator [] (size_type n) {
	if (n <= _size)
		_size++;
	return _data[n];
}

template <typename T>
void heap<T>::heapify(void) {
	size_type	up_index = (_size >> 1);
	size_type	down_index;
	size_type	minimum;
	value_type	buf;

	while (up_index--) {
		down_index = up_index;
		while ((down_index << 1) + 1 < _size) {
			minimum = (down_index << 1) + 1;
			if ((down_index << 1) + 2 < _size && _data[(down_index << 1) + 2] < _data[(down_index << 1) + 1])
				minimum++;
			if (_data[down_index] > _data[minimum]) {
				buf = _data[minimum];
				_data[minimum] = _data[down_index];
				_data[down_index] = buf;
				down_index = minimum;
			}
			else
				break ;
		}
	}
}

template <typename T>
void heap<T>::push(const value_type& val) {
	size_type	index = _size;
	value_type	buf;

	_data[_size++] = val;
	while (index && _data[index] < _data[(index - 1) >> 1]) {
		buf = _data[index];
		_data[index] = _data[(index - 1) >> 1];
		_data[(index - 1) >> 1] = buf;
		index = (index - 1) >> 1;
	}
}

template <typename T>
void heap<T>::pop(void) {
	size_type	index = 0;
	size_type	minimum;
	value_type	buf;

	std::cout << _data[0] << " ";
	_data[0] = _data[--_size];
	_data[_size] = value_type();
	while ((index << 1) + 1 < _size) {
		minimum = (index << 1) + 1;
		if ((index << 1) + 2 < _size && _data[(index << 1) + 2] < _data[(index << 1) + 1])
			minimum++;
		if (_data[index] > _data[minimum]) {
			buf = _data[index];
			_data[index] = _data[minimum];
			_data[minimum] = buf;
			index = minimum;
		}
		else
			break ;
	}
}

int main(void) {
	heap<int>		heap;
	std::ifstream	file;
	int				n = 0;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n;
		for (int i = 0, j = 0; i < n; ++i)
			file >> heap[i];
		heap.heapify();
		for (int i = 0; i < n; ++i)
			heap.pop();
		std::cout << std::endl;
		file.close();
	}
}