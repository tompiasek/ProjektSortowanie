#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

// sortowanie przez kopcowanie. Należy samodzielnie zaimplementować odpowiedni kopiec, który kopcuje bez użycia dodatkowej pamięci.

template <typename T>
class HeapSort
{
    using it = typename std::vector<T>::iterator;

public:
    void sort(it start, it end)
    {
        /*std::cout << "Before sorting: ";
        for (auto i = start; i != end; i++) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;*/

        size_t size = std::distance(start, end) + 1;
        std::vector<T> heap;
        it temp = start;
        while (temp != end) {
            heap = insert(heap.begin(), heap.end(), *temp);
            temp++;
        }

        /*std::cout << "Heap (after inserting): ";
        for (auto i = heap.begin(); i != heap.end(); i++) {
			std::cout << *i << " ";
		}
        std::cout << std::endl;*/

        temp = std::prev(heap.end());
        T popped;
        while (temp >= heap.begin()) {
            //std::cout << "Popping...\n";
            popped = *heap.begin();
            //std::cout << "Popped: " << popped << '\n';
            //std::cout << "*temp: " << *temp << '\n';
			pop(heap.begin(), (temp+1));
            if (temp != heap.begin()) temp--;
            else break;

            /*std::cout << "Heap (after popping): ";
            for (auto i = heap.begin(); i != heap.end(); i++) {
				std::cout << *i << " ";
			}
            std::cout << std::endl;*/
		}

        /*std::cout << "Heap (after popping): ";
        for (auto i = heap.begin(); i != heap.end(); i++) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;*/

        std::copy(heap.begin(), heap.end(), start);

        /*std::cout << "After sorting: ";
        for (auto i = start; i != end; i++) {
			std::cout << *i << " ";
		}
        std::cout << std::endl;*/
    };

    std::vector<T> insert(it start, it end, const T& val)
    {
        size_t size = std::distance(start, end);

        std::vector<T> temp(size + 1);

        std::copy(start, end, temp.begin());

        it tempStart = temp.begin();
        it tempEnd = std::prev(temp.end());
        *tempEnd = val;
        
        it curr = tempEnd;

        while (curr != tempStart) {
            it parrent = tempStart + (curr - tempStart - 1) / 2;

            if (*curr > *parrent) {
				swap(curr, parrent);
				curr = parrent;
			}
			else break;
        }

        return temp;
	};

    std::vector<T> pop(it start, it end)
    {
        //std::cout << "Popping (inside)...\n";
        if (std::distance(start, end) - 1 < 2) {
			std::vector<T> resVector;
			return resVector;
		}
        T result = *start;
        *start = *std::prev(end);
        *(end - 1) = result;
        /*std::cout << "Swapped, result: " << result << '\n';
        std::cout << "Array after swapping: ";
        for (auto i = start; i != end; i++) {
			std::cout << *i << " ";
		}
        std::cout << std::endl;*/

        size_t size = std::distance(start, end) - 1;
        //std::cout << "Size: " << size << std::endl;
        it curr = start;
        it left;
        it right;
        if (size > 2) {
            left = start + 1;
            right = start + 2;
        }
        else {
            std::vector<T> resVector(std::distance(start, end));
            std::copy(start, end, resVector.begin());
            return resVector;
        }

        while (curr < end && right < std::prev(end) && (*curr < *left || *curr < *right)) {
            //std::cout << "curr: " << *curr << ", left: " << *left << ", right: " << *right << '\n'; //com
            if (*curr > *left && *curr > *right) break;
            if (*left > *right) {
				swap(curr, left);
				curr = left;
			}
            else {
				swap(curr, right);
				curr = right;
			}

            auto dist = std::distance(start, curr);
            if (2*dist < size) {
                left = start + (2 * (std::distance(start, curr) + 1)) - 1;
                right = start + (2 * (std::distance(start, curr) + 1));
            }
            else {
                break;
            }
        }
        //std::cout << "Loop ended, creating result vector...\n";
        std::vector<T> resVector(std::distance(start, end));
        std::copy(start, end, resVector.begin());


        return resVector;
    }


private:

    void swap(it a, it b)
    {
		T temp = *a;
		*a = *b;
		*b = temp;
	};

    
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
