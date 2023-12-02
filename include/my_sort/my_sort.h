#pragma once
#include <vector>
#include <iostream>
using std::vector, std::ostream, std::cout;

namespace my_sort {
	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

	/*
	template<typename T>
	void swap(T& l, T& r) {
		T temp = l;
		l = r;
		r = temp;
	}*/

	template<typename T>
	struct Comp {
		size_t copy = 0;
		size_t comparison = 0;
		T value_type;
		Comp(T& value):value_type(value) {}
		bool less(T& l, T& r) {
			comparison++;
			return l < r;
		}
		bool more(T& l, T& r) {
			comparison++;
			return l > r;
		}
		void swap(T& l, T& r) {
			copy++;
			T temp = l;
			l = r;
			r = temp;;
		}
	};

	template<typename T>
	void swp(T& l, T& r) {
		T temp = l;
		l = r;
		r = temp;;
	}

	template<typename T>
	ostream& operator<<(ostream& os, vector<T>& data) {
		for (size_t i = 0; i < data.size(); i++)
		{
			os << data[i] << ' ';
		}
		os << '\n';
		return os;
	}

	ostream& operator<<(ostream& os, stats st) {
		os << "Number of comparisons: " << st.comparison_count << '\n';
		os << "Number of copies: " << st.copy_count << '\n';
		return os;
	}

	template<typename ForwardIterator>
	stats bubble_sort(ForwardIterator begin, ForwardIterator end) {
		Comp comp(*begin);
		ForwardIterator fix_begin = begin;
		for (size_t i = 0; begin != end; begin++, i++)
		{
			bool is_sorted = true;
			for (ForwardIterator j = fix_begin; j != end - (i + 1); j++)
			{
				if (comp.more(*j, *(j + 1))) {
					is_sorted = false;
					comp.swap(*j, *(j + 1));
				}
			}
			if (is_sorted == true) break;
		}
		return stats{ comp.comparison, comp.copy};
	}	
	
	template<typename ForwardIterator, typename T>
	void insert_sort(ForwardIterator begin, ForwardIterator end, Comp<T>& comp) {
		for (ForwardIterator it = begin + 1; it!=end; ++it) {
			for (ForwardIterator init = it; init != begin && comp.less(*init, *(init-1)); --init)
			{
				comp.swap(*init, *(init - 1));
			}
		}
	}

	template<typename ForwardIterator, typename T>
	void qs_vector(ForwardIterator begin, ForwardIterator end, Comp<T>& comp) {
		auto sup_elem = begin;
		auto i = begin + 1;
		auto j = end - 1;
		while (i < j || ((i == j) && (*j < *sup_elem))) {		
			while (comp.less(*i, *sup_elem) && i != end - 1) {
				++i;
			}
			while (comp.more(*j, *sup_elem)) {
				--j;
			}
			if (i < j) {
				comp.swap(*i, *j);
				--j;
			}
			++i;
			for (auto it = begin; it != end; it++) {
				cout << *it << ' ';
			}
			cout << '\n';
		}
		if (comp.more(*sup_elem, *j)) comp.swap(*j, *sup_elem);

		for (auto it = begin; it != end; it++) {
			cout << *it << ' ';
		}
		cout << '\n';

		int left_size = j - begin;

		int right_size = end - begin - left_size - 1;

		cout << "l: " << left_size << " " << "r: " << right_size << '\n';

		if (left_size > 5) {
			qs_vector(begin, begin + left_size, comp);
		}
		else if (left_size > 1) {
			insert_sort(begin, begin + left_size, comp);
		}
		if (right_size > 5) {
			qs_vector(end - right_size, end, comp);
		}
		else if (right_size > 1) {
			insert_sort(end - right_size, end, comp);
		}
	}

	template<typename ForwardIterator>
	stats quick_sort(ForwardIterator begin, ForwardIterator end) {
		Comp comp(*begin);
		qs_vector(begin, end, comp);
		return stats{ comp.comparison, comp.copy };
	}

	template<typename ForwardIterator, typename T>
	void max_heap(ForwardIterator begin, size_t size, ForwardIterator index, Comp<T>& comp) {
		if ((index - begin) * 2 + 1 >= size) return;
		ForwardIterator largest = index;
		ForwardIterator left = begin + (2 * (index - begin) + 1);
		ForwardIterator right = begin + (2 * (index - begin) + 2);

		if (left < (begin + size) && comp.more(*left, *largest)) {
			largest = left;
		}

		if (right < (begin + size) && comp.more(*right, *largest)) {
			largest = right;
		}

		if (largest != index) {
			comp.swap(*index, *largest);
			max_heap(begin, size, largest, comp);
		}	
	}
	
	template<typename ForwardIterator>
	stats pyramidal_sort(ForwardIterator begin, ForwardIterator end) {
		Comp comp(*begin);
		int size = end - begin;
		for (int i = size/2 - 1; i >= 0 ; --i)
		{
			max_heap(begin, size, begin + i, comp);
		}
		for (int i = size - 1; i >= 0; --i)
		{
			comp.swap(*begin, *(begin + i));
			max_heap(begin, i, begin, comp);
		}
		return stats{ comp.comparison, comp.copy };
	}
}