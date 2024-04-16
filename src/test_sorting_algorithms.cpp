#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <ctime>

#include "algorithms/bubblesort.h"
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/mergesort.h"
#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"

using namespace std::string_literals;

std::vector<int> getTestData()
{
    return {10,-12,-12,0,0,-120,10,10,1,1,13,25,18,20,7,8,6,103,3,1,1,0,1,0,1,5,-1,-1,10}; /// Można modyfikować
}

std::vector<int> getSortedData()
{
    auto data = getTestData();
    std::sort(data.begin(),data.end());
    return data;
}

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

TEST_CASE("BubbleSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    BubbleSort<int> bubbleSort;
    bubbleSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("InsertSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    InsertSort<int> insertSort;
    insertSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("HeapSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    HeapSort<int> heapSort;
    heapSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("MergeSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    MergeSort<int> mergeSort;
    mergeSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("ShellSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    ShellSort<int> shellSort;
    shellSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("QuickSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    QuickSort<int> quickSort;
    quickSort.sort(data.begin(),std::prev(data.end()));

    REQUIRE(data == resultData);
}

TEST_CASE("IntroSort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    IntroSort<int> introSort;
    introSort.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}