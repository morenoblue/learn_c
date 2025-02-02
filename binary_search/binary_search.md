# Binary Search

**Note**: The following description of the binary search algorithms assume a
sorted ascending array of values but the logic can easily be flipped for
descending values. 

## General Theory

The Binary Search algorithm solves the problem of finding an element of value
$t$ within a sorted array $A$, with the following elements:
$A_1,<A_2,<\dots<A_{n-1}$. Conceptually this algorithm is very easy to
comprehend; It's a simple divide and conquer problem. I'm personally not very
good at math but since I am trying to learn how Binary Search properly works, I
tried my best to research what is the math behind it.

Consider that within our array $A$, we know about the existence of the indexes
$L$ and $R$ such that $A_L \leq t \leq A_R$. Furthermore, consider another
arbitrary index $M$ such that $L \lt M \lt R$. Now, $t$ is either to the left
of $A_M$, in other words, $\;t \leq A_M$, or t is to the right of $A_M$, $\;t \ge A_M$.
Since we only care about finding $t$, we can safely ignore the
subarray that $t$ surely doesn't belong to (this is true because $A$ is
sorted):

1. If $\;t \leq A_M$ we can safely ignore: $]A_M, A_R]$ and focus on: $[A_L, A_M]$;
2. If $\;t \leq A_M$ we can safely ignore: $[A_L, A_M[$ and focus on: $[A_M, A_R]$;

Essentially we are reducing the problem from the initial search space $[A_L, A_R]$ to $[A_L, A_M]$ if $\;t \leq A_M$;
 Or from - again - the initial space $[A_L, A_R]$ to $[A_M, A_R]$ if $\;t \ge A_M$.

The more we are able to reduce the search space, the better because a smaller
search space equates to a faster search. So now the question becomes: "How do
we reliably pick an index $M$ that minimizes the search space in the worst case
scenario?". Just to clarify, when I say "worst case scenario" I am talking about those cases were the interval that we choose to focus on, ends up being larger than the ones that we discard. If you think about for a second it is fairly easy to intuitively figure out how to pick the index $M$; Lets consider - for the sake of argument - for a moment that $t$ will always fall on the right side of $M$; 

For example, consider an array $A$ with 10 sorted elements. If we pick $M$ to be a value that is very close to the left side of $A$ - lets say for instance that we pick $M$ to be 2 - then it would mean that the worst case scenario would be if $t$ were to fall on the right of $M$ which means that the search space would reduce from 10 to 8; But can do better? Say we set $M$ to the middle, 5; Now since both subarrays will have the same size, regardless where $t$ falls, in the worst case scenario our search space would reduce from 10 to 5 which is much better than before. What if we were to set $M$ to a value closer to the right instead like 8? Well, in that case the worst case scenario would be if $t$ fell on the left of $M$, in which case the search space would go from 10 to 8 again.

I hope that the above example convinced you that the best and most reliable way to pick $M$ given the requirements established is by picking it to be the index at the middle of the array $M \approx \frac{(L+M)}{2}$ essentially splitting the array into two equal parts. If you are still not convinced, you could get to the same conclusion using math.

First convince yourself that the function below if what we are trying to minimize:

1. $f(M) = \max\{M - L,\, R - M\}$

In other words, what we want is:

2. $M^* = {argmin}_{M} \max\{M - L,\, R - M\}$

To solve this, we can do:

3. $M - L = R - M \quad \Longleftrightarrow$ $\quad2M = L + R \quad \Longleftrightarrow \quad M = \frac{L+R}{2}$

Of course, since M is an index and needs to be an integer is more correct to express that equality as $M \approx \frac{(L+M)}{2}$.

## Implementation

<!-- TODO: Add Implementation information about the 3 different implementations I found more interesting -->
<!-- TODO: Talk about the time and space complexities -->

# Sources

[This website](https://cp-algorithms.com/num_methods/binary_search.html) is really good, It showed me all the math. But according to them their just a translation of [this website](https://e-maxx.ru/).


