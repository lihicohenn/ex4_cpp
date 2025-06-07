//lihicohen1123@gmail.com
#pragma once
#include <vector>

using namespace std;

namespace Container {

template <typename T>
class Order {
private:
    vector<T> elements;
    size_t index;

public:
    // Constructor
    Order(const vector<T>& elements, bool end = false)
        : elements(elements), index(end ? elements.size() : 0)
    {}

    // Dereference operator
    const T& operator*() const {
        return elements.at(index);
    }

    // Pre-increment
    Order& operator++() {
        ++index;
        return *this;
    }

    // Comparison
    bool operator!=(const Order& other) const {
        return index != other.index;
    }

    bool operator==(const Order& other) const {
        return index == other.index;
    }
    // Begin method
    Order begin() const {
        return Order(elements, false);
    }

    // End method
    Order end() const {
        return Order(elements, true);
    }
};

}