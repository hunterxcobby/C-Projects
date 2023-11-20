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

# Let's break down 
tee Insertion Sort algorithm into simpler terms:

**Imagine you have a deck of cards:**
- This deck is your array of numbers, and the goal is to arrange these cards in ascending order (from smallest to largest).

**How Insertion Sort works:**
1. **Start with one card:** You pick the first card and consider it as a sorted pile, even though it's just one card.

2. **Pick the next card:** You take the next card and compare it with the one in the sorted pile.

3. **Insert in the right place:** If the new card is smaller, you insert it before the card in the sorted pile. If it's larger, you leave it where it is.

4. **Repeat:** You keep picking cards, comparing, and inserting until all cards are in the right order.

**In simpler terms:**
- Imagine you have cards in your hand, and you want to arrange them by looking at each card and placing it in the correct spot in your hand.

**Example:**
Let's say your cards are `[5, 2, 9, 1, 5]`.

1. **Start:** You start with the first card, `[5]`, because it's like having one card in your hand.
2. **Next card:** You take the next card, `[2]`, and insert it before or after `[5]`. In this case, it goes before.
   - Your hand: `[2, 5]`.
3. **Next card:** Take `[9]` and insert it in the right place in your hand.
   - Your hand: `[2, 5, 9]`.
4. **Repeat:** Keep doing this until all cards are in order.

**Visual Representation:**
```
Start: [5]
Pick 2: [2, 5]
Pick 9: [2, 5, 9]
...
Final: [1, 2, 5, 5, 9]
```

This is essentially how Insertion Sort works—gradually building a sorted sequence. It's like sorting a hand of cards by repeatedly picking one card at a time and placing it where it belongs in the sorted order.

Insertion Sort is not recommended for large datasets, but its simplicity makes it a good choice for educational purposes and situations where the array is almost sorted.