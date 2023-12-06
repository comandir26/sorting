#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stack>
using std::vector, std::ostream, std::cout, std::string, std::stack;

namespace my_sort {
	struct Player {
		string name;
		int g_balls;

		Player(string name, int balls) : name(name), g_balls(balls) {}

		bool operator<(Player& rhs) {
			return g_balls < rhs.g_balls;
		}
		bool operator>(Player& rhs) {
			return g_balls > rhs.g_balls;
		}
	};

	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

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
	ostream& operator<<(ostream& os, vector<T>& data) {
		for (size_t i = 0; i < data.size(); i++)
		{
			if (i != 0 && i % 10 == 0) {
				cout << '\n';
			}
			os << data[i] << ' ';
		}
		os << '\n';
		return os;
	}

	ostream& operator<<(ostream& os, stats& st) {
		os << "Number of comparisons: " << st.comparison_count << '\n';
		os << "Number of copies: " << st.copy_count << '\n';
		return os;
	}

	ostream& operator<<(ostream& os, Player& p) {
		os << p.name << ", " << p.g_balls << '\n';
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

	template<typename ForwardIterator, typename T>
	ForwardIterator pivot(ForwardIterator begin, ForwardIterator end, Comp<T>& comp) {
		ForwardIterator pivot = begin;
		ForwardIterator i = begin;
		for (auto j = begin + 1; j <= end - 1; j++) {
			if (comp.less(*j, *pivot)) {
				i++;
				comp.swap(*i, *j);
			}
		}
		comp.swap(*pivot, *i);
		return i;
	}

	template<typename ForwardIterator>
	stats quick_sort(ForwardIterator begin, ForwardIterator end) {
		Comp comp(*begin);
		stack<ForwardIterator> s;
		ForwardIterator last_elem = end - 1;
		s.push(begin);
		s.push(last_elem);
		while (!s.empty()) {
			last_elem = s.top();
			s.pop();
			begin = s.top();
			s.pop();
			ForwardIterator pi = pivot(begin, end, comp);
			if (pi!= begin && pi - 1 > begin ) {
				s.push(begin);
				s.push(pi - 1);
			}
			if (pi + 1 < last_elem) {
				s.push(pi + 1);
				s.push(last_elem);
			}
		}
		return stats{comp.comparison, comp.copy};
	}
}