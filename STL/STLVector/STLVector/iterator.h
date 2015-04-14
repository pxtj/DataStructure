//iterator.h
#ifndef ITERATOR_H
#define ITERATOR_H

//���ֵ���������
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

//��ȡ���� iterator_traits
template <typename Iterator>
struct iterator_traits {
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

//iterator_traits���ԭ��ָ����ػ��汾
template <typename T>
struct iterator_traits<T*> {
	typedef ::random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

//iterator_traits���const ԭ��ָ����ػ��汾
//���û�д˰汾,������value_typeΪconst T,�˱����������ǵõ���Ҳ���������,��Ϊ�޷���ֵ
template <typename T>
struct iterator_traits<const T*> {
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

//�˺�������ĳ����������category
template <typename Iterator>
inline typename iterator_traits<Iterator>::iterator_category
	iterator_category(const Iterator&) {
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();
}

//�˺�������ĳ����������distance_type
template <typename Iterator>
inline typename iterator_traits<Iterator>::difference_type*
	distance_type(Iterator&) {
		return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
}

//�˺�������ĳ����������value_type
template <typename Iterator>
inline typename iterator_traits<Iterator>::value_type*
	value_type(Iterator&) {
		return static_cast<typename ::iterator_traits<Iterator>::value_type*>(0);
}

#endif
