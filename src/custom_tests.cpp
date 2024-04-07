#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <vector>
#include <ctime>
#include "algorithms/quicksort.h"


std::vector<int> randomData(int size)
{
    srand(time(NULL));
	std::vector<int> *data = new std::vector<int>[size];
	for (int i = 0; i < size; i++)
	{
		data->push_back((rand() % 100000) - 50000);
	}
	return *data;
}


std::vector<int> getTestData()
{
    // return randomData(10000);
    return { 11,102,1,13,25,18,20,7,8,6,103,3,1 }; /// Można modyfikować
}

std::vector<int> getSortedData()
{
    auto data = getTestData();
    std::sort(data.begin(), data.end());
    return data;
}

//TEST_CASE("Name")
//{
//    REQUIRE(false);
//}

TEST_CASE("QuickSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    QuickSort<int> quickSort;
    quickSort.sort(data.begin(), data.end());

    REQUIRE(data == resultData);
}

