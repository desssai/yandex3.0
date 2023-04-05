#include <memory>
#include <fstream>
#include <iostream>
#include <string>

namespace ft
{


template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}


} /* FT NAMESPACE */


namespace ft
{


template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <typename InputIterator1, typename InputIterator2, typename Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
	while (first1 != last1)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}


} /* FT NAMESPACE */

namespace ft
{


template <typename Iterator>
class iterator_traits {

public:
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::pointer				pointer;
};

template <typename T>
class iterator_traits<T*> {

public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T&								reference;
	typedef T*								pointer;
};

template <typename T>
class iterator_traits<const T*> {

public:
	typedef std::random_access_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T&						reference;
	typedef const T*						pointer;
};


} /* FT NAMESPACE */

namespace ft
{


template <typename Iterator>
class reverse_iterator {

private:
	/* MEMBER TYPES */

	typedef typename ft::iterator_traits<Iterator>		traits_type;

public:
	typedef typename traits_type::iterator_category		iterator_category;
	typedef typename traits_type::difference_type		difference_type;
	typedef Iterator									iterator_type;
	typedef typename traits_type::value_type			value_type;
	typedef typename traits_type::reference				reference;
	typedef typename traits_type::pointer				pointer;

	/* ASSIGNMENT */

	reverse_iterator();
	explicit reverse_iterator(iterator_type it);
	reverse_iterator(const reverse_iterator& other);
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter>& other);
	~reverse_iterator();

	reverse_iterator&		operator = (const reverse_iterator& other);
	template <typename Iter>
	reverse_iterator&		operator = (const reverse_iterator<Iter>& other);

	/* MEMBER METHODS */

	const iterator_type		base(void) const;
	reverse_iterator&		operator ++	(void);
	reverse_iterator		operator ++	(int);
	reverse_iterator&		operator --	(void);
	reverse_iterator		operator --	(int);
	reference				operator *	(void) const;
	pointer					operator ->	(void) const;
	reverse_iterator&		operator +=	(const difference_type& n);
	reverse_iterator&		operator -=	(const difference_type& n);
	reverse_iterator		operator -	(const difference_type& n) const;
	reverse_iterator		operator +	(const difference_type& n);
	reference				operator []	(const difference_type& n) const;

private:
	/* ATTRIBUTES */

	iterator_type	_base;
};

/* ASSIGNMENT START --> */

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator() : _base(Iterator()) {}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(Iterator it) : _base(it) {}

template <typename Iterator>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& other) {
	*this = other;
}

template <typename Iterator>
template <typename Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& other) {
	*this = other;
}

template <typename Iterator>
reverse_iterator<Iterator>::~reverse_iterator() {}

/* <-- ASSIGNMENT END */

/* MEMBER METHODS START --> */

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator = (const reverse_iterator& other) {
	if (*this != other)
		_base = other.base();
	return (*this);
}

template <typename Iterator>
template <typename Iter>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator = (const reverse_iterator<Iter>& other) {
	if (*this != other)
		_base = other.base();
	return (*this);
}

template <typename Iterator>
const typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base(void) const {
	return _base;
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator * (void) const {
	iterator_type	copy(_base);
	return *(--copy);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator + (const difference_type& n) {
	return reverse_iterator<Iterator>(_base - n);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator ++ (void) {
	--_base;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator ++ (int) {
	reverse_iterator<Iterator>	copy(*this);

	--_base;
	return (copy);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator += (const difference_type& n) {
	_base -= n;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator - (const difference_type& n) const {
	return reverse_iterator<Iterator>(_base + n);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator -- (void) {
	++_base;
	return (*this);
}

template <typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator -- (int) {
	reverse_iterator<Iterator>	copy(*this);

	++_base;
	return (copy);
}

template <typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator -= (const difference_type& n) {
	_base += n;
	return (*this);
}

template <typename Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator -> (void) const {
	return &(operator*());
}

template <typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator [] (const difference_type& n) const {
	return _base[-n-1];
}

/* <-- MEMBER METHODS END */

/* NON-MEMBER OPERATORS START --> */

template <typename Iterator> 
bool operator == (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator == (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() == rhs.base());
}

template <typename Iterator> 
inline bool operator != (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename IteratorL, typename IteratorR> 
inline bool operator != (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() != rhs.base());
}

template <typename Iterator> 
bool operator < (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator < (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() > rhs.base());
}

template <typename Iterator> 
bool operator <= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator <= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <typename Iterator> 
bool operator > (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator > (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() < rhs.base());
}

template <typename Iterator> 
bool operator >= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename IteratorL, typename IteratorR> 
bool operator >= (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <typename Iterator, typename Container>
typename reverse_iterator<Iterator>::difference_type operator - (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return rhs.base() - lhs.base();
}

template <typename IteratorL, typename IteratorR>
typename reverse_iterator<IteratorL>::difference_type operator - (const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs) {
	return rhs.base() - lhs.base();
}

template <typename Iterator>
reverse_iterator<Iterator>	operator + (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	return reverse_iterator<Iterator>(rev_it.base() - n);
}

/* <-- NON-MEMBER OPERATORS END */


}; /* FT NAMESPACE */

namespace ft
{


template <typename T, T v>
class integral_constant {

public:
	static const T	value = v;

	typedef	T value_type;
	typedef integral_constant type;

	operator value_type() const { return value; }
};


typedef integral_constant<bool, true>	true_type;
typedef integral_constant<bool, false>	false_type;


}; /* FT NAMESPACE */

namespace ft
{


template <typename T>	class is_integral : public false_type {};

template <> 			class is_integral<bool> : public true_type {};

template <> 			class is_integral<int> : public true_type {};
template <> 			class is_integral<unsigned int> : public true_type {};

template <> 			class is_integral<long int> : public true_type {};
template <> 			class is_integral<unsigned long int> : public true_type {};

template <> 			class is_integral<short int> : public true_type {};
template <> 			class is_integral<unsigned short int> : public true_type {};

template <> 			class is_integral<long long int> : public true_type {};
template <> 			class is_integral<unsigned long long int> : public true_type {};

template <> 			class is_integral<char> : public true_type {};
template <> 			class is_integral<wchar_t> : public true_type {};
template <> 			class is_integral<signed char> : public true_type {};
template <> 			class is_integral<unsigned char> : public true_type {};


}; /* FT NAMESPACE */

namespace ft
{


template <typename T, typename Allocator = std::allocator<T> >
class deque_node {

public:
	typedef T						value_type;
	typedef Allocator				allocator_type;
	typedef T*						pointer;
	typedef const T*				const_pointer;
	typedef T&						reference;
	typedef const T&				const_reference;
	typedef	deque_node<value_type>*	link_type;
	typedef ptrdiff_t				difference_type;

	deque_node(const allocator_type& alloc = allocator_type());
	deque_node(const deque_node& other);
	~deque_node();

	deque_node&	operator = (const deque_node& other);

	void	init(void);

	void	add_front(const value_type& val);
	void	add_back(const value_type& val);
	void	remove_front(void);
	void	remove_back(void);

	const static difference_type	_capacity = (sizeof (T) <= 1 ? 16 \
										: sizeof (T) <= 2 ? 8 \
										: sizeof (T) <= 4 ? 4 \
										: sizeof (T) <= 8 ? 2 : 1);

	pointer							_left_border;
	pointer							_left;
	pointer							_right_border;
	pointer							_right;
	link_type						_next;
	link_type						_prev;
	allocator_type					_alloc;
};

template <typename T, typename Allocator>
deque_node<T, Allocator>::deque_node(const allocator_type& alloc) : _left_border(nullptr), _left(nullptr), _right_border(nullptr), _right(nullptr), _next(nullptr), _prev(nullptr), _alloc(alloc) { }

template <typename T, typename Allocator>
deque_node<T, Allocator>::deque_node(const deque_node& other) : _alloc(other._alloc) {
	*this = other;
}

template <typename T, typename Allocator>
deque_node<T, Allocator>::~deque_node() {
	if (!_left_border)
		return ;
	while (_left <= _right)
		std::allocator_traits<allocator_type>::destroy(_alloc, _left++);
	_alloc.deallocate(_left_border, _capacity);
}

template <typename T, typename Allocator>
deque_node<T, Allocator>& deque_node<T, Allocator>::operator = (const deque_node& other) {
	if (!other._left_border)
		return *this;
	_left_border = _alloc.allocate(_capacity);
	_right_border = _left_border + _capacity - 1;
	_left = _left_border + (other._left - other._left_border);
	_right = _left;
	for (difference_type i = 0; other._left + i != other._right; ++i, ++_right)
		std::allocator_traits<allocator_type>::construct(_right, *(other._left + i));
	return *this;
}

template <typename T, typename Allocator>
void deque_node<T, Allocator>::init(void) {
	_left_border = _alloc.allocate(_capacity);
	_right_border = _left_border + _capacity - 1;
}

template <typename T, typename Allocator>
void deque_node<T, Allocator>::add_front(const value_type& val) {
	if (!_left) {
		_left = _right_border;
		_right = _left;
		std::allocator_traits<allocator_type>::construct(_alloc, _left, val);
	}
	else {
		_left--;
		std::allocator_traits<allocator_type>::construct(_alloc, _left, val);
	}
}

template <typename T, typename Allocator>
void deque_node<T, Allocator>::add_back(const value_type& val) {
	if (!_right) {
		_right = _left_border;
		_left = _right;
		std::allocator_traits<allocator_type>::construct(_alloc, _right, val);
	}
	else {
		_right++;
		std::allocator_traits<allocator_type>::construct(_alloc, _right, val);
	}
}

template <typename T, typename Allocator>
void deque_node<T, Allocator>::remove_front(void) {
	std::allocator_traits<allocator_type>::destroy(_alloc, _left);
	if (_left == _right) {
		_left = nullptr;
		_right = nullptr;
	}
	else
		_left++;
}

template <typename T, typename Allocator>
void deque_node<T, Allocator>::remove_back(void) {
	std::allocator_traits<allocator_type>::destroy(_alloc, _right);
	if (_left == _right) {
		_left = nullptr;
		_right = nullptr;
	}
	else
		_right--;
}


template <typename T, typename Node>
class deque_iterator {
public:
	typedef	Node*								iterator;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef	std::ptrdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	deque_iterator(const iterator& base = iterator(), const pointer& elem = pointer(), const iterator& null = iterator());
	deque_iterator(const deque_iterator& other);
	~deque_iterator();

	deque_iterator&	operator = (const deque_iterator& other);

	reference		operator * (void) const;
	pointer			operator -> (void) const;

	deque_iterator	operator ++ (int);
	deque_iterator&	operator ++ (void);
	deque_iterator	operator -- (int);
	deque_iterator&	operator -- (void);
	deque_iterator	operator +	(difference_type diff) const;
	deque_iterator	operator -	(difference_type diff) const;
	deque_iterator&	operator +=	(difference_type diff);
	deque_iterator&	operator -=	(difference_type diff);
	
	const iterator&	base(void) const;
	const pointer&	elem(void) const;
	const iterator&	null(void) const;

	iterator	_base;
	pointer		_elem;
	iterator	_null;
};

template <typename T, typename Node>
deque_iterator<T, Node>::deque_iterator(const iterator& base, const pointer& elem, const iterator& null) : _base(base), _elem(elem), _null(null) { }

template <typename T, typename Node>
deque_iterator<T, Node>::deque_iterator(const deque_iterator& other) : _base(other.base()), _elem(other.elem()), _null(other.null()) { }

template <typename T, typename Node>
deque_iterator<T, Node>::~deque_iterator() { }

template <typename T, typename Node>
deque_iterator<T, Node>& deque_iterator<T, Node>::operator = (const deque_iterator& other) {
	if (*this != other) {
		_base = other.base();
		_elem = other.elem();
		_null = other.null();
	}
	return *this;
}

template <typename T, typename Node>
typename deque_iterator<T, Node>::reference deque_iterator<T, Node>::operator * (void) const {
	return *_elem;
}

template <typename T, typename Node>
typename deque_iterator<T, Node>::pointer deque_iterator<T, Node>::operator -> (void) const {
	return _elem;
}

template <typename T, typename Node>
deque_iterator<T, Node> deque_iterator<T, Node>::operator ++ (int) {
	deque_iterator	copy(*this);

	if (_elem && _elem != _base->_right)
		_elem++;
	else if (_elem && _elem == _base->_right) {
		_base = _base->_next;
		_elem = _base->_left;
	}
	else {
		_base = _base->_next;
		_elem = _base->_left;
	}
	return copy;
}

template <typename T, typename Node>
deque_iterator<T, Node>& deque_iterator<T, Node>::operator ++ (void) {
	if (_elem && _elem != _base->_right)
		_elem++;
	else if (_elem && _elem == _base->_right) {
		_base = _base->_next;
		_elem = _base->_left;
	}
	else {
		_base = _base->_next;
		_elem = _base->_left;
	}
	return *this;
}

template <typename T, typename Node>
deque_iterator<T, Node> deque_iterator<T, Node>::operator -- (int) {
	deque_iterator	copy(*this);

	if (_elem && _elem != _base->_left)
		_elem--;
	else if (_elem && _elem == _base->_left) {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	else {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	return copy;
}

template <typename T, typename Node>
deque_iterator<T, Node>& deque_iterator<T, Node>::operator -- (void) {
	if (_elem && _elem != _base->_left)
		_elem--;
	else if (_elem && _elem == _base->_left) {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	else {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	return *this;
}

template <typename T, typename Node>
deque_iterator<T, Node> deque_iterator<T, Node>::operator +	(difference_type diff) const {
	deque_iterator	copy(*this);
	difference_type	offset = _base->_right - _elem;

	if (offset >= diff)
		copy._elem = _elem + diff;
	else {
		diff -= offset;
		copy._base = copy._base->_next;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			copy._base = copy._base->_next;
			if (_base == _null) {
				copy._elem = nullptr;
				return copy;
			}
		}
		copy._elem = copy._base->_left + diff - 1;
	}
	return copy;
}

template <typename T, typename Node>
deque_iterator<T, Node> deque_iterator<T, Node>::operator -	(difference_type diff) const {
	deque_iterator	copy(*this);
	difference_type	offset = _elem - _base->_left;

	if (offset >= diff)
		copy._elem = _elem - diff;
	else {
		diff -= offset;
		copy._base = copy._base->_prev;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			copy._base = copy._base->_prev;
			if (_base == _null) {
				copy._elem = nullptr;
				return copy;
			}
		}
		copy._elem = copy._base->_right - diff + 1;
	}
	return copy;
}

template <typename T, typename Node>
deque_iterator<T, Node>& deque_iterator<T, Node>::operator +=	(difference_type diff) {
	difference_type	offset = _base->_right - _elem;

	if (offset >= diff)
		_elem = _elem + diff;
	else {
		diff -= offset;
		_base = _base->_next;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			_base = _base->_next;
			if (_base == _null) {
				_elem = nullptr;
				return *this;
			}
		}
		_elem = _base->_left + diff - 1;
	}
	return *this;
}

template <typename T, typename Node>
deque_iterator<T, Node>& deque_iterator<T, Node>::operator -=	(difference_type diff) {
	difference_type	offset = _elem - _base->_left;

	if (offset >= diff)
		_elem = _elem - diff;
	else {
		diff -= offset;
		_base = _base->_prev;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			_base = _base->_prev;
			if (_base == _null) {
				_elem = nullptr;
				return *this;
			}
		}
		_elem = _base->_right - diff + 1;
	}
	return *this;
}

template <typename T, typename Node>
const typename deque_iterator<T, Node>::iterator&	deque_iterator<T, Node>::base(void) const {
	return _base;
}

template <typename T, typename Node>
const typename deque_iterator<T, Node>::pointer&	deque_iterator<T, Node>::elem(void) const {
	return _elem;
}

template <typename T, typename Node>
const typename deque_iterator<T, Node>::iterator&	deque_iterator<T, Node>::null(void) const {
	return _null;
}


template <typename T, typename Node>
class const_deque_iterator {
public:
	typedef	Node*								iterator;
	typedef	T									value_type;
	typedef	T*									pointer;
	typedef	T&									reference;
	typedef	std::ptrdiff_t						difference_type;
	typedef	std::bidirectional_iterator_tag		iterator_category;

	const_deque_iterator(const iterator& base = iterator(), const pointer& elem = pointer(), const iterator& null = iterator());
	const_deque_iterator(const const_deque_iterator& other);
	const_deque_iterator(const deque_iterator<T, Node>& other);
	~const_deque_iterator();

	const_deque_iterator&	operator = (const const_deque_iterator& other);
	const_deque_iterator&	operator = (const deque_iterator<T, Node>& other);

	reference		operator * (void) const;
	pointer			operator -> (void) const;

	const_deque_iterator	operator ++ (int);
	const_deque_iterator&	operator ++ (void);
	const_deque_iterator	operator -- (int);
	const_deque_iterator&	operator -- (void);
	const_deque_iterator	operator +	(difference_type diff) const;
	const_deque_iterator	operator -	(difference_type diff) const;
	const_deque_iterator&	operator +=	(difference_type diff);
	const_deque_iterator&	operator -=	(difference_type diff);
	
	const iterator&	base(void) const;
	const pointer&	elem(void) const;
	const iterator&	null(void) const;

	iterator	_base;
	pointer		_elem;
	iterator	_null;
};

template <typename T, typename Node>
const_deque_iterator<T, Node>::const_deque_iterator(const iterator& base, const pointer& elem, const iterator& null) : _base(base), _elem(elem), _null(null) { }

template <typename T, typename Node>
const_deque_iterator<T, Node>::const_deque_iterator(const const_deque_iterator& other) : _base(other.base()), _elem(other.elem()), _null(other.null()) { }

template <typename T, typename Node>
const_deque_iterator<T, Node>::const_deque_iterator(const deque_iterator<T, Node>& other) : _base(other.base()), _elem(other.elem()), _null(other.null()) { }

template <typename T, typename Node>
const_deque_iterator<T, Node>::~const_deque_iterator() { }

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator = (const const_deque_iterator& other) {
	if (*this != other) {
		_base = other.base();
		_elem = other.elem();
		_null = other.null();
	}
	return *this;
}

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator = (const deque_iterator<T, Node>& other) {
	if (*this != other) {
		_base = other.base();
		_elem = other.elem();
		_null = other.null();
	}
	return *this;
}

template <typename T, typename Node>
typename const_deque_iterator<T, Node>::reference const_deque_iterator<T, Node>::operator * (void) const {
	return *_elem;
}

template <typename T, typename Node>
typename const_deque_iterator<T, Node>::pointer const_deque_iterator<T, Node>::operator -> (void) const {
	return _elem;
}

template <typename T, typename Node>
const_deque_iterator<T, Node> const_deque_iterator<T, Node>::operator ++ (int) {
	const_deque_iterator	copy(*this);

	if (_elem && _elem != _base->_right)
		_elem++;
	else if (_elem && _elem == _base->_right) {
		_base = _base->_next;
		_elem = _base->_left;
	}
	else {
		_base = _base->_next;
		_elem = _base->_left;
	}
	return copy;
}

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator ++ (void) {
	if (_elem && _elem != _base->_right)
		_elem++;
	else if (_elem && _elem == _base->_right) {
		_base = _base->_next;
		_elem = _base->_left;
	}
	else {
		_base = _base->_next;
		_elem = _base->_left;
	}
	return *this;
}

template <typename T, typename Node>
const_deque_iterator<T, Node> const_deque_iterator<T, Node>::operator -- (int) {
	const_deque_iterator	copy(*this);

	if (_elem && _elem != _base->_left)
		_elem--;
	else if (_elem && _elem == _base->_left) {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	else {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	return copy;
}

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator -- (void) {
	if (_elem && _elem != _base->_left)
		_elem--;
	else if (_elem && _elem == _base->_left) {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	else {
		_base = _base->_prev;
		_elem = _base->_right;
	}
	return *this;
}

template <typename T, typename Node>
const_deque_iterator<T, Node> const_deque_iterator<T, Node>::operator +	(difference_type diff) const {
	const_deque_iterator	copy(*this);
	difference_type	offset = _base->_right - _elem;

	if (offset >= diff)
		copy._elem = _elem + diff;
	else {
		diff -= offset;
		copy._base = copy._base->_next;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			copy._base = copy._base->_next;
			if (_base == _null) {
				copy._elem = nullptr;
				return copy;
			}
		}
		copy._elem = copy._base->_left + diff - 1;
	}
	return copy;
}

template <typename T, typename Node>
const_deque_iterator<T, Node> const_deque_iterator<T, Node>::operator -	(difference_type diff) const {
	const_deque_iterator	copy(*this);
	difference_type	offset = _elem - _base->_left;

	if (offset >= diff)
		copy._elem = _elem - diff;
	else {
		diff -= offset;
		copy._base = copy._base->_prev;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			copy._base = copy._base->_prev;
			if (_base == _null) {
				copy._elem = nullptr;
				return copy;
			}
		}
		copy._elem = copy._base->_right - diff + 1;
	}
	return copy;
}

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator +=	(difference_type diff) {
	difference_type	offset = _base->_right - _elem;

	if (offset >= diff)
		_elem = _elem + diff;
	else {
		diff -= offset;
		_base = _base->_next;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			_base = _base->_next;
			if (_base == _null) {
				_elem = nullptr;
				return *this;
			}
		}
		_elem = _base->_left + diff - 1;
	}
	return *this;
}

template <typename T, typename Node>
const_deque_iterator<T, Node>& const_deque_iterator<T, Node>::operator -=	(difference_type diff) {
	difference_type	offset = _elem - _base->_left;

	if (offset >= diff)
		_elem = _elem - diff;
	else {
		diff -= offset;
		_base = _base->_prev;
		while (diff > _base->_capacity) {
			diff -= _base->_capacity;
			_base = _base->_prev;
			if (_base == _null) {
				_elem = nullptr;
				return *this;
			}
		}
		_elem = _base->_right - diff + 1;
	}
	return *this;
}

template <typename T, typename Node>
const typename const_deque_iterator<T, Node>::iterator&	const_deque_iterator<T, Node>::base(void) const {
	return _base;
}

template <typename T, typename Node>
const typename const_deque_iterator<T, Node>::pointer&	const_deque_iterator<T, Node>::elem(void) const {
	return _elem;
}

template <typename T, typename Node>
const typename const_deque_iterator<T, Node>::iterator&	const_deque_iterator<T, Node>::null(void) const {
	return _null;
}


template <typename _T, typename _Node>
bool operator == (const deque_iterator<_T, _Node>& lhs, const deque_iterator<_T, _Node>& rhs) {
	return (lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator != (const deque_iterator<_T, _Node>& lhs, const deque_iterator<_T, _Node>& rhs) {
	return !(lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator == (const const_deque_iterator<_T, _Node>& lhs, const const_deque_iterator<_T, _Node>& rhs) {
	return (lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator != (const const_deque_iterator<_T, _Node>& lhs, const const_deque_iterator<_T, _Node>& rhs) {
	return !(lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator == (const const_deque_iterator<_T, _Node>& lhs, const deque_iterator<_T, _Node>& rhs) {
	return (lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator != (const const_deque_iterator<_T, _Node>& lhs, const deque_iterator<_T, _Node>& rhs) {
	return !(lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator == (const deque_iterator<_T, _Node>& lhs, const const_deque_iterator<_T, _Node>& rhs) {
	return (lhs.elem() == rhs.elem());
}

template <typename _T, typename _Node>
bool operator != (const deque_iterator<_T, _Node>& lhs, const const_deque_iterator<_T, _Node>& rhs) {
	return !(lhs.elem() == rhs.elem());
}


template <typename T, typename Allocator = std::allocator<T> >
class deque {

public:
	typedef T														value_type;

private:
	typedef deque_node<value_type>									node_type;
	typedef deque_node<value_type>*									link_type;

public:
	typedef typename node_type::pointer								pointer;
	typedef typename node_type::const_pointer						const_pointer;
	typedef typename node_type::reference							reference;
	typedef typename node_type::const_reference						const_reference;
	typedef	size_t													size_type;
	typedef	ptrdiff_t												difference_type;
	typedef std::allocator<node_type>								allocator_type;
	typedef deque_iterator<value_type, node_type>					iterator;
	typedef const_deque_iterator<value_type, node_type>				const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

	explicit deque(const allocator_type& alloc = allocator_type());
	explicit deque(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	deque(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	deque(const deque& x);
	~deque();

	deque& operator = (const deque& x);

	iterator					begin(void);
	const_iterator				begin(void) const;
	iterator					end(void);
	const_iterator				end(void) const;
	reverse_iterator			rbegin(void);
	const_reverse_iterator		rbegin(void) const;
	reverse_iterator			rend(void);
	const_reverse_iterator		rend(void) const;

	size_type					size(void) const;
	size_type					max_size(void) const;
	void						resize(size_type n, value_type val = value_type());
	bool						empty(void) const;
	void						shrink_to_fit(void);

	reference					operator [] (size_type n);
	const_reference				operator [] (size_type n) const;
	reference					at(size_type n);
	const_reference				at(size_type n) const;
	reference					front(void);
	const_reference				front(void) const;
	reference					back(void);
	const_reference				back(void) const;

	template <class InputIterator>
	void						assign(InputIterator first, InputIterator last);
	void						assign(size_type n, const value_type& val);
	void						push_back (const value_type& val);
	void						push_front (const value_type& val);
	void						pop_back(void);
	void						pop_front(void);
	template <class InputIterator>
	void						insert(iterator position, InputIterator first, InputIterator last);
	iterator					insert(iterator position, const value_type& val);
    void						insert(iterator position, size_type n, const value_type& val);
	iterator					erase(iterator position);
	iterator					erase(iterator first, iterator last);
	void						swap(deque& x);
	void						clear(void);
	allocator_type				get_allocator(void);

private:
	template <typename _Iterator>
	void						__assign(_Iterator first, _Iterator last, ft::false_type);
	template <typename _Integer>
	void						__assign(_Integer n, const _Integer& val, ft::true_type);

	template <typename _Iterator>
	void						__insert(iterator position, _Iterator first, _Iterator last, ft::false_type);
	template <typename _Integer>
	void						__insert(iterator position, _Integer n, const _Integer& val, ft::true_type);

	void						_node_push_back(void);
	void						_node_push_front(void);
	void						_node_pop_back(void);
	void						_node_pop_front(void);

	size_type			_size;
	link_type			_null;
	allocator_type		_node_alloc;
};

template <typename T, typename Allocator>
deque<T, Allocator>::deque(const allocator_type& alloc) : _size(0), _node_alloc(alloc) {
	_null = _node_alloc.allocate(1);
	std::allocator_traits<allocator_type>::construct(_node_alloc, _null);
	_null->_next = _null;
	_null->_prev = _null;
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(size_type n, const value_type& val, const allocator_type& alloc) : _node_alloc(alloc) {
	_null = _node_alloc.allocate(1);
	std::allocator_traits<allocator_type>::construct(_node_alloc, _null);
	_null->_next = _null;
	_null->_prev = _null;
	assign(n, val);
}

template <typename T, typename Allocator>
template <class InputIterator>
deque<T, Allocator>::deque(InputIterator first, InputIterator last, const allocator_type& alloc) : _node_alloc(alloc) {
	_null = _node_alloc.allocate(1);
	std::allocator_traits<allocator_type>::construct(_node_alloc, _null);
	_null->_next = _null;
	_null->_prev = _null;

	typedef typename ft::is_integral<InputIterator>::type	_Type;
	__assign(first, last, _Type());
}

template <typename T, typename Allocator>
deque<T, Allocator>::deque(const deque& x) {
	_null = _node_alloc.allocate(1);
	std::allocator_traits<allocator_type>::construct(_node_alloc, _null);
	_null->_next = _null;
	_null->_prev = _null;
	__assign(x.begin(), x.end(), ft::false_type());
}

template <typename T, typename Allocator>
deque<T, Allocator>::~deque() {
	clear();
	std::allocator_traits<allocator_type>::destroy(_node_alloc, _null);
	_node_alloc.deallocate(_null, 1);
}

template <typename T, typename Allocator>
deque<T, Allocator>& deque<T, Allocator>::operator = (const deque& x) {
	__assign(x.begin(), x.end(), ft::false_type());
	return *this;
}


template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::begin() {
	return iterator(_null->_next, _null->_next->_left, _null);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_iterator deque<T, Allocator>::begin() const {
	return const_iterator(_null->_next, _null->_next->_left, _null);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::end() {
	return iterator(_null, nullptr, _null);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_iterator deque<T, Allocator>::end() const {
	return const_iterator(_null, nullptr, _null);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rbegin() {
	return reverse_iterator(end());
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::rbegin() const {
	return const_reverse_iterator(end());
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reverse_iterator deque<T, Allocator>::rend() {
	return reverse_iterator(begin());
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reverse_iterator deque<T, Allocator>::rend() const {
	return const_reverse_iterator(begin());
}


template <typename T, typename Allocator>
typename deque<T, Allocator>::size_type deque<T, Allocator>::size() const {
	return _size;
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::size_type deque<T, Allocator>::max_size() const {
	return _node_alloc.max_size() > __LONG_LONG_MAX__ ? __LONG_LONG_MAX__ : _node_alloc.max_size();
}

template <typename T, typename Allocator>
void deque<T, Allocator>::resize(size_type n, value_type val) {
	while (n > _size)
		push_back(val);
	while (n < _size)
		pop_back();
}

template <typename T, typename Allocator>
bool deque<T, Allocator>::empty() const {
	return _size ? false : true;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::shrink_to_fit(void) {
	return ;
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::operator [] (size_type n) {
	link_type		node = _null->_next;
	difference_type	offset = node->_right_border - node->_left;

	if (static_cast<size_type>(offset) >= n)
		return *(node->_left + n);
	n -= offset;
	node = node->_next;
	while (n > node->_capacity) {
		n -= node->_capacity;
		node = node->_next;
	}
	return *(node->_left_border + n - 1);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::operator [] (size_type n) const {
	link_type		node = _null->_next;
	difference_type	offset = node->_right_border - node->_left;

	if (static_cast<size_type>(offset) < n) {
		n -= offset;
		node = node->_next;
	}
	while (n > node->_capacity) {
		n -= node->_capacity;
		node = node->_next;
	}
	return *(node->_left + n);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::at(size_type n) {
	if (n >= _size)
		throw std::out_of_range("deque");
	return operator[](n);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::at(size_type n) const {
	if (n >= _size)
		throw std::out_of_range("deque");
	return operator[](n);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::front() {
	return *(_null->_next->_left);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::front() const {
	return *(_null->_next->_left);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::reference deque<T, Allocator>::back() {
	return *(_null->_prev->_right);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::const_reference deque<T, Allocator>::back() const {
	return *(_null->_prev->_right);
}


template <typename T, typename Allocator>
template <class InputIterator>
void deque<T, Allocator>::assign(InputIterator first, InputIterator last) {
	typedef typename ft::is_integral<InputIterator>::type	_Type;
	__assign(first, last, _Type());
}

template <typename T, typename Allocator>
void deque<T, Allocator>::assign(size_type n, const value_type& val) {
	clear();
	for (size_type i = 0; i < n; ++i)
		push_back(val);
}

template <typename T, typename Allocator>
template <typename _Iterator>
void deque<T, Allocator>::__assign(_Iterator first, _Iterator last, ft::false_type) {
	clear();
	for (; first != last; ++first)
		push_back(*first);
}

template <typename T, typename Allocator>
template <typename _Integer>
void deque<T, Allocator>::__assign(_Integer n, const _Integer& val, ft::true_type) {
	assign(static_cast<size_type>(n), val);
}

template <typename T, typename Allocator>
void deque<T, Allocator>::push_back (const value_type& val) {
	if (_null->_prev == _null || _null->_prev->_right == _null->_prev->_right_border)
		_node_push_back();
	_null->_prev->add_back(val);
	_size++;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::push_front (const value_type& val) {
	if (_null->_next == _null || _null->_next->_left == _null->_next->_left_border)
		_node_push_front();
	_null->_next->add_front(val);
	_size++;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::pop_back() {
	if (_null->_prev != _null) {
		_null->_prev->remove_back();
		_size--;
	}
	if (_null->_prev != _null && !_null->_prev->_right)
		_node_pop_back();
}

template <typename T, typename Allocator>
void deque<T, Allocator>::pop_front() {
	if (_null->_next != _null) {
		_null->_next->remove_front();
		_size--;
	}
	if (_null->_next != _null && !_null->_next->_left)
		_node_pop_front();
}

template <typename T, typename Allocator>
void deque<T, Allocator>::_node_push_back() {
	link_type	ptr = _node_alloc.allocate(1);

	if (ptr) {
		std::allocator_traits<allocator_type>::construct(_node_alloc, ptr);
		_null->_prev->_next = ptr;
		ptr->_prev = _null->_prev;
		ptr->_next = _null;
		_null->_prev = ptr;
		ptr->init();
	}
}

template <typename T, typename Allocator>
void deque<T, Allocator>::_node_push_front() {
	link_type	ptr = _node_alloc.allocate(1);

	if (ptr) {
		std::allocator_traits<allocator_type>::construct(_node_alloc, ptr);
		_null->_next->_prev = ptr;
		ptr->_next = _null->_next;
		ptr->_prev = _null;
		_null->_next = ptr;
		ptr->init();
	}
}

template <typename T, typename Allocator>
void deque<T, Allocator>::_node_pop_back() {
	link_type	ptr = _null->_prev;

	if (ptr != _null) {
		ptr->_prev->_next = _null;
		_null->_prev = ptr->_prev;
		std::allocator_traits<allocator_type>::destroy(_node_alloc, ptr);
		_node_alloc.deallocate(ptr, 1);
	}
}

template <typename T, typename Allocator>
void deque<T, Allocator>::_node_pop_front() {
	link_type	ptr = _null->_next;

	if (ptr != _null) {
		ptr->_next->_prev = _null;
		_null->_next = ptr->_next;
		std::allocator_traits<allocator_type>::destroy(_node_alloc, ptr);
		_node_alloc.deallocate(ptr, 1);
	}
}

template <typename T, typename Allocator>
template <class InputIterator>
void deque<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last) {
	typedef typename ft::is_integral<InputIterator>::type _Type;
	__insert(position, first, last, _Type());
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::insert(iterator position, const value_type& val) {
	iterator	it = end();
	
	push_back(it == position ? val : back());
	if (position == it)
		return (it - 1);
	--it;
	while (it != position) {
		*it = *(it - 1);
		--it;
	}
	*it = val;
	return it;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::insert(iterator position, size_type n, const value_type& val) {
	for (size_type i = 0; i < n; ++i)
		position = insert(position, val);
}

template <typename T, typename Allocator>
template <typename _Iterator>
void deque<T, Allocator>::__insert(iterator position, _Iterator first, _Iterator last, ft::false_type) {
	for (; first != last; ++first)
		position = insert(position, *first);
}

template <typename T, typename Allocator>
template <typename _Integer>
void deque<T, Allocator>::__insert(iterator position, _Integer n, const _Integer& val, ft::true_type) {
	insert(position, static_cast<size_type>(n), val);
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::erase(iterator position) {
	iterator it = position;

	if ((it + 1) == end()) {
		pop_back();
		return end();
	}
	while ((it + 1) != end()) {
		*it = *(it + 1);
		++it;
	}
	pop_back();
	return position;
}

template <typename T, typename Allocator>
typename deque<T, Allocator>::iterator deque<T, Allocator>::erase(iterator first, iterator last) {
	for (; first != last; --last)
		first = erase(first);
	return first;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::swap(deque& x) {
	deque b = x;

	x = *this;
	*this = b;
}

template <typename T, typename Allocator>
void deque<T, Allocator>::clear(void) {
	link_type	buf = _null->_next;

	while (buf != _null) {
		_null->_next = buf->_next;
		std::allocator_traits<allocator_type>::destroy(_node_alloc, buf);
		_node_alloc.deallocate(buf, 1);
		buf = _null->_next;
	}
	_size = 0;
	_null->_next = _null;
	_null->_prev = _null;
}


template <typename T, typename Allocator>
bool operator == (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return true;
	return false;
}

template <typename T, typename Allocator>
bool operator != (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename Allocator>
bool operator < (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, typename Allocator>
bool operator <= (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	return !(rhs < lhs);
}

template <typename T, typename Allocator>
bool operator > (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	return (rhs < lhs);
}

template <typename T, typename Allocator>
bool operator >= (const deque<T, Allocator>& lhs, const deque<T, Allocator>& rhs) {
	return !(lhs < rhs);
}

template <class T, class Allocator>
void swap (deque<T, Allocator>& x, deque<T, Allocator>& y) {
	x.swap(y);
}


} /* FT NAMESPACE */

int main(void) {
	std::ifstream	file;
	ft::deque<int>	deck;
	std::string		s;
	int				n = 0;

	file.open("input.txt", std::ifstream::in);
	while (file) {
		file >> s;

		if (s == "push_front") {
			file >> n;
			deck.push_front(n);
			std::cout << "ok" << std::endl;
		}
		else if (s == "push_back") {
			file >> n;
			deck.push_back(n);
			std::cout << "ok" << std::endl;
		}
		else if (s == "pop_front") {
			if (deck.size()) {
				std::cout << deck.front() << std::endl;
				deck.pop_front();
			}
			else
				std::cout << "error" << std::endl;
		}
		else if (s == "pop_back") {
			if (deck.size()) {
				std::cout << deck.back() << std::endl;
				deck.pop_back();
			}
			else
				std::cout << "error" << std::endl;
		}
		else if (s == "front") {
			if (deck.size())
				std::cout << deck.front() << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (s == "back") {
			if (deck.size())
				std::cout << deck.back() << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (s == "size") {
			std::cout << deck.size() << std::endl;
		}
		else if (s == "clear") {
			deck.clear();
			std::cout << "ok" << std::endl;
		}
		else if (s == "exit") {
			std::cout << "bye" << std::endl;
			return 0;
		}
	}
}