# Open Source Contribution & Workflow Guide

Welcome! If you are a first-year student or new to Git and open source, this guide is written especially for you.

Contributing to open-source software is one of the best ways to improve your programming skills, build a public portfolio, and learn how real software teams collaborate.

---

## 1. Core Concepts Explained

### What is Git?
**Git** is a Distributed Version Control System that runs locally on your computer. It tracks snapshots (commits) of your project's history so you can undo changes, compare different versions, and branch out without breaking working code.

### What is GitHub?
**GitHub** is a cloud platform that hosts Git repositories online. It provides collaboration tools such as Issues, Pull Requests, Code Reviews, and Discussions.

### What is a Repository ("Repo")?
A repository is the folder containing all project files, history, and branches.

### What is a Fork?
A **fork** is a complete copy of another user's GitHub repository created under your personal GitHub account. Forking allows you to freely experiment and make changes without affecting the original project.

### What is a Branch?
A **branch** is an isolated workspace within a Git repository. Always make your changes on a dedicated branch (e.g., `fix/stack-underflow` or `feature/array-median`) rather than modifying `main` directly.

### What is a Commit?
A **commit** is a saved checkpoint in Git history. It records which lines changed, who changed them, and includes a short descriptive commit message explaining *why* the change was made.

### What is a Pull Request (PR)?
A **Pull Request** is a proposal you submit asking the maintainers of the original project to review and merge your branch into their `main` branch.

### What is a Code Review?
A **Code Review** is a friendly discussion where maintainers and peers review your proposed changes. Reviewers might ask questions, suggest improvements, or approve your code. Feedback is an opportunity to learn, not a test!

---

## 2. The Open Source Contribution Lifecycle

Here is the exact journey every contribution follows:

```text
Find an Issue or Feature
          ↓
Understand the Codebase
          ↓
Reproduce the Problem / Plan the Solution
          ↓
Fork Repository & Clone Locally
          ↓
Create a Feature/Fix Branch
          ↓
Make Code / Doc Changes
          ↓
Build & Run Automated Tests (`make test`)
          ↓
Commit Changes with Clear Message
          ↓
Push Branch to your Fork
          ↓
Open a Pull Request on GitHub
          ↓
Code Review & Discussion
          ↓
Address Feedback (if any)
          ↓
PR Merged 🎉
```

---

## 3. Issue-Based Learning: How to Find Something to Work On

Students often wonder: *"I want to contribute, but where do I start?"*

Here are the primary areas where open-source projects always need help:

1. **Bugs:** Notice unexpected output or edge case crashes? Report or fix it!
2. **Missing Functionality:** A helpful utility or algorithm that isn't yet present.
3. **Documentation Improvements:** Unclear explanations, missing comments, typos, or confusing examples.
4. **Test Improvements:** Additional test cases for boundary values, empty inputs, or large arrays.
5. **Code Cleanup:** Removing dead code, improving variable names, or adhering to coding guidelines.
6. **Edge Cases:** What happens when an array has 0 elements? What if `NULL` is passed?
7. **Performance Improvements:** Making an algorithm use fewer passes or eliminating redundant allocations.

---

## 4. Issue Labels You Will See

In GitHub repositories, issues are tagged with labels to help contributors find suitable tasks:

* `good first issue`: Ideal for beginners; clear scope, minimal prior codebase knowledge needed.
* `bug`: Something is broken, giving wrong answers, or crashing.
* `enhancement`: A request to add new features or improvements.
* `documentation`: Improvements to README, Markdown docs, or code comments.
* `testing`: Adding or improving unit test cases in `tests/test.c`.
* `help wanted`: Tasks where maintainers actively seek community assistance.

---

## 5. Realistic "Good First Issue" Examples

Here are four real-world examples of issues designed for students:

### Issue #1: Clarify Binary Search Behavior on Duplicates
* **Label:** `good first issue`, `documentation`, `testing`
* **Problem:** In [`src/searching.c`](../src/searching.c), when an array contains duplicate target elements (e.g. `[1, 2, 2, 2, 3]`), `binary_search` returns *one* matching index, but not necessarily the *first* or *last*.
* **Task:**
  1. Add a test in [`tests/test.c`](../tests/test.c) demonstrating duplicate searches.
  2. Document this behavior in [`include/searching.h`](../include/searching.h).
  3. (Optional enhancement) Implement `binary_search_first_occurrence`.

---

### Issue #2: Add Array Median or Array Mode Function
* **Label:** `good first issue`, `enhancement`
* **Task:**
  1. Declare `double array_median(int arr[], int size);` in [`include/array.h`](../include/array.h).
  2. Implement the function in [`src/array.c`](../src/array.c) (sorting a copy first).
  3. Add unit tests in [`tests/test.c`](../tests/test.c).
  4. Verify with `make test`.

---

### Issue #3: Add Additional Test Cases for Palindrome Strings
* **Label:** `good first issue`, `testing`
* **Task:**
  1. Open [`tests/test.c`](../tests/test.c).
  2. Add test assertions for edge cases: `"madam"`, `"hello"`, `""` (empty string), `"a"` (single letter), and `"A man a plan a canal Panama"`.
  3. Verify with `make test`.

---

### Issue #4: Improve Error Handling in Stack and Queue Operations
* **Label:** `good first issue`, `enhancement`, `bug`
* **Task:**
  1. Inspect what happens when `stack_push()` is called when the stack is full, or `stack_pop()` when empty.
  2. Ensure consistent boolean return values and document behaviors in [`include/stack.h`](../include/stack.h).
  3. Add boundary tests verifying overflow and underflow behavior.

---

## 6. Contribution Ideas by Skill Level

### Level 1: Easy (Start here!)
* Fix typos or grammatical errors in documentation.
* Add missing edge-case assertions in `tests/test.c` (e.g., negative numbers, empty arrays).
* Add detailed doc-comments to an undocumented function.
* Add a simple utility (e.g., `c_is_odd`, `str_count_digits`).

### Level 2: Medium
* Implement a new array utility (e.g., `array_mode`, `array_is_palindrome`).
* Implement a new string operation (e.g., `str_trim`, `str_find_substring`).
* Add error handling for invalid input pointers across modules.
* Expand the interactive demonstration in `examples/main.c`.

### Level 3: Slightly Advanced
* Implement a new sorting algorithm (e.g., Shell Sort or Counting Sort).
* Add a doubly linked list or a stack implemented using a linked list.
* Implement binary search tree (BST) operations (insert, search, in-order traversal).
* Benchmark sorting algorithms with various array sizes and display timing comparisons.
