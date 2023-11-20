# Quick Sort Algorithm

Quick Sort is a widely used sorting algorithm known for its efficiency and effectiveness. It follows the divide-and-conquer strategy to sort an array. Here's an explanation suitable for a beginner:

**Algorithm Steps:**

1. **Choose Pivot:** Select a pivot element from the array (usually the last element).
2. **Partitioning:** Rearrange the array elements such that elements smaller than the pivot are on the left, and elements larger than the pivot are on the right.
3. **Recursion:** Apply Quick Sort recursively to the left and right sub-arrays.
4. **Combine:** The sorted sub-arrays are combined to produce the final sorted array.

**Key Features:**

- **Efficiency:** One of the fastest sorting algorithms, especially for large datasets.
- **In-Place Sorting:** Requires only a constant amount (O(1)) of additional memory space.
- **Unstable Sorting:** Can change the relative order of equal elements.

**Pseudocode:**

```
quickSort(array, low, high):
    if low < high:
        pivotIndex = partition(array, low, high)
        quickSort(array, low, pivotIndex - 1)
        quickSort(array, pivotIndex + 1, high)

partition(array, low, high):
    pivot = array[high]
    i = low - 1
    
    for j = low to high - 1:
        if array[j] <= pivot:
            i = i + 1
            swap(array[i], array[j])

    swap(array[i + 1], array[high])
    return i + 1
```

**Example:**

Consider the array `[10, 80, 30, 90, 40, 50, 70]`. After the first partitioning with the pivot as 70:

1. `[10, 30, 40, 50, 70, 90, 80]`

Then, the array is recursively partitioned and sorted, resulting in the final sorted array.

**Time Complexity:**

- **Worst Case:** O(n^2) (when the pivot always divides the array into two non-empty sub-arrays).
- **Best Case:** O(n log n) (when the pivot consistently divides the array into balanced sub-arrays).
- **Average Case:** O(n log n).

Quick Sort is often used in practice due to its speed and efficiency, especially for large datasets.
