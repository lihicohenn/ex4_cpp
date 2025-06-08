//lihicohen1123@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace Container;

TEST_CASE("MyContainer - basic functionality") {
    MyContainer<int> container;

    SUBCASE("Adding elements") {
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        CHECK(container.size() == 3);
    }

    SUBCASE("Removing elements") {
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        container.removeElement(10);
        CHECK(container.size() == 2);
    }

    SUBCASE("Removing elements - out of bounds") {
        container.addElement(5);
        container.addElement(10);
        container.removeElement(10);
        container.removeElement(5);
        CHECK_THROWS(container.removeElement(20)); // Trying to remove an element that doesn't exist
    }

    SUBCASE("Removing non-existent element throws exception") {
        container.addElement(5);
        CHECK_THROWS_AS(container.removeElement(10), std::runtime_error);
    }

}

TEST_CASE("MyContainer - Ascending iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_ascending_order();
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(it == container.end_ascending_order());
}

TEST_CASE("MyContainer - Descending iterator") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_descending_order();
    CHECK(*it == 20);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(it == container.end_descending_order());
}

TEST_CASE("MyContainer - Side cross order") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_side_cross_order();
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(it == container.end_side_cross_order());
}

TEST_CASE("MyContainer - Reverse order") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_reverse_order();
    CHECK(*it == 7);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(it == container.end_reverse_order());
}

TEST_CASE("MyContainer - Order") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_order();
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 10);
    ++it;
    CHECK(*it == 20);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 7);
}

TEST_CASE("MyContainer - Middle out order") {
    MyContainer<int> container;
    container.addElement(8);
    container.addElement(10);
    container.addElement(20);
    container.addElement(5);
    container.addElement(7);

    auto it = container.begin_middle_out_order();
    CHECK(*it == 20); 
    ++it; 
    CHECK(*it == 10); 
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 8);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(it == container.end_middle_out_order());
}
TEST_CASE("MyContainer - Ascending order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> ascendingExpected = {1.41, 1.73, 2.71, 3.14};
    std::vector<double> actualAscending;

    for (auto it = cont.begin_ascending_order(); it != cont.end_ascending_order(); ++it) {
        actualAscending.push_back(*it);
    }
    CHECK(actualAscending == ascendingExpected);

    std::vector<double> crossExpected = {1.41, 3.14, 1.73, 2.71};
    std::vector<double> actualCross;

    for (auto it = cont.begin_side_cross_order(); it != cont.end_side_cross_order(); ++it) {
        actualCross.push_back(*it);
    }
    CHECK(actualCross == crossExpected);
}

TEST_CASE("MyContainer - Descending order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> descendingExpected = {3.14, 2.71, 1.73, 1.41};
    std::vector<double> actualDescending;

    for (auto it = cont.begin_descending_order(); it != cont.end_descending_order(); ++it) {
        actualDescending.push_back(*it);
    }
    CHECK(actualDescending == descendingExpected);
}
TEST_CASE("MyContainer - Side Cross Order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> sideCrossExpected = {1.41, 3.14, 1.73, 2.71};
    std::vector<double> actualSideCross;

    for (auto it = cont.begin_side_cross_order(); it != cont.end_side_cross_order(); ++it) {
        actualSideCross.push_back(*it);
    }
    CHECK(actualSideCross == sideCrossExpected);
}

TEST_CASE("MyContainer with std::string values - Ascending and Side Cross Order") {
    Container::MyContainer<std::string> cont;
    cont.addElement("banana");
    cont.addElement("apple");
    cont.addElement("cherry");
    cont.addElement("date");

    std::vector<std::string> ascendingExpected = {"apple", "banana", "cherry", "date"};
    std::vector<std::string> actualAscending;

    for (auto it = cont.begin_ascending_order(); it != cont.end_ascending_order(); ++it) {
        actualAscending.push_back(*it);
    }
    CHECK(actualAscending == ascendingExpected);

    std::vector<std::string> crossExpected = {"apple", "date", "banana", "cherry"};
    std::vector<std::string> actualCross;

    for (auto it = cont.begin_side_cross_order(); it != cont.end_side_cross_order(); ++it) {
        actualCross.push_back(*it);
    }
    CHECK(actualCross == crossExpected);
}