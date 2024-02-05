Binary search is a highly efficient search algorithm used to locate a specific element in a sorted collection of data. It works by repeatedly dividing the search interval in half until the target element is found or the interval is empty. Binary search is particularly effective on sorted arrays and offers a significant improvement in efficiency over linear search for large datasets.

Illustration:
Imagine you're searching for a particular word in a dictionary. With binary search, you'd start by opening the dictionary in the middle. If the word you're looking for comes before the current page, you'd repeat the process with the first half of the dictionary; otherwise, you'd search the second half. This process continues until you find the word or narrow down the search interval to an empty range.

Analogies:
1. Finding a word in a sorted book index: Similar to how you'd use the index in a book to quickly locate a chapter, binary search narrows down the search space by half with each iteration, like flipping through pages in a book.

2. Guessing a number in a "higher or lower" game: If you're asked to guess a number between 1 and 100, and each guess is met with "higher" or "lower" feedback, you can efficiently narrow down the possible range with each guess until you find the correct number.

Example Code (in C):
Here's an example of a binary search algorithm in C:

```c
#include <stdio.h>

int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Return index if target is found
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Discard left half
        }
        else {
            high = mid - 1; // Discard right half
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target_value = 5;
    int array_size = sizeof(my_array) / sizeof(my_array[0]);
    
    int index = binary_search(my_array, 0, array_size - 1, target_value);
    
    if (index != -1) {
        printf("Target value %d found at index %d.\n", target_value, index);
    } else {
        printf("Target value %d not found.\n", target_value);
    }
    
    return 0;
}
```

In this C code, the `binary_search` function searches for the `target` value within a sorted array by repeatedly dividing the search interval in half. If the value is found, it returns the index where it's located; otherwise, it returns -1. The `main` function demonstrates how to use the `binary_search` function to find a target value in a sorted array.