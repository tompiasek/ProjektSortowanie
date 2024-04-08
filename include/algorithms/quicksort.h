//  quicksort

template <typename T>
class QuickSort
{
public:
    // Recursive quicksort implementation
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        std::cout << "Sorting...\n";
        std::cout << "Data: ";
        for (auto it = start; it <= end; ++it)
			std::cout << *it << " ";
        std::cout << "\n";

        std::cout << "Distance: " << std::distance(start, end) << "\n";

        if (std::distance(start, end) <= 1) {
            std::cout << "Base case: vector size is 0 or 1\n";
            return; // Base case: vector size is 0 or 1
        }

        std::cout << "Choosing pivot\n";
        // Choose pivot (preferably middle element)
        typename std::vector<T>::iterator pivot = choosePivot(start, end);

        // Partition the vector
        typename std::vector<T>::iterator bound = part(start, end, *pivot);
        std::cout << "Bound: " << *bound << "\n";
        std::cout << "Data after partitioning: ";
        for (auto it = start; it <= end; ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        // Recursively sort the sub-vectors
        std::cout << "Sorting left sub-vector\n";
        sort(start, bound);
        std::cout << "Sorting right sub-vector\n";
        sort(bound + 1, end);
    }

private:

    // Choose pivot (middle element)
    typename std::vector<T>::iterator choosePivot(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        // return std::prev(end, 1); // Choose the last element as pivot

        // Calculate indices for three elements: first, middle, and last
        auto first = start;
        auto middle = start + std::distance(start, end) / 2;
        auto last = end;

        std::cout << "First: " << *first << "; Position: " << std::distance(start, first) + 1 << std::endl;
        std::cout << "Middle: " << *middle << "; Position: " << std::distance(start, middle) + 1 << std::endl;
        std::cout << "Last: " << *last << "; Position: " << std::distance(start, last) + 1 << std::endl;

        // Sort the three elements
        if (*first > *middle)
            swap(*first, *middle);
        if (*middle > *last) {
            swap(*middle, *last);
            if (*first > *middle)
                swap(*first, *middle);
        }

        std::cout << "Data after choosing pivot: ";
        for (auto it = start; it <= end; ++it)
			std::cout << *it << " ";
        std::cout << "\n";

        // Return the middle element as the pivot
        std::cout << "Pivot: " << *middle << "; Position: " << std::distance(start, middle) + 1 << std::endl;
        return middle;
    }

    //// Partition the vector
    //typename std::vector<T>::iterator part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, typename std::vector<T>::iterator pivot) {
    //    auto i = start;
    //    for (auto j = start; j != pivot; ++j) {
    //        if (*j < *pivot)
    //            swap(*i++, *j);
    //    }
    //    swap(*i, *pivot);
    //    return i;
    //}

    // Swap two elements
    void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

    // Partition the vector
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, const T pivot) {
        std::cout << "Partitioning...\n";
        auto i = start;
        auto j = end;
        std::cout << "i: " << *i << "; j: " << *j << "; pivot: " << pivot << "\n";

        while (true) {
            std::cout << "i (before incrementing): " << *i << " (pos: " << std::distance(start, i) + 1 << ")" << std::endl;
            while (*i < pivot) {
                ++i;
                std::cout << "i (after incrementing): " << *i << " (pos: " << std::distance(start, i) + 1 << ")" << std::endl;
            }
            
            std::cout << "j (before decrementing): " << *j << " (pos: " << std::distance(start, j) + 1 << ")" << std::endl;
            while (*j > pivot) {
                --j;
                std::cout << "j (after decrementing): " << *j << " (pos: " << std::distance(start, j) + 1 << ")" << std::endl;
            }

            if (i >= j) {
                std::cout << "Partitioning done\n";
                std::cout << "Returning i: " << *i << " (pos: " << std::distance(start, i) << ")\n";
                return i;
            }
            std::cout << "i before swap: " << *i << " (pos: " << std::distance(start, i) + 1 << "); j before swap: " << *j << "(pos: " << std::distance(start, j) + 1 << ")\n";
            swap(*i, *j);
            std::cout << "i after swap: " << *i << " (pos: " << std::distance(start, i) + 1 << "); j after swap: " << *j << "(pos: " << std::distance(start, j) + 1 << ")\n";
            ++i;
            --j;
        }
    }
};
