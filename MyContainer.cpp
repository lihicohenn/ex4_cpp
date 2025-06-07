//lihicohen1123@gmail.com
#include "MyContainer.hpp"

namespace Container {
    template<typename T>

    void MyContainer<T>::addElement(const T& value) {
        elements.push_back(value);
    }

    template<typename T>
    void MyContainer<T>::removeElement(const T& value) {
        auto it = find(elements.begin(), elements.end(), value);
        if (it != elements.end()) {
            elements.erase(it);
        } else {
            throw std::runtime_error("Element not found");
        }
    }

    template<typename T>
    ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        for (const auto& element : container.elements) {
            os << element << ' ';
        }
        return os;
    }

    template<typename T>
    size_t MyContainer<T>::size() const {
        return elements.size();
    }

    template<typename T>
    AscendingOrder<T> MyContainer<T>::begin_ascending_order() const {
        return AscendingOrder<T>(elements);
    }

    template<typename T>
    AscendingOrder<T> MyContainer<T>::end_ascending_order() const {
        return AscendingOrder<T>(elements, true);
    }

    template<typename T>
    DescendingOrder<T> MyContainer<T>::begin_descending_order() const {
        return DescendingOrder<T>(elements);
    }

    template<typename T>
    DescendingOrder<T> MyContainer<T>::end_descending_order() const {
        return DescendingOrder<T>(elements, true);
    }

    template<typename T>
    SideCrossOrder<T> MyContainer<T>::begin_side_cross_order() const {
        return SideCrossOrder<T>(elements);
    }

    template<typename T>
    SideCrossOrder<T> MyContainer<T>::end_side_cross_order() const {
        return SideCrossOrder<T>(elements, true);
    }

    template<typename T>
    ReverseOrder<T> MyContainer<T>::begin_reverse_order() const {
        return ReverseOrder<T>(elements);
    }

    template<typename T>
    ReverseOrder<T> MyContainer<T>::end_reverse_order() const {
        return ReverseOrder<T>(elements, true);
    }

    template<typename T>
    Order<T> MyContainer<T>::begin_order() const {
        return Order<T>(elements);
    }

    template<typename T>
    Order<T> MyContainer<T>::end_order() const {
        return Order<T>(elements, true);
    }

    template<typename T>
    MiddleOutOrder<T> MyContainer<T>::begin_middle_out_order() const {
        return MiddleOutOrder<T>(elements);
    }

    template<typename T>
    MiddleOutOrder<T> MyContainer<T>::end_middle_out_order() const {
        return MiddleOutOrder<T>(elements, true);
    }

}
template class Container::MyContainer<int>;
template std::ostream& Container::operator<< <int>(std::ostream&, const Container::MyContainer<int>&);