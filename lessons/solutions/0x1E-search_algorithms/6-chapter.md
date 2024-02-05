1. **Recursive Function:**

```python
int add(int n){
    if (n <= 0){
        return 0;
    }
    return n + add(n-1);
}
```

- This recursive function has a space complexity of O(n) because each recursive call adds a level to the call stack until the base case is reached.
- For example, calling `add(4)` would result in a call stack with 5 levels (`add(4)`, `add(3)`, `add(2)`, `add(1)`, `add(0)`), requiring O(n) space.

2. **Non-Recursive Function with Loop:**

```python
int addSequence(int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += pairSum(i, i+1);
    }
    return sum;
}

int pairSum(int x, int y){
    return x + y;
}
```

- The `addSequence` function iterates `n` times, calling `pairSum` within each iteration. However, the calls to `pairSum` do not exist simultaneously on the call stack.
- Since the calls to `pairSum` do not stack up recursively, and each call is independent of the others, the space complexity remains constant, O(1), regardless of the value of `n`.

It's essential to note that space complexity can vary depending on factors such as the programming language, compiler optimizations, and the underlying machine architecture, as mentioned in your note.