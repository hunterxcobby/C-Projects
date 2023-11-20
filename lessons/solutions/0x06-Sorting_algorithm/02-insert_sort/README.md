# Insertion Sort Algorithm

Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, it has several advantages, making it useful in certain situations:

**Algorithm Steps:**

1. **Start:** Assume the first element is already sorted.
2. **Insertion:** Take the next element and insert it into its proper position among the sorted elements.
3. **Repeat:** Continue this process for each remaining element.

**Key Features:**

- **Efficiency:** Efficient for small datasets or nearly sorted data.
- **Adaptive:** Performs well when dealing with partially sorted arrays.
- **In-Place Sorting:** Requires only a constant amount (O(1)) of additional memory space.
- **Stable Sorting:** Does not change the relative order of equal elements.

**Pseudocode:**

```
for i = 1 to n-1
    key = array[i]
    j = i - 1

    // Move elements of array[0..i-1] that are greater than key to one position ahead of their current position
    while j >= 0 and array[j] > key
        array[j + 1] = array[j]
        j = j - 1
    
    array[j + 1] = key
```

**Example:**

Consider the array `[12, 11, 13, 5, 6]`. The sorted array after each iteration would be:

1. `[11, 12, 13, 5, 6]`
2. `[11, 12, 13, 5, 6]`
3. `[5, 11, 12, 13, 6]`
4. `[5, 6, 11, 12, 13]`

**Time Complexity:**

- **Worst Case:** O(n^2) comparisons and swaps (when the array is sorted in reverse order).
- **Best Case:** O(n) comparisons and O(1) swaps (when the array is already sorted).
- **Average Case:** O(n^2).

Insertion Sort is not recommended for large datasets, but its simplicity makes it a good choice for educational purposes and situations where the array is almost sorted.