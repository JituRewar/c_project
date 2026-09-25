# C Learning & DSA Toolkit

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Build & Tests](https://img.shields.io/badge/tests-146%20passed-brightgreen.svg)](#testing)
[![C Standard](https://img.shields.io/badge/C-C99-informational.svg)](#getting-started)
[![Good First Issues](https://img.shields.io/badge/PRs-welcome-orange.svg)](CONTRIBUTING.md)

> A beginner-friendly, educational open-source C repository designed for first-year computer science students to master C programming, fundamental data structures, algorithms, and practical Git/GitHub open-source workflows.

---

## 🎯 Why This Project Exists

Learning C programming in your first year of university can sometimes feel isolated to simple, single-file classroom exercises like `hello_world.c` or `lab1.c`. In the real world, software engineering is collaborative, multi-file, and open-source.

**C Learning & DSA Toolkit** bridges this gap:
1. **Learn Clean C & DSA:** Explore clean, documented implementations of essential C utilities, arrays, strings, searching, sorting, and linear data structures (Stack, Queue, Linked List).
2. **Learn Real Open Source:** Practice the entire open-source journey—cloning repositories, exploring existing code, finding issues, writing unit tests, making git commits, opening pull requests, and participating in code reviews.

---

## 📦 Features & Implemented Modules

| Module | Description | Header | Source |
| :--- | :--- | :--- | :--- |
| **Basic C Utilities** | Swap, min/max, factorial (iterative & recursive), prime check, GCD, LCM, Fibonacci, number reverse, palindrome check | [`include/c_utils.h`](include/c_utils.h) | [`src/c_utils.c`](src/c_utils.c) |
| **Array Operations** | Print, min, max, sum, average, reverse, copy, remove duplicates, frequency count, rotate left, merge sorted, two-sum | [`include/array.h`](include/array.h) | [`src/array.c`](src/array.c) |
| **String Utilities** | Length, copy, compare, reverse, palindrome check, vowel/consonant count, word count, lowercase/uppercase, space removal, anagram check | [`include/string_utils.h`](include/string_utils.h) | [`src/string_utils.c`](src/string_utils.c) |
| **Searching** | Linear search, iterative binary search, recursive binary search | [`include/searching.h`](include/searching.h) | [`src/searching.c`](src/searching.c) |
| **Sorting** | Bubble sort, selection sort, insertion sort, merge sort, quick sort | [`include/sorting.h`](include/sorting.h) | [`src/sorting.c`](src/sorting.c) |
| **Stack** | Array-based LIFO stack with push, pop, peek, size, empty/full detection | [`include/stack.h`](include/stack.h) | [`src/stack.c`](src/stack.c) |
| **Queue** | Array-based circular FIFO queue with enqueue, dequeue, front, size | [`include/queue.h`](include/queue.h) | [`src/queue.c`](src/queue.c) |
| **Linked List** | Singly linked list with insert beginning/end, delete by value, search, count, display, memory cleanup | [`include/linked_list.h`](include/linked_list.h) | [`src/linked_list.c`](src/linked_list.c) |

---

## 💡 Quick Code Example

Here is how simple it is to use the toolkit in your own C code:

```c
#include <stdio.h>
#include "array.h"

int main(void) {
    int arr[] = {5, 2, 8, 1, 3};
    int size = 5;

    int max_val = array_max(arr, size);
    int min_val = array_min(arr, size);

    printf("Array: ");
    array_print(arr, size);
    printf("Maximum: %d\n", max_val);
    printf("Minimum: %d\n", min_val);

    return 0;
}
```

---

## 🚀 Getting Started

### 1. Prerequisites
You only need a C compiler (`gcc` or `clang`), `make`, and `git`.

* **Linux (Ubuntu/Debian):** `sudo apt update && sudo apt install build-essential git`
* **macOS:** `xcode-select --install`
* **Windows:** Use WSL (Windows Subsystem for Linux) or MinGW / MSYS2.

### 2. Clone the Repository
```bash
git clone https://github.com/your-username/c-learning-dsa-toolkit.git
cd c-learning-dsa-toolkit
```

### 3. Build & Run
```bash
# Compile the entire project
make

# Run the comprehensive demonstration
make run

# Run all 140+ automated unit tests
make test
```

---

## 📂 Project Structure

This repository follows a clean, realistic standard open-source C layout:

```text
c-learning-dsa-toolkit/
├── README.md                   # Project overview, features, and quickstart
├── LICENSE                     # MIT open-source license
├── CONTRIBUTING.md             # Beginner guide to git, branches, commits, PRs
├── CODE_OF_CONDUCT.md          # Community standards and friendly environment
├── SECURITY.md                 # Security reporting guidelines
├── Makefile                    # Educational build script with make, run, test targets
├── .gitignore                  # Ignore binaries and temporary build objects
│
├── .github/                    # GitHub community templates
│   ├── ISSUE_TEMPLATE/
│   │   ├── bug_report.md       # Template for reporting bugs
│   │   └── feature_request.md  # Template for proposing new features
│   └── pull_request_template.md# Checklist for opening pull requests
│
├── docs/                       # In-depth educational documentation
│   ├── getting-started.md      # Toolchain setup and commands
│   ├── algorithms.md           # Time and space complexity reference table
│   └── contributing.md         # Open-source lifecycle and issue-based learning
│
├── include/                    # Header files (.h) containing function prototypes & docstrings
│   ├── c_utils.h
│   ├── array.h
│   ├── string_utils.h
│   ├── searching.h
│   ├── sorting.h
│   ├── stack.h
│   ├── queue.h
│   └── linked_list.h
│
├── src/                        # Source files (.c) containing function implementations
│   ├── c_utils.c
│   ├── array.c
│   ├── string_utils.c
│   ├── searching.c
│   ├── sorting.c
│   ├── stack.c
│   ├── queue.c
│   └── linked_list.c
│
├── examples/                   # Practical examples demonstrating toolkit usage
│   └── main.c
│
└── tests/                      # Automated unit test suite
    └── test.c
```

---

## 🧪 Testing

Automated testing is fundamental to real-world software engineering. This repository includes a self-contained unit test suite in [`tests/test.c`](tests/test.c).

To run all tests:
```bash
make test
```

Sample output:
```text
==================================================
   C Learning & DSA Toolkit - Test Suite
==================================================

Running c_utils tests...
Running array tests...
Running string_utils tests...
Running searching tests...
Running sorting tests...
Running stack tests...
Running queue tests...
Running linked_list tests...

==================================================
Test Results: 146 executed | 146 PASSED | 0 FAILED
ALL TESTS PASSED!
==================================================
```

---

## 🤝 Contributing

We welcome contributions from students of all experience levels!

Whether you want to:
* Fix a typo or improve documentation
* Add test cases for edge cases
* Implement a new sorting algorithm or data structure
* Improve error handling or function comments

Check out our **[Contributing Guide](CONTRIBUTING.md)** and the **[Issue-Based Learning Guide](docs/contributing.md)** to get started with your first pull request!

---

## 📄 License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute this code for personal, academic, or educational projects.
