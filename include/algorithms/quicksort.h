//  quicksort
#include <functional>


template <typename T>
class QuickSort
{
    using it = typename std::vector<T>::iterator;

public:
    // Recursive quicksort implementation
	void sort(it start, it end, std::function<int(T, T)> comparator = [](T a, T b) { return a - b; }) {
		if (start < end) {
			//std::cout << "Sorting...\n";
			const it pivot = part(start, end, comparator);

			//std::cout << "Sorting left...\n";
			if(pivot > start) sort(start, pivot - 1, comparator);

			//std::cout << "Sorting right...\n";
			if(pivot < end) sort(pivot + 1, end, comparator);
		}
    }

private:

    // Choose pivot (middle element)
    it choosePivot(it start, it end) {
		//std::cout << "Choosing pivot...\n";
		it mid = start + (end - start) / 2;

		if (*start > *mid) swap(start, mid);
		if (*mid > *end) {
			swap(mid, end);
			if (*start > *mid) swap(start, mid);
		}

		//std::cout << "Pivot: " << *mid << " (pos: " << std::distance(start, mid) << ")\n";
		return mid;
    }

    // Partition the array
    it part(it start, it end, std::function<int(T, T)> comparator) {
		//std::cout << "Partitioning...\n";
		it pivot = choosePivot(start, end);
		T pivotValue = *pivot;
		it target = start;

		swap(pivot, end);
		it pivotTemp = end;

		for (it i = start; i != pivotTemp; i++) {
			if (comparator(*i, pivotValue) < 0) {
				swap(i, target);
				target++;
			}
		}

		swap(pivotTemp, target);
		return target;
	}

    // Swap two elements
	void swap(it a, it b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};
