//lihicohen1123@gmail.com
#pragma once
#include <vector>

using namespace std;

namespace Container {

template <typename T>
class MiddleOutOrder {
private:
    vector<T> order;
    size_t index;

public:
    // Constructor
    MiddleOutOrder(const vector<T>& elements, bool end = false)
        : index(end ? elements.size() : 0)
    {
        if (elements.empty()) return; // If input is empty, do nothing

        size_t n = elements.size();
        size_t mid = n / 2; // Middle index (rounded down for even n)
        order.push_back(elements[mid]); // Start with the middle element

        size_t left = mid, right = mid;
        bool goLeft = true; // Alternate between left and right

        while (order.size() < n) {
            if (goLeft && left > 0) {
                --left;
                order.push_back(elements[left]); // Add next left element
            } else if (!goLeft && right + 1 < n) {
                ++right;
                order.push_back(elements[right]); // Add next right element
            }
            goLeft = !goLeft; // Alternate direction
        }
    }

    // Dereference operator
    const T& operator*() const {
        return order.at(index);
    }

    // Pre-increment
    MiddleOutOrder& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const MiddleOutOrder& other) const {
        return index != other.index;
    }

    // Equality operator
    bool operator==(const MiddleOutOrder& other) const {
        return index == other.index;
    }
    // Begin method
    MiddleOutOrder begin() const {
        return MiddleOutOrder(order, false);
    }

    // End method
    MiddleOutOrder end() const {
        return MiddleOutOrder(order, true);
    }
};

}
