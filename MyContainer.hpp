//lihicohen1123@gmail.com
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "ReverseOrder.hpp"
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "MiddleOutOrder.hpp"
#include "Order.hpp"

namespace Container {

template<typename T>
class MyContainer;

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container);

template<typename T = int>
class MyContainer {
private:
    std::vector<T> elements;

public:
    MyContainer() = default;
    ~MyContainer() = default;

    void addElement(const T& value);
    void removeElement(const T& value);
    size_t size() const;

    // ✨ שימי לב ל- <>
    friend std::ostream& operator<< <>(std::ostream& os, const MyContainer<T>& container);

    AscendingOrder<T> begin_ascending_order() const;
    AscendingOrder<T> end_ascending_order() const;

    DescendingOrder<T> begin_descending_order() const;
    DescendingOrder<T> end_descending_order() const;

    SideCrossOrder<T> begin_side_cross_order() const;
    SideCrossOrder<T> end_side_cross_order() const;

    ReverseOrder<T> begin_reverse_order() const;
    ReverseOrder<T> end_reverse_order() const;

    Order<T> begin_order() const;
    Order<T> end_order() const;

    MiddleOutOrder<T> begin_middle_out_order() const;
    MiddleOutOrder<T> end_middle_out_order() const;
};

}
