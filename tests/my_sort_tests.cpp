#include "gtest/gtest.h"
#include "my_sort/my_sort.h"
#include <random>
#include <ctime>

using namespace my_sort;
using std::cout, std::string;

/*
TEST(BubbleSort, type_int) {
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75,
						69, 19, 38, 58, 63, 0, 19, 71, 74, 44 };
	cout << data;
	stats st = bubble_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}
TEST(BubbleSort, type_string) {
	vector<string> data{"car", "ball", "world", "coffee", "university", 
						"laptop", "winter", "zip", "allocator", "python"};
	cout << data;
	stats st = bubble_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}
TEST(BubbleSort, type_player) {
	vector<Player> data{Player("Messi", 8), Player("Neymar", 0), Player("Platini", 3), Player("Benzema", 1),
						Player("Ronaldo(Port.)", 5), Player("Cruyff", 3) , Player("Ronaldo(Br.)", 2) , Player("Modric", 1),
						Player("Mbappe", 2) };
	cout << data;
	stats st = bubble_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(QuickSort, type_int) {
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75, 69, 19, 38, 58, 63, 0, 19, 71, 74, 44};
	cout << data;
	stats st = quick_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(QuickSort, type_string) {
	vector<string> data{"car", "ball", "world", "coffee", "university",
						"laptop", "winter", "zip", "allocator", "python"};
	cout << data;
	stats st = quick_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(QuickSort, type_player) {
	vector<Player> data{ Player("Messi", 8), Player("Neymar", 0), Player("Platini", 3), Player("Benzema", 1),
						Player("Ronaldo(Port.)", 5), Player("Cruyff", 3) , Player("Ronaldo(Br.)", 2) , Player("Modric", 1),
						Player("Mbappe", 2) };
	cout << data;
	stats st = quick_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}

TEST(PyramidalSort, type_int) {
	vector<int> data{ 2, 44, 12, 18, 33, 65, 35, 87, 48, 90, 32, 29, 14, 75, 
		69, 19, 38, 58, 63, 0, 19, 71, 74, 44};
	cout << data;
	stats st = pyramidal_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}
TEST(PyramidalSort, type_string) {
	vector<string> data{ "car", "ball", "world", "coffee", "university",
						"laptop", "winter", "zip", "allocator", "python" };
	cout << data;
	stats st = pyramidal_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}
TEST(PyramidalSort, type_player) {
	vector<Player> data{ Player("Messi", 8), Player("Neymar", 0), Player("Platini", 3), Player("Benzema", 1),
						Player("Ronaldo(Port.)", 5), Player("Cruyff", 3), Player("Ronaldo(Br.)", 2) , Player("Modric", 1),
						Player("Mbappe", 0) };
	cout << data;
	stats st = pyramidal_sort(data.begin(), data.end());
	cout << st;
	cout << data;
}


TEST(QuickSort, random) {
	vector<int> sizes{1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<float> comparisons;
	vector<float> copies;
	for (auto size: sizes) {
		size_t size_comparisons = 0;
		size_t size_copies = 0;
		for (size_t i = 0; i < 100; i++)
		{
			std::mt19937 gen(i);
			std::uniform_int_distribution<> distrib(0, 100000);
			vector<int> data;
			for (size_t j = 0; j < size; ++j)
			{
				data.push_back(distrib(gen));
			}
			stats st = quick_sort(data.begin(), data.end());
			size_comparisons += st.comparison_count;
			size_copies += st.copy_count;
		}
		comparisons.push_back(size_comparisons / 100);
		copies.push_back(size_copies / 100);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}

TEST(QuickSort, sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = 0; j < size; ++j)
		{
			data.push_back(j);
		}
		stats st = quick_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}
*/

TEST(QuickSort, rev_sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = size; j != 0; --j)
		{
			data.push_back(j);
		}
		stats st = quick_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}
/*
TEST(PyramidalSort, random) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<float> comparisons;
	vector<float> copies;
	for (int size : sizes) {
		size_t size_comparisons = 0;
		size_t size_copies = 0;
		for (size_t i = 0; i < 100; i++)
		{
			std::mt19937 gen(i);
			std::uniform_int_distribution<> distrib(0, 100000);
			vector<int> data;
			for (size_t j = 0; j < size; ++j)
			{
				data.push_back(distrib(gen));
			}
			stats st = pyramidal_sort(data.begin(), data.end());
			size_comparisons += st.comparison_count;
			size_copies += st.copy_count;
		}
		comparisons.push_back(size_comparisons / 100);
		copies.push_back(size_copies / 100);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}*/
/*
TEST(PyramidalSort, sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = 0; j < size; ++j)
		{
			data.push_back(j);
		}
		stats st = pyramidal_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}

TEST(PyramidalSort, rev_sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = size; j != 0; --j)
		{
			data.push_back(j);
		}
		stats st = pyramidal_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}*/
/*
TEST(BubbleSort, random) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<float> comparisons;
	vector<float> copies;
	for (int size : sizes) {
		size_t size_comparisons = 0;
		size_t size_copies = 0;
		for (size_t i = 0; i < 100; i++)
		{
			std::mt19937 gen(i);
			std::uniform_int_distribution<> distrib(0, 100000);
			vector<int> data;
			for (size_t j = 0; j < size; ++j)
			{
				data.push_back(distrib(gen));
			}
			stats st = bubble_sort(data.begin(), data.end());
			size_comparisons += st.comparison_count;
			size_copies += st.copy_count;
		}
		comparisons.push_back(size_comparisons / 100);
		copies.push_back(size_copies / 100);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}*/
/*
TEST(BubbleSort, sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = 0; j < size; ++j)
		{
			data.push_back(j);
		}
		stats st = bubble_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}*/

TEST(BubbleSort, rev_sorted_data) {
	vector<int> sizes{ 1000, 2000, 3000, 5000, 10000, 25000, 50000, 100000 };
	vector<size_t> comparisons;
	vector<size_t> copies;
	for (int size : sizes) {
		vector<int> data;
		for (int j = size; j != 0; --j)
		{
			data.push_back(j);
		}
		stats st = bubble_sort(data.begin(), data.end());
		comparisons.push_back(st.comparison_count);
		copies.push_back(st.copy_count);
	}
	for (size_t i = 0; i < 8; i++)
	{
		cout << "size: " << sizes[i] << '\n';
		cout << "comparisons: " << comparisons[i] << '\n';
		cout << "copies: " << copies[i] << '\n';
		cout << '\n';
	}
}