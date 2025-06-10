//lihicohen1123@gmail.com
#pragma once
#include <vector>
#include <algorithm>

using namespace std;

namespace Container {

template <typename T>

class ReverseOrder {
private:
    vector<T> sorted;
    size_t index;

public:
    // Constructor
    ReverseOrder(const vector<T>& elements, bool end = false)
    : sorted(elements), index(end ? elements.size() : 0)
    {
    reverse(sorted.begin(), sorted.end()); // just reverse the order, no sorting needed
    }
    
    // Dereference operator
    const T& operator*() const {
        return sorted.at(index);
    }

    // Pre-increment
    ReverseOrder& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const ReverseOrder& other) const {
        return index != other.index;
    }

    // Equality operator
    bool operator==(const ReverseOrder& other) const {
        return index == other.index;
    }
    // Begin method
    ReverseOrder begin() const {
        return ReverseOrder(sorted, false);
    }

    // End method
    ReverseOrder end() const {
        return ReverseOrder(sorted, true);
    }
};

}
