#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <vector>
#include "algorithms/quicksort.h"


std::vector<int> getTestData()
{
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

    std::cout << "Data: ";
    for (auto i : data)
	{
		std::cout << i << " ";
	}
    QuickSort<int> quickSort;
    std::cout << "\nQuicksort start\n";
    quickSort.sort(data.begin(), data.end());
    std::cout << "\nQuicksort end\n";

    REQUIRE(data == resultData);
}

