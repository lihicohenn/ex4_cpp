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
TEST_CASE("MyContainer - Reverse order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> reverseExpected = {1.73, 1.41, 2.71, 3.14};
    std::vector<double> actualReverse;

    for (auto it = cont.begin_reverse_order(); it != cont.end_reverse_order(); ++it) {
        actualReverse.push_back(*it);
    }
    CHECK(actualReverse == reverseExpected);
}

TEST_CASE("MyContainer - Middle out order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> middleOutExpected = {1.41,2.71, 1.73, 3.14};
    std::vector<double> actualMiddleOut;

    for (auto it = cont.begin_middle_out_order(); it != cont.end_middle_out_order(); ++it) {
        actualMiddleOut.push_back(*it);
    }
    CHECK(actualMiddleOut == middleOutExpected);
}

TEST_CASE("MyContainer - Order with double values") {
    Container::MyContainer<double> cont;
    cont.addElement(3.14);
    cont.addElement(2.71);
    cont.addElement(1.41);
    cont.addElement(1.73);

    std::vector<double> orderExpected = {3.14, 2.71, 1.41, 1.73};
    std::vector<double> actualOrder;

    for (auto it = cont.begin_order(); it != cont.end_order(); ++it) {
        actualOrder.push_back(*it);
    }
    CHECK(actualOrder == orderExpected);
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

TEST_CASE("MyContainer with std::string values - Descending and Reverse Order") {
    Container::MyContainer<std::string> cont;
    cont.addElement("banana");
    cont.addElement("apple");
    cont.addElement("cherry");
    cont.addElement("date");

    std::vector<std::string> descendingExpected = {"date", "cherry", "banana", "apple"};
    std::vector<std::string> actualDescending;

    for (auto it = cont.begin_descending_order(); it != cont.end_descending_order(); ++it) {
        actualDescending.push_back(*it);
    }
    CHECK(actualDescending == descendingExpected);

    std::vector<std::string> reverseExpected = {"date", "cherry", "apple", "banana"};
    std::vector<std::string> actualReverse;

    for (auto it = cont.begin_reverse_order(); it != cont.end_reverse_order(); ++it) {
        actualReverse.push_back(*it);
    }
    CHECK(actualReverse == reverseExpected);
}

TEST_CASE("MyContainer with std::string values - Middle Out Order") {
    Container::MyContainer<std::string> cont;
    cont.addElement("banana");
    cont.addElement("apple");
    cont.addElement("cherry");
    cont.addElement("date");

    std::vector<std::string> middleOutExpected = {"cherry", "apple", "date", "banana"};
    std::vector<std::string> actualMiddleOut;

    for (auto it = cont.begin_middle_out_order(); it != cont.end_middle_out_order(); ++it) {
        actualMiddleOut.push_back(*it);
    }
    CHECK(actualMiddleOut == middleOutExpected);
}

TEST_CASE("MyConainer with std::string values - Order") {
    Container::MyContainer<std::string> cont;
    cont.addElement("banana");
    cont.addElement("apple");
    cont.addElement("cherry");
    cont.addElement("date");

    std::vector<std::string> orderExpected = {"banana", "apple", "cherry", "date"};
    std::vector<std::string> actualOrder;

    for (auto it = cont.begin_order(); it != cont.end_order(); ++it) {
        actualOrder.push_back(*it);
    }
    CHECK(actualOrder == orderExpected);
}

TEST_CASE("MyContainer - Negative values") {
    MyContainer<int> container;
    container.addElement(-5);
    container.addElement(-10);
    container.addElement(-15);
    container.addElement(-1);
    container.addElement(-2);

    std::vector<int> expectedAscending = {-15, -10, -5, -2, -1};
    std::vector<int> actualAscending;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        actualAscending.push_back(*it);
    }
    CHECK(actualAscending == expectedAscending);

    std::vector<int> expectedDescending = {-1, -2, -5, -10, -15};
    std::vector<int> actualDescending;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        actualDescending.push_back(*it);
    }
    CHECK(actualDescending == expectedDescending);
}
TEST_CASE("MyContainer - Mixed values") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(-1);
    container.addElement(0);
    container.addElement(2);
    container.addElement(-2);

    std::vector<int> expectedAscending = {-2, -1, 0, 2, 3};
    std::vector<int> actualAscending;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        actualAscending.push_back(*it);
    }
    CHECK(actualAscending == expectedAscending);

    std::vector<int> expectedDescending = {3, 2, 0, -1, -2};
    std::vector<int> actualDescending;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        actualDescending.push_back(*it);
    }
    CHECK(actualDescending == expectedDescending);
}

TEST_CASE("MyContainer - One Element Ascending and Descending Order") {
    MyContainer<int> container;
    container.addElement(42);

    std::vector<int> expectedAscending = {42};
    std::vector<int> actualAscending;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        actualAscending.push_back(*it);
    }
    CHECK(actualAscending == expectedAscending);

    std::vector<int> expectedDescending = {42};
    std::vector<int> actualDescending;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        actualDescending.push_back(*it);
    }
    CHECK(actualDescending == expectedDescending);
}

TEST_CASE("MyContainer - One Element Side Cross Order") {
    MyContainer<int> container;
    container.addElement(42);

    std::vector<int> expectedSideCross = {42};
    std::vector<int> actualSideCross;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        actualSideCross.push_back(*it);
    }
    CHECK(actualSideCross == expectedSideCross);
}
TEST_CASE("MyContainer - One Element Reverse Order") {
    MyContainer<int> container;
    container.addElement(42);

    std::vector<int> expectedReverse = {42};
    std::vector<int> actualReverse;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        actualReverse.push_back(*it);
    }
    CHECK(actualReverse == expectedReverse);
}
TEST_CASE("MyContainer - One Element Middle Out Order") {
    MyContainer<int> container;
    container.addElement(42);

    std::vector<int> expectedMiddleOut = {42};
    std::vector<int> actualMiddleOut;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        actualMiddleOut.push_back(*it);
    }
    CHECK(actualMiddleOut == expectedMiddleOut);
}
TEST_CASE("MyContainer - One Element Order") {
    MyContainer<int> container;
    container.addElement(42);

    std::vector<int> expectedOrder = {42};
    std::vector<int> actualOrder;

    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        actualOrder.push_back(*it);
    }
    CHECK(actualOrder == expectedOrder);
}
 TEST_CASE("MyContainer - Empty Container - invalid actions") {
    MyContainer<int> container;

    CHECK(container.size() == 0);

    // Check that iterators for all orders are equal to end
    CHECK(container.begin_ascending_order() == container.end_ascending_order());
    CHECK(container.begin_descending_order() == container.end_descending_order());
    CHECK(container.begin_side_cross_order() == container.end_side_cross_order());
    CHECK(container.begin_reverse_order() == container.end_reverse_order());
    CHECK(container.begin_middle_out_order() == container.end_middle_out_order());
    CHECK(container.begin_order() == container.end_order());

    // Check that removing an element throws an exception
    CHECK_THROWS_AS(container.removeElement(42), std::runtime_error);
}

TEST_CASE("MyContainer - Begin and End methods - Order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    auto begin = container.begin_order();
    auto end = container.end_order();

    CHECK(*begin == 1);
    ++begin;
    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}

TEST_CASE("MyContainer - Begin and End methods - Ascending Order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);

    auto begin = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    CHECK(*begin == 1);
    ++begin;
    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}
TEST_CASE("MyContainer - Begin and End methods - Descending Order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);

    auto begin = container.begin_descending_order();
    auto end = container.end_descending_order();

    CHECK(*begin == 3);
    ++begin;
    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 1);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}
TEST_CASE("MyContainer - Begin and End methods - Side Cross Order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);

    auto begin = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(*begin == 1);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(*begin == 2);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}
TEST_CASE("MyContainer - Begin and End methods - Reverse Order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);

    auto begin = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 1);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}
TEST_CASE("MyContainer - Begin and End methods - Middle Out Order") {
    MyContainer<int> container;
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);

    auto begin = container.begin_middle_out_order();
    auto end = container.end_middle_out_order();

    CHECK(*begin == 1); // Middle element
    ++begin;
    CHECK(*begin == 3); // Next left element
    ++begin;
    CHECK(*begin == 2); // Next right element
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}
TEST_CASE("MyContainer - Begin and End methods - Empty Container") {
    MyContainer<int> container;

    auto begin = container.begin_order();
    auto end = container.end_order();

    CHECK(begin == end); // Check that begin and end are equal for an empty container
}

TEST_CASE("MyContainer - Begin and End methods - Single Element") {
    MyContainer<int> container;
    container.addElement(42);

    auto begin = container.begin_order();
    auto end = container.end_order();

    CHECK(*begin == 42);
    ++begin;
    CHECK(begin == end); // Check that we reached the end
}