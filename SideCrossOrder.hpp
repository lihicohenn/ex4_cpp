//lihicohen1123@gmail.com
#pragma once 
#include <vector>
#include <algorithm>

using namespace std;

namespace Container {

template <typename T>

class SideCrossOrder {
private:
    vector<T> sorted;
    size_t index;

public:
    // Constructor
    SideCrossOrder(const vector<T>& elements, bool end = false)
    {
        vector<T> temp = elements; // create a copy of the vector to sort him
        sort(temp.begin(), temp.end()); // sort ascending order

        sorted.clear(); // clean the final answer so we can start building it
        size_t left = 0; // left pointer
        size_t right = temp.size() ? temp.size() - 1 : 0; // right pointer- if temp is empty right = 0

        while (left <= right && !temp.empty()) { // as long as there are no elements left and we didn't reach the end of the vector
            if (left == right) {
                    sorted.push_back(temp[left]); // if stay only one element in the middle (when there is an odd number of elements) we add it to the sorted vector
                    break;
                }
                sorted.push_back(temp[left]); // add the smallest 
                sorted.push_back(temp[right]); // add the biggest
                ++left; // move the pointer to the right
                if (right > 0) --right; // if right is bigger than 0, move the pointer to the left
            }
            index = end ? sorted.size() : 0; // set the index to the end if end is true, otherwise set it to 0
        }
    

    // Dereference operator
    const T& operator*() const {
        return sorted.at(index);
    }

    // Pre-increment
    SideCrossOrder& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const SideCrossOrder& other) const {
        return index != other.index;
    }

    bool operator==(const SideCrossOrder& other) const {
        return index == other.index;
    }
    // Begin method
    SideCrossOrder begin() const {
        return SideCrossOrder(sorted, false);
    }

    // End method
    SideCrossOrder end() const {
        return SideCrossOrder(sorted, true);
    }
};

}

