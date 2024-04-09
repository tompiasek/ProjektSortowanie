#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <vector>
#include <ctime>
#include <chrono>
#include "algorithms/quicksort.h"


std::vector<int> randomData(int size)
{
    srand(time(NULL));
    std::vector<int> data;
	for (int i = 0; i < size; i++)
	{
		data.push_back((rand() % 100000) - 50000);
	}
	return data;
}


std::vector<int> getTestData()
{
    return randomData(500000);
    // return { -1,2,3,9,8,7,4,127,-23,67,0,11,13,11,102,1,13,25,18,20,7,8,6,103,3,1 }; /// Można modyfikować
    //return { 9,2,-3,6,1,10,8,-2,1,2,20,1,0,1,0,10 };
}

std::vector<int> getSortedData(std::vector<int> data) {
    std::sort(data.begin(), data.end());
    return data;
}

std::vector<int> getReversedData(std::vector<int> data) {
	std::sort(data.begin(), data.end(), std::greater<int>());
	return data;
}


// Custom comparison function for arrays
template <typename T>
bool arraysAreEqual(const std::vector<T> arr1, const std::vector<T> arr2) {
    return std::equal(arr1.begin(), arr1.end(), arr2.begin());
}

// Custom failure message for array comparison
template <typename T>
bool requireArraysEqual(const std::vector<T> expected, const std::vector<T> actual) {
    if (!arraysAreEqual(expected, actual)) {
        // Construct a custom message with differing elements
        std::ostringstream msg;
        msg << "Arrays are not equal. Differences:\n";
        for (size_t i = 0; i < expected.size(); ++i) {
            if (expected[i] != actual[i]) {
                msg << "Element at index " << i << ": expected " << expected[i]
                    << ", actual " << actual[i] << "\n";
            }
        }
        FAIL(msg.str()); // Fail the test with custom message
        return false;
    }
    return true;
}

//TEST_CASE("QuickSort")
//{
//	// Initialize variables
//	std::vector<int> data = getTestData();
//
//    std::vector<int> sorted = getSortedData(data);
//	QuickSort<int> quickSort;
//
//	// Sort the data
//	quickSort.sort(data.begin(), std::prev(data.end()));
//
//	// Check if the data is sorted
//	//REQUIRE(requireArraysEqual(sorted, data));
//    REQUIRE(sorted == data);
//}


TEST_CASE("QuickSort 100 TIMES")
{
    // Initialize variables
    int successCount = 0;
    int failCount = 0;

    long time;
    std::chrono::steady_clock::time_point start, end;
    QuickSort<int> quickSort;

    // Run tests
    for(int i = 0; i < 100; i++)
	{
		// Get test data
		auto data = getTestData();
        // auto reversed = getReversedData(data);


        // Sort the data and measure time
        start = std::chrono::high_resolution_clock::now();
		quickSort.sort(data.begin(), std::prev(data.end()));
        end = std::chrono::high_resolution_clock::now();
        if (i > 0) {
            time += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            time /= 2;
        } else {
            time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}
        system("cls");
        std::cout << i + 1 << "%\n";
        std::cout << "Time: " << time << " microseconds\n";

        // Check if the data is sorted
        if (arraysAreEqual(getSortedData(data), data)) {
            ++successCount;
        } else {
            std::cout << "TEST " << i << " FAILED" << std::endl;
			++failCount;
		}
	}

    std::cout << "Average time: " << time << " microseconds" << std::endl;
    
    INFO("Tests passed: " << successCount);
    INFO("Tests failed: " << failCount);

    REQUIRE(failCount == 0);
}

