#pragma once
#include <vector>
#include <algorithm>

using namespace std;

namespace Container {

template <typename T>

class AscendingOrder {
private:
    vector<T> sorted;
    size_t index;

public:
    // Constructor
    AscendingOrder(const MyContainer<T>& container, bool end = false)
        : sorted(container.getElements()), index(end ? container.size() : 0)
    {
        sort(sorted.begin(), sorted.end()); // here we sort the elements in ascending order
    }

    // Dereference operator
    const T& operator*() const {
        return sorted.at(index);
    }

    // Pre-increment
    AscendingOrder& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const AscendingOrder& other) const {
        return index != other.index;
    }

    bool operator==(const AscendingOrder& other) const {
        return index == other.index;
    }
};

}
