//lihicohen1123@gmail.com
#pragma once
#include <vector>
#include <algorithm>

using namespace std;

namespace Container {

template <typename T>

class DescendingOrder {
private:
    vector<T> sorted;
    size_t index;

public:
    // Constructor
    DescendingOrder(const vector<T>& elements, bool end = false)
        : sorted(elements), index(end ? elements.size() : 0)
    {
        sort(sorted.begin(), sorted.end(), [](const T& a, const T& b) {
            return a > b; // descending order
        });
    }

    // Dereference operator
    const T& operator*() const {
        return sorted.at(index);
    }

    // Pre-increment
    DescendingOrder& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const DescendingOrder& other) const {
        return index != other.index;
    }

    // Equality operator
    bool operator==(const DescendingOrder& other) const {
        return index == other.index;
    }

    // Begin method
    DescendingOrder begin() const {
        return DescendingOrder(sorted, false);
    }

    // end method
    DescendingOrder end() const {
        return DescendingOrder(sorted, true);
    }
};

}
