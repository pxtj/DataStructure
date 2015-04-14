//construct.h
#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <new>
#include "type_traits.h"
#include "iterator.h"

template <typename T1, typename T2>
inline void construct(T1 *p, const T2 &value) {
	new (p) T1(value);			//placement new 表达式
}
//destroy版本1
template <typename T>
inline void destroy(T *pointer) {
	pointer->~T();				//调用类的析构函数
}

//destroy版本2
template <typename ForwardIterator>
inline void destroy(ForwardIterator first, ForwardIterator last) {
	_destroy(first, last, value_type(first));
}

template <typename ForwardIterator, typename T>
inline void _destroy(ForwardIterator first, ForwardIterator last, T*) {
	// _type_traits<T>用于取得T类别的特性  1. _false_type  2._true_type
	// 前者表示需要析构函数　后者表示无意义的析构函数
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	_destroy_aux(first, last, trivial_destructor());
}

template <typename ForwardIterator>
inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __false_type) {
	for( ; first != last; ++first) {
		destroy(&*first);			//调用版本1的destroy
	}  
}

template <typename ForwardIterator>
inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __true_type) {}

//destroy()的特化版本 char * , wchar *
template <>
inline void destroy(char*, char*) {}

template <>
inline void destroy(wchar_t*, wchar_t*) {}

#endif