//vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
#include "construct.h"

using std::allocator;

template <typename T, typename Alloc = allocator<T> >
class vector {
public:
	//vector ��Ƕ���ͱ���
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t size_type;
	typedef ptrdiff_t differenct_type;
protected:
	//SGI STL�а�װ��һ��simple_alloc<>
	/*typedef simple_alloc< value_type, Alloc > data_allocator;*/
	Alloc alloc;
	iterator start;
	iterator finish;
	iterator end_of_storage;

	void deallocate() {
		if(start) {
			alloc.deallocate(start, end_of_storage - start);
		}
	}

	void insert_aux(iterator, const T&);
	void fill_initialize(size_type n, const T &value) {
		start = allocate_and_fill(n, value);
		finish = start + n;
		end_of_storage = finish;
	}

	iterator allocate_and_fill(size_type n, const T &x) {
		iterator result = alloc.allocate(n);
		uninitialized_fill_n(result, n, x);
		return result;
	}
public:
	iterator begin() {
		return start;
	}

	iterator end() {
		return finish;
	}

	size_type size() {
		return size_type(end() - begin());
	}

	size_type capacity() {
		return size_type(end_of_storage - begin());
	}

	bool empty() const {
		return begin() == end();
	}

	reference operator[](size_type n) {
		return *(begin() + n);
	}

	//constructor
	vector(): start(0), finish(0), end_of_storage(0) {}
	vector(size_type n, const T &value) {
		fill_initialize(n, value);
	}

	vector(int n, const T &value) {
		fill_initialize(n, value);
	}

	vector(long n, const T &value) {
		fill_initialize(n, value);
	}

	explicit vector(size_type n) {
		fill_initialize(n, T());
	}
	//end of constructor

	~vector() {
		destroy(start, finish);
		deallocate();
	}

	reference front() const {
		return *begin();
	}

	reference back() const {
		return *(end() - 1);
	}

	void push_back(const T &x) {
		if(finish != end_of_storage) {
			construct(finish, x);
			++finish;
		} else {
			insert_aux(end(), x);
		}
	}
	void insert(iterator position, size_type n, const T &x);
	void pop_back() {
		--finish;
		destroy(finish);
	}

	iterator erase(iterator pos) {
		if(pos+1 != end()) {
			copy(pos+1, finish, pos);
		}
		--finish;
		destroy(finish);
		return pos;
	}

	iterator erase(iterator first, iterator last) {
		iterator i = copy(last, finish, first);
		destroy(i, finish);
		finish = finish - (last - first);
		return first;
	}

	void clear() {
		erase(begin(), end());
	}
};

template <typename T, typename Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T &x) {
	if(finish != end_of_storage) {		//���б��ÿռ�
		construct(finish, *(finish-1));
		++finish;
		T x_copy = x;
		copy_backward(position, finish-2, finish-1);
		*position = x_copy;
	} else {							//���ޱ��ÿռ�
		const size_type old_size = size();
		//���ԭ��СΪ0��������1��Ԫ�أ����ԭ��С��Ϊ0��������ԭ��С������
		const size_type len = old_size!=0 ? 2*old_size : 1;

		iterator new_start = alloc.allocate(len);
		iterator new_finish = new_start;

		try {
			//��Դvector�����ݿ�����vector(ǰ��)
			new_finish = uninitialized_copy(start, position, new_start);
			//������Ԫ��
			construct(new_finish, x);
			++new_finish;
			//��������ݿ�����
			new_finish = uninitialized_copy(position, finish, new_finish);
		} catch(...) {
			//commit or rollback
			destroy(new_start, new_finish);
			alloc.deallocate(new_start, len);
			throw;
		}

		//�������ͷ�ԭvector
		destroy(begin(), end());
		deallocate();

		//����������
		start = new_start;
		finish = new_finish;
		end_of_storage = new_start + len;
	}
}

template <typename T, typename Alloc>
void vector<T, Alloc>::insert(iterator position, size_type n, const T &x) {
	if(n != 0) {					//��n!=0ʱ�Ž������²���
		if(size_type(end_of_storage - finish) >= n) {
			//���ÿռ����"����Ԫ�ظ���"
			T x_copy = x;
			//��������֮�������Ԫ�ظ���
			const size_type elems_after = finish - position;
			iterator old_finish = finish;
			if(elems_after > n) {
				//�������Ԫ�ش�������Ԫ�ظ���
				uninitialized_copy(finish - n, finish, finish);
				finish += n;
				copy_backward(position, old_finish - n, old_finish);
				fill(position, position + n, x_copy);
			} else {
				//�������Ԫ��С������Ԫ�ظ���
				uninitialized_fill_n(finish, n - elems_after, x_copy);
				finish += n - elems_after;
				uninitialized_copy(position, old_finish, finish);
				finish += elems_after;
				fill(position, old_finish, x_copy);
			}
		} else {
			//���ÿռ�С��"����Ԫ�ظ���"��Ҫ�������ÿռ�
			const size_type old_size = size();
			//�¿ռ�ĳ��ȡ�2�� or �ɳ��ȼ�����Ԫ�ظ���
			const size_type len = old_size + max(old_size, n);

			iterator new_start = alloc.allocate(len);
			iterator new_finish = new_start;

			//��positionǰ��Ԫ�ؿ������¿ռ�
			new_finish = uninitialized_copy(start, position, new_start);
			//������Ԫ��
			uninitialized_fill_n(new_finish, n, x);
			new_finish += n;
			//��postion���Ԫ�ؿ������¿ռ�
			new_finish = uninitialized_copy(position, finish, new_finish);
			
			//������ͷžɵĿռ�
			destroy(start, finish);
			deallocate();
			//����������
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}
}

#endif
