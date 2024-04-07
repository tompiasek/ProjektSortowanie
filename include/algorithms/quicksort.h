// quicksort

template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        if (start == end) return;
        // Wyświetlanie danych
        /*std::cout << "Start: " << *start << " End: " << *std::prev(end) << std::endl;
        std::cout << "Data: ";
        for (typename std::vector<T>::iterator it = start; it != end; it++) {
			std::cout << *it << " ";
		}
        std::cout << std::endl;*/
        // Działanie algorytmu
        if (start <= end) {
            typename std::vector<T>::iterator pivot = part(start, end);
            sort(start, pivot);
            sort(++start, end);
        }
    }
    
private:
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator low, typename std::vector<T>::iterator high)
    {
        T pivot = *low;
        typename std::vector<T>::iterator i = low;
        typename std::vector<T>::iterator j = std::prev(high);
        while (i < j) {
            while (*i < pivot) {
                if (++i == high) return i;
            }
            while (*j >= pivot) {
                if (--j == low) return i;
            }
            swap(i, j);
            if (++i == j--) return i;
        }
        return i;
    }
    void swap(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
};


template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        while (start != end)
        {
            // Działanie algorytmu
            if (start <= end)
            {
                typename std::vector<T>::iterator pivot = part(start, end);
                sort(start, pivot);
                start = ++pivot;
            }
            else
            {
                --start;
                end = start;
            }
        }
    }

private:
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator low, typename std::vector<T>::iterator high)
    {
        T pivot = *low;
        typename std::vector<T>::iterator i = low;
        typename std::vector<T>::iterator j = std::prev(high);
        while (i < j)
        {
            while (*i < pivot)
            {
                if (++i == high) return i;
            }
            while (*j >= pivot)
            {
                if (--j == low) return i;
            }
            swap(i, j);
            if (++i == j--) return i;
        }
        return i;
    }

    void swap(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
};