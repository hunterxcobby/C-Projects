1. **Sorting Algorithms and Auxiliary Space**:
   - Think of sorting algorithms as different methods for organizing your belongings in your new apartment. Merge Sort might use a separate room to sort everything, like renting auxiliary space, while Insertion Sort and Heap Sort manage to sort everything within the space of your apartment, without needing extra storage. Even though they use different amounts of auxiliary space, their space complexity remains O(n) because they all ultimately require space proportional to the size of the input.

2. **Relation to Time Complexity**:
   - Just as we measure the time it takes to complete an algorithm's operations with time complexity, space complexity measures the space (memory) it needs. For example, creating an array of size n requires O(n) space, while a two-dimensional array of size n*n requires O(n²) space because it has n rows and n columns.

3. **Stack Space in Recursive Calls**:
   - Imagine you're stacking boxes in your apartment. Each recursive call in functions, like the "add" function you provided, adds another box to the stack. Each of these calls takes up actual memory, just like adding physical boxes to your apartment. So, for recursive functions like this, the space complexity is O(n) because it grows linearly with the size of the input.

In summary, space complexity considers both the auxiliary space used by an algorithm and the space taken up by the input, similar to how time complexity considers the number of operations performed. Recursive functions also contribute to space complexity, with each call adding to the memory used, just like stacking boxes in your apartment.

### PS: Check the next file to see example codes