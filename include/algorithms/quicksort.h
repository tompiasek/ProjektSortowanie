//  quicksort


template <typename T>
class QuickSort
{
    using it = typename std::vector<T>::iterator;

public:
    // Recursive quicksort implementation
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        if (start < end) {
			auto q = part(start, end);
            if (q != start) sort(start, q - 1);
            if (q != end) sort(q + 1, end);
		}
    }

private:

    // Choose pivot (middle element)
    typename std::vector<T>::iterator choosePivot(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
    	// return start + (end - start) / 2;

        std::vector<T>::iterator mid = start + (end - start) / 2;
		if (*start > *mid) swap(start, mid);
		if (*start > *end) swap(start, end);
		if (*mid > *end) swap(mid, end);

		return mid;
    }

    // Partition the array
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        auto partIdx = start;
        auto pivot = end;

        for (auto i = start; i < end; i++) {
			if (*i <= *pivot) {
				swap(i, partIdx);
				partIdx++;
			}
		}

        swap(partIdx, pivot);
        return partIdx;
	}

    // Swap two elements
	void swap(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
};
