#include <iostream>
#include <fstream>

template <typename T>
class heap {

public:
	typedef T			value_type;
	typedef size_t		size_type;
	typedef	T*			pointer;
	
	heap(void);
	~heap();

	void		push(const value_type& val);
	void		pop(void);

private:
	size_type	_size;
	pointer		_data;
};

template <typename T>
heap<T>::heap(void) {
	_data = new value_type[100000];
	_size = 0;
}

template <typename T>
heap<T>::~heap() {
	delete [] _data;
}


template <typename T>
void heap<T>::push(const value_type& val) {
	size_type	index = _size;
	value_type	buf = value_type();

	_data[_size++] = val;
	while (index && _data[index] > _data[(index - 1) >> 1]) {
		buf = _data[index];
		_data[index] = _data[(index - 1) >> 1];
		_data[(index - 1) >> 1] = buf;
		index = (index - 1) >> 1;
	}
}

template <typename T>
void heap<T>::pop(void) {
	size_type	index = 0;
	size_type	maximum = 0;
	value_type	buf = value_type();

	std::cout << _data[0] << std::endl;
	_data[0] = _data[--_size];
	_data[_size] = value_type();
	while ((index << 1) + 1 < _size) {
		maximum = (index << 1) + 1;
		if ((index << 1) + 2 < _size && _data[(index << 1) + 2] > _data[(index << 1) + 1])
			maximum++;
		if (_data[index] < _data[maximum]) {
			buf = _data[index];
			_data[index] = _data[maximum];
			_data[maximum] = buf;
			index = maximum;
		}
		else
			break ;
	}
}


int main(void) {
	std::ifstream	file;
	heap<int>		heap;
	int				n = 0, num = 0;
	bool			extract = true;

	file.open("input.txt", std::ifstream::in);
	if (file) {
		file >> n;

		for (int i = 0; i < n; ++i) {
			file >> extract;
			if (extract)
				heap.pop();
			else {
				file >> num;
				heap.push(num);
			}
		}
		file.close();
	}
	return 0;
}
