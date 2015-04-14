//construct.h
#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <new>
#include "type_traits.h"
#include "iterator.h"

template <typename T1, typename T2>
inline void construct(T1 *p, const T2 &value) {
	new (p) T1(value);			//placement new ���ʽ
}
//destroy�汾1
template <typename T>
inline void destroy(T *pointer) {
	pointer->~T();				//���������������
}

//destroy�汾2
template <typename ForwardIterator>
inline void destroy(ForwardIterator first, ForwardIterator last) {
	_destroy(first, last, value_type(first));
}

template <typename ForwardIterator, typename T>
inline void _destroy(ForwardIterator first, ForwardIterator last, T*) {
	// _type_traits<T>����ȡ��T��������  1. _false_type  2._true_type
	// ǰ�߱�ʾ��Ҫ�������������߱�ʾ���������������
	typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
	_destroy_aux(first, last, trivial_destructor());
}

template <typename ForwardIterator>
inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __false_type) {
	for( ; first != last; ++first) {
		destroy(&*first);			//���ð汾1��destroy
	}  
}

template <typename ForwardIterator>
inline void _destroy_aux(ForwardIterator first, ForwardIterator last, __true_type) {}

//destroy()���ػ��汾 char * , wchar *
template <>
inline void destroy(char*, char*) {}

template <>
inline void destroy(wchar_t*, wchar_t*) {}

#endif