// quicksort

template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        std::cout << "Start: " << *start << " End: " << *(end-1) << std::endl;
        std::cout << "Data: ";
        for (typename std::vector<T>::iterator it = start; it != end; it++) {
			std::cout << *it << " ";
		}
        std::cout << std::endl;
        if (start < end) {
            typename std::vector<T>::iterator pivot = part(start, end);
            std::cout << "Pivot: " << *pivot << std::endl;
            sort(start, pivot);
            sort(pivot + 1, end);
        }
    }
    
private:
    typename std::vector<T>::iterator part(typename std::vector<T>::iterator low, typename std::vector<T>::iterator high)
    {
        std::cout << "Low: " << *low << " High: " << *(high) << std::endl;
        T pivot = *low;
        typename std::vector<T>::iterator i = low;
        typename std::vector<T>::iterator j = high;
        while (i < j) {
            do {
                i++;
            } while (*i <= pivot && i < high);
            do {
                j--;
            } while (*j > pivot && j > low);
            if (i < j) {
                swap(i, j);
            }
        }
        swap(low, j);
        return j;
    }
    void swap(typename std::vector<T>::iterator a, typename std::vector<T>::iterator b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
        std::cout << "Swapped: " << *a << " " << *b << std::endl;
    }
};
