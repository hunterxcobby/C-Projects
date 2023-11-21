### Chapter 8: Asymptotic Notation - Big O, Omega, Theta

**Understanding Asymptotic Notation:**
- **Introduction:** Asymptotic notation describes the upper and lower bounds of an algorithm's growth as input size increases.
- **Big O (O):** Describes the upper bound or worst-case scenario. If an algorithm has a time complexity of O(f(n)), it means its runtime won't grow faster than a constant multiple of f(n).
  - *Example:* O(n^2) indicates a quadratic upper limit.

**Comparing Big O with Omega (Ω) and Theta (Θ):**
- **Omega (Ω):** Describes the lower bound or best-case scenario. If an algorithm has a time complexity of Ω(g(n)), it means its runtime won't grow slower than a constant multiple of g(n).
  - *Example:* Ω(n) implies a linear lower limit.
- **Theta (Θ):** Describes both upper and lower bounds, providing a tight bound on the growth rate.
  - *Example:* Θ(n) indicates a linear tight bound.

**Practical Examples and Analogies:**
- **Race Analogy:** Imagine algorithms as runners in a race. Big O is the slowest runner, Omega is the fastest, and Theta is when the fastest and slowest have similar speeds.

**Common Big O Examples:**
- **O(1):** Constant time complexity, ideal but not always achievable.
- **O(log n):** Logarithmic time complexity, often seen in efficient search algorithms.
- **O(n):** Linear time complexity, common in linear search and iteration.
- **O(n^2):** Quadratic time complexity, seen in some sorting algorithms.

