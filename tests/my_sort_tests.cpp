#include "gtest/gtest.h"
#include "my_sort/my_sort.h"

using namespace my_sort;

using std::cout, std::string;

TEST(FirstTest, bubble_int) {
	vector<int> data{0, 2, 1 };
	cout << data;
	stats st = bubble_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}
/*
TEST(SecondTest, insert_int) {
	vector<int> data{ 2, 3, 7, 1, 9, 6, 5, 3, 11, 0, -2 };
	cout << data;
	insert_sort(data.begin(), data.end());
	cout << data;
}
*/
/*
TEST(ThirdTest, quick_sort) {
	vector<int> data{ 2, 3, 6, 1, 9, 7, 5, 3, 11, 0, -2 };
	cout << data;
	size_t copy_count = 0;
	size_t comparison_count = 0;
	stats st = quick_sort(data.begin(), data.end(), copy_count, comparison_count);
	cout << st;
	cout << data;
}*/