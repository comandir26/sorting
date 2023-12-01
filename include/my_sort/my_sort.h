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
		inline static size_t copy = 0;
		inline static size_t comparison = 0;
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
		//size_t copy_count = 0;
		//size_t comparison_count = 0;
		ForwardIterator fix_begin = begin;
		for (size_t i = 0; begin != end; begin++, i++)
		{
			bool is_sorted = true;
			for (ForwardIterator j = fix_begin; j != end - (i + 1); j++)
			{
				//++comparison_count;
				if (comp.more(*j, *(j + 1))) {
					is_sorted = false;
					//++copy_count;
					comp.swap(*j, *(j + 1));
				}
			}
			if (is_sorted == true) break;
		}
		return stats{ comp.comparison, comp.copy};
	}	
	
	template<typename ForwardIterator>
	void insert_sort(ForwardIterator begin, ForwardIterator end, size_t& copy_count, size_t& comparison_count) {
		for (ForwardIterator it = begin + 1; it!=end; ++it) {
			for (ForwardIterator init = it; init != begin && *init < *(init - 1); --init)
			{
				swap(*init, *(init - 1));
			}
		}
	}

	template<typename ForwardIterator>
	stats quick_sort(ForwardIterator begin, ForwardIterator end, size_t& copy_count, size_t& comparison_count) {
		auto sup_elem = begin;
		auto i = begin + 1;
		auto j = end - 1;
		while (i < j || ((i == j) && (*j < *sup_elem)) ) {
			++comparison_count;
			while (*i < *sup_elem && i != end - 1) {				
				++comparison_count;
				++i;
			}
			++comparison_count;
			while (*j > *sup_elem) {
				--j;
			}
			if (i < j) {
				++copy_count;
				swap(*i, *j);
				--j;
			}
			++i;
			for (auto it = begin; it != end; it++) {
				cout << *it << ' ';
			}
			cout << '\n';
		}

		++copy_count;

		if(*sup_elem > *j) swap(*j, *sup_elem);
		
		for (auto it = begin; it != end; it++) {
			cout << *it << ' ';
		}
		cout << '\n';

		int left_size = j - begin;

		int right_size = end - begin - left_size - 1;

		cout << "l: " << left_size << " " << "r: " << right_size << '\n';

		if (left_size > 1) quick_sort(begin, begin + left_size, copy_count, comparison_count);

		if (right_size > 1) quick_sort(end - right_size, end, copy_count, comparison_count);
		
		/*
		if (left_size > 5) {
			quick_sort(begin, begin + left_size, copy_count, comparison_count);
		}
		else if (left_size > 1) {
			insert_sort( vector<T>(data.begin(), data.begin() + left_size) );
		}
		if (right_size > 5) {
			quick_sort( vector<T>(data.begin() + left_size + 1, data.end()) );
		}
		else if (right_size > 1) {
			insert_sort(vector<T>(data.begin() + left_size + 1, data.end()) );
		}
		*/
		return stats{ comparison_count, copy_count };
	}
}