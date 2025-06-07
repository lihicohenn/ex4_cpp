//lihicohen1123@gmail.com
#include "MyContainer.hpp"
#include <iostream>

using namespace std;
using namespace Container;

int main() {
    MyContainer<int> container;

    container.addElement(7);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    cout << "Initial container size: " << container.size() << endl;
    cout << "Container contents: " << container << endl;

    // Ascending Order
    cout << "Ascending Order: ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Descending Order
    cout << "Descending Order: ";
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Side Cross Order
    cout << "Side Cross Order: ";
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse Order
    cout << "Reverse Order: ";
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Original Order
    cout << "Original Order: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Middle-Out Order
    cout << "Middle-Out Order: ";
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // הסרת איבר
    cout << "\nRemoving element 6..." << endl;
    container.removeElement(6);
    cout << "Updated container: " << container << endl;
    cout << "Updated size: " << container.size() << endl;

    // Ascending Order לאחר ההסרה
    cout << "Ascending Order (after removal): ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
