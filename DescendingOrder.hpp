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
    DescendingOrder(const MyContainer<T>& container, bool end = false)
        : sorted(container.getElements()), index(end ? container.size() : 0)
    {
        sort(sorted.begin(), sorted.end(), greater<T>()); // here we sort the elements in descending order
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

    bool operator==(const DescendingOrder& other) const {
        return index == other.index;
    }
};

}
 