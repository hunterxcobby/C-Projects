# Merge Sort ALgorithm

Merge Sort is another popular sorting algorithm known for its stability and efficiency. It follows the divide-and-conquer strategy to sort an array. Here's an explanation suitable for a beginner:

**Algorithm Steps:**

1. **Divide:** Divide the unsorted array into two halves.
2. **Conquer:** Recursively sort each half.
3. **Merge:** Merge the sorted halves to produce a single sorted array.

**Key Features:**

- **Stability:** Maintains the relative order of equal elements.
- **Predictable Performance:** Always has a time complexity of O(n log n) regardless of the input.
- **Out-of-Place Sorting:** Requires additional memory space proportional to the size of the input.

**Pseudocode:**

```
mergeSort(array):
    if length of array <= 1:
        return array
    
    mid = length of array / 2
    leftHalf = mergeSort(first half of array)
    rightHalf = mergeSort(second half of array)
    
    return merge(leftHalf, rightHalf)

merge(left, right):
    result = empty array
    
    while left is not empty and right is not empty:
        if first element of left <= first element of right:
            append first element of left to result
            remove first element from left
        else:
            append first element of right to result
            remove first element from right
    
    append remaining elements of left and right to result
    
    return result
```

**Example:**

Consider the array `[38, 27, 43, 3, 9, 82, 10]`. After applying Merge Sort:

1. `[38, 27, 43]` and `[3, 9, 82, 10]` are recursively sorted.
2. The two sorted halves are merged into `[3, 9, 10, 27, 38, 43, 82]`.

**Time Complexity:**

- **Worst Case:** O(n log n)
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)

Merge Sort is efficient and widely used, especially when stability is crucial, and additional memory space is not a significant concern.