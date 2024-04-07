#ifndef SORTING_ALGORITHMS_BUBBLESORT_H
#define SORTING_ALGORITHMS_BUBBLESORT_H
#include <vector>

// sortowanie bąbelkowe

template <typename T>
class BubbleSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
		for (auto i = start; i != end; ++i)
		{
			for (auto j = start; j != end - 1; ++j)
			{
				if (*j > *(j + 1))
				{
					auto temp = *j;
					*j = *(j + 1);
					*(j + 1) = temp;
				}
			}
		}
    };
};

#endif //SORTING_ALGORITHMS_BUBBLESORT_H
