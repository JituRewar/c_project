# Algorithms & Complexity Guide

This document provides a reference for the searching and sorting algorithms implemented in the **C Learning & DSA Toolkit**.

---

## Algorithm Complexity Summary Table

| Algorithm      | Best Time   | Average Time | Worst Time | Auxiliary Space | Stable? |
| -------------- | ----------- | ------------ | ---------- | --------------- | ------- |
| **Linear Search**  | $O(1)$      | $O(n)$       | $O(n)$     | $O(1)$          | Yes     |
| **Binary Search**  | $O(1)$      | $O(\log n)$  | $O(\log n)$| $O(1)$ (iterative) / $O(\log n)$ (recursive) | Yes |
| **Bubble Sort**    | $O(n)$      | $O(n^2)$     | $O(n^2)$   | $O(1)$          | Yes     |
| **Selection Sort** | $O(n^2)$    | $O(n^2)$     | $O(n^2)$   | $O(1)$          | No      |
| **Insertion Sort** | $O(n)$      | $O(n^2)$     | $O(n^2)$   | $O(1)$          | Yes     |
| **Merge Sort**     | $O(n \log n)$ | $O(n \log n)$| $O(n \log n)$ | $O(n)$       | Yes     |
| **Quick Sort**     | $O(n \log n)$ | $O(n \log n)$| $O(n^2)$   | $O(\log n)$ avg / $O(n)$ worst | No |

> **Note for Students:** Time complexity estimates how the running time grows as the input size $n$ increases. Auxiliary space complexity measures the additional memory used beyond the input itself.

---

## 1. Searching Algorithms

### A. Linear Search (`linear_search`)
* **How it works:** Starts from the first element (index 0) and inspects every element one by one until the target is found or the end of the array is reached.
* **When to use:** Use when the array is **unsorted** or very small.
* **Best Case:** $O(1)$ when the target is at the very first position.
* **Worst Case:** $O(n)$ when the target is at the last position or not present.
* **Code Reference:** [`include/searching.h`](../include/searching.h), [`src/searching.c`](../src/searching.c)

---

### B. Binary Search (`binary_search`, `binary_search_recursive`)
* **How it works:**
  1. Find the middle element `mid = left + (right - left) / 2`.
  2. If `arr[mid] == target`, target is found.
  3. If `arr[mid] < target`, discard the left half and search the right half.
  4. If `arr[mid] > target`, discard the right half and search the left half.
* **Prerequisite:** The array **MUST be sorted**.
* **Why `left + (right - left) / 2`?** Using `(left + right) / 2` can cause integer overflow when `left + right > INT_MAX`.
* **Complexity:** Halving the search space at each step gives $O(\log n)$ comparisons.

---

## 2. Sorting Algorithms

### A. Bubble Sort (`bubble_sort`)
* **Intuition:** Imagine bubbles rising to the surface of water. In each pass, adjacent elements are compared and swapped if they are in wrong order. At the end of pass 1, the largest element "bubbles up" to the end.
* **Optimization:** Our implementation tracks if any swaps occurred. If no elements were swapped during a pass, the array is already sorted, terminating early in $O(n)$ time.
* **Stability:** Stable (equal elements retain their relative positions).

---

### B. Selection Sort (`selection_sort`)
* **Intuition:** Divide the array into a sorted part and an unsorted part. Find the smallest element in the unsorted part and swap it into the first unsorted slot.
* **Characteristics:** Always performs $\frac{n(n-1)}{2}$ comparisons regardless of initial ordering ($O(n^2)$ in all cases). It minimizes the number of swaps ($O(n)$ swaps total).
* **Stability:** Unstable in array form due to long-distance swaps.

---

### C. Insertion Sort (`insertion_sort`)
* **Intuition:** Similar to sorting playing cards in your hand. You pick the next card and slide it into its proper place among the already sorted cards on the left.
* **Best Case:** $O(n)$ when the array is already sorted (only 1 comparison per element, no shifts).
* **When to use:** Excellent for very small arrays ($n \le 20$) or arrays that are already nearly sorted.

---

### D. Merge Sort (`merge_sort`)
* **Intuition:** Divide and Conquer.
  1. **Divide:** Recursively divide the array into two halves until single-element subarrays remain.
  2. **Conquer:** Sort each half recursively.
  3. **Combine:** Merge two sorted halves back together in linear time $O(n)$.
* **Guaranteed Performance:** $O(n \log n)$ time in all cases.
* **Trade-off:** Requires $O(n)$ temporary extra memory.

---

### E. Quick Sort (`quick_sort`)
* **Intuition:** Divide and Conquer using partitioning.
  1. Pick a "pivot" element (our implementation uses the Lomuto partition with the last element as pivot).
  2. Rearrange the array so elements smaller than or equal to pivot are on the left, and larger elements on the right.
  3. Recursively quick-sort the left and right partitions.
* **Average Time:** $O(n \log n)$ with small constant factors (often faster in practice than merge sort).
* **Worst Case:** $O(n^2)$ when the pivot is consistently the smallest or largest element (e.g. already sorted array with naive pivot).

---

## 3. Recommended Student Exercises

1. Trace `merge_sort` by hand with pencil and paper on the array `[38, 27, 43, 3, 9, 82, 10]`.
2. Compare the number of swaps between Bubble Sort and Selection Sort on `[5, 4, 3, 2, 1]`.
3. Try implementing a random pivot or median-of-three pivot for Quick Sort as an open-source enhancement!
