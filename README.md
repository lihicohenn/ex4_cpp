// lihicohen1123@gmail.com


## How to Run

To compile and run the demo:
```bash
make demo
```

To compile and run the main:
```bash
make Main
./main_exec
```

To test the project:
```bash
make test
```

To compile and run the tests and main with valgrind:
```bash
make valgrind
```

To clean the build:
```bash
make clean
```

---

## Project Structure

.
├── Makefile
├── Demo.cpp
├── Test.cpp
├── Main.cpp
├── MyContainer.hpp
├── MyContainer.cpp
├── AscendingOrder.hpp
├── DescendingOrder.hpp
├── SideCrossOrder.hpp
├── MiddleOutOrder.hpp
├── ReverseOrder.hpp
├── Order.hpp
├── README.md
└── doctest.h

---

## Description

This project implements a generic templated container class `MyContainer<T>` along with **custom iterator types** that allow different traversal strategies on the container.

It demonstrates concepts of:
- Templates
- Encapsulation
- Iterator patterns
- Dynamic memory management
- Polymorphic iterator logic

---


### MyContainer Class
- `addElement` – Add element to container
- `removeElement` – Remove element
- `size` – Returns number of elements
- `operator<<` – Print all elements in default order

### Iterators:
| Iterator Type         | Behavior Description                                  |
|-----------------------|-------------------------------------------------------|
| `AscendingOrder`      | Sorts and iterates from smallest to largest           |
| `DescendingOrder`     | Sorts and iterates from largest to smallest           |
| `SideCrossOrder`      | Alternates from smallest to largest, like: min,max,.. |
| `ReverseOrder`        | Traverses internal order in reverse                   |
| `Order`               | Traverses in insertion order                          |
| `MiddleOutOrder`      | Starts from middle and alternates left-right          |

---

## Design

- **Encapsulation**: Internal vector is private
- **Template Programming**: Generic container and iterators (`MyContainer<T>`)
- **Friend Functions**: Used for custom `<<` printing

---

## Testing

All functionalities are tested using the `doctest` framework in `Test.cpp`, including:
- Edge cases like removing non-existing elements
- Checking iterator order correctness

Run `make valgrind` to ensure memory safety and proper function of all features.

---

## Future Improvements
- Add support for bidirectional or random-access iterators
- Use STL algorithms with custom iterators
- Exception safety for iterator invalidation

---
