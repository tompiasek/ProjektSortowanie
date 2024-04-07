 // quicksort

template <typename T>
class QuickSort
{
public:
    // Recursive quicksort implementation
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        if (std::distance(start, end) <= 1)
            return; // Base case: vector size is 0 or 1

        // Choose pivot (preferably middle element)
        typename std::vector<T>::iterator pivot = choosePivot(start, end);

        // Partition the vector
        typename std::vector<T>::iterator bound = part(start, end, pivot);

        // Recursively sort the sub-vectors
        sort(start, bound);
        sort(bound + 1, end);
    }

private:

    // Choose pivot (middle element)
    typename std::vector<T>::iterator choosePivot(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        return std::prev(end, 1); // Choose the last element as pivot
    }

    // Partition the vector
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, typename std::vector<T>::iterator pivot) {
        auto i = start;
        for (auto j = start; j != pivot; ++j) {
            if (*j < *pivot)
                std::swap(*i++, *j);
        }
        std::swap(*i, *pivot);
        return i;
    }
};