#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>
#include <iterator>

// sortowanie przez scalanie

template <typename T>
class MergeSort
{
    using it = typename std::vector<T>::iterator;

public:
    void sort(it start, it end)
    {
         auto length = std::distance(start, end);
         if(length < 2) return;

         it mid = start + (end - start) / 2;
         sort(start, mid);
         sort(mid, end);

         auto &&v = merge(start, end);
         std::move(v.cbegin(), v.cend(), start);
    };

private:
    std::vector<T> merge(it start, it end) {
        std::vector<T> result;
        it mid = start + (end - start) / 2;
        it left = start;
        it right = mid;
        const it leftEnd = mid;
        const it rightEnd = end;

        while(left != leftEnd && right != rightEnd) {
			result.push_back((*left <= *right) ? *left++ : *right++);
		}

		result.insert(result.end(), left, leftEnd);
        result.insert(result.end(), right, rightEnd);

        return std::move(result);
    };
};
#endif //SORTING_ALGORITHMS_MERGESORT_H
