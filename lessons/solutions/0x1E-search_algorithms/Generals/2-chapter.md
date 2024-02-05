A linear search is a simple search algorithm that sequentially checks each element in a collection of data until a match is found or the entire collection has been searched. It's like searching for a specific item by checking each item in a list one by one, starting from the beginning. Linear search is straightforward but may not be the most efficient for large datasets.

Illustration:
Imagine you're searching for a specific toy in a box filled with different toys. With a linear search, you'd start by looking at the first toy, then the second, and continue until you find the desired toy or until you've checked every toy in the box.

Analogies:
1. Searching for a name in a phonebook: You'd start from the beginning of the phonebook and go through each entry until you find the desired name.

2. Finding a specific ingredient in a recipe book: You'd flip through each page of the recipe book, checking each ingredient list until you find the one you're looking for.

Example Code (in C):
Here's an example of a linear search algorithm in C:

```c
#include <stdio.h>

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int my_array[] = {3, 6, 2, 8, 1, 9, 5};
    int target_value = 8;
    int array_size = sizeof(my_array) / sizeof(my_array[0]);
    
    int index = linear_search(my_array, array_size, target_value);
    
    if (index != -1) {
        printf("Target value %d found at index %d.\n", target_value, index);
    } else {
        printf("Target value %d not found.\n", target_value);
    }
    
    return 0;
}
```

In this C code, the `linear_search` function iterates through the array to find the `target` value. If the value is found, it returns the index where it's located; otherwise, it returns -1. The `main` function demonstrates how to use the `linear_search` function to find a target value in an array.