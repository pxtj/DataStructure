//iterator.h
#ifndef ITERATOR_H
#define ITERATOR_H

//五种迭代器类型
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public ::input_iterator_tag {};
struct bidirectional_iterator_tag: public ::forward_iterator_tag {};
struct random_access_iterator_tag: public ::bidirectional_iterator_tag {};

template <typename Category, typename T, typename Distance = ptrdiff_t,
	typename Pointer = T*, typename Reference = T&>
struct Iteraotr {
	typename Category iterator_category;
	typename T value_type;
	typename Distance difference_type;
	typename Pointer pointer;
	typename Reference reference;
};

//萃取特征 iterator_traits
template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

//iterator_traits针对原生指针的特化版本
template <typename T>
struct iterator_traits<T*> {
	typedef ::random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

//iterator_traits针对const 原生指针的特化版本
//如果没有此版本,设想下value_type为const T,此变量类型我们得到了也是无意义的,因为无法赋值
template <typename T>
struct iterator_traits<const T*> {
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

//此函数决定某个迭代器的category
template <typename Iterator>
inline typename iterator_traits<Iterator>::iterator_category
	iterator_category(const Iterator&) {
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
}

//此函数决定某个迭代器的distance_type
template <typename Iterator>
inline typename iterator_traits<Iterator>::difference_type*
	distance_type(Iterator&) {
		return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
}

//此函数决定某个迭代器的value_type
template <typename Iterator>
inline typename iterator_traits<Iterator>::value_type*
	value_type(Iterator&) {
		return static_cast<typename ::iterator_traits<Iterator>::value_type*>(0);
}

#endif
