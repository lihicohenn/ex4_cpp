//lihicohen1123@gmail.com
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
    AscendingOrder(const vector<T>& elements, bool end = false)
        : sorted(elements), index(end ? elements.size() : 0)
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
    AscendingOrder begin() const {
        return AscendingOrder(sorted, false);
    }

    // end method
    AscendingOrder end() const {
        return AscendingOrder(sorted, true);
    }
};

}
