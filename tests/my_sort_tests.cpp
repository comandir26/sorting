#include "gtest/gtest.h"
#include "my_sort/my_sort.h"
#include <string>

using namespace my_sort;

using std::cout, std::string;

TEST(FirstTest, bubble_int) {
	//vector<int> data{ 2, 3, 7, 1, 9, 6, 5, 3, 11, 0, -2 };
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75,
		69, 19, 38, 58, 63, 0, 19, 71, 74, 44, 83, 48, 44, 17, 32, 28, 80, 89,
		97, 75, 92, 38, 6, 22, 31, 50, 99, 9, 90, 84, 80, 88, 82, 25, 49, 93 };
	cout << data;
	stats st = bubble_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(SecondTest, quick_sort) {
	//vector<int> data{2, 3, 1, 4, 8, 5, 6, 7};
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75,
		69, 19, 38, 58, 63, 0, 19, 71, 74, 44, 83, 48, 44, 17, 32, 28, 80, 89,
		97, 75, 92, 38, 6, 22, 31, 50, 99, 9, 90, 84, 80, 88, 82, 25, 49, 93 };
	cout << data;
	stats st = quick_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(ThirdTest, pyramidal_sort) {
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75, 
		69, 19, 38, 58, 63, 0, 19, 71, 74, 44, 83, 48, 44, 17, 32, 28, 80, 89, 
		97, 75, 92, 38, 6, 22, 31, 50, 99, 9, 90, 84, 80, 88, 82, 25, 49, 93 };
	cout << data;
	stats st = pyramidal_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

