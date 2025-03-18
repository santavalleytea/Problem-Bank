# 📌 COMP2823: Data Structures & Algorithms (Tutorial 2)

A collection of C++ implementations for problems from my 2nd year DS&A class Tutorial 2.

# 📘 Problem Questions

## Question 5.
Using only two stacks, provide an implementation of a queue. Analyze the time complexity of enqueue and dequeue operations.

### Approach

- Initialize two stacks ($s1, s2$) where $s1$ is the main stack for enqueue, and $s2$ is a temporary stack for dequeue.
- For the `enqueue(int val)` function, simply push the value onto the stack.
- For the `dequeue()` function: first we want to check if $s2$ is empty, then we also check if $s1$ is empty, if both are empty then we cannot dequeue.
- Otherwise, if only $s2$ is empty, we move all the elements from $s1$ to $s2$ and then pop the top element in $s2$. By doing so, we remove the element that was pushed first into $s1$.
- Similary, with the `front()` function, we do the same as above except we simply just return the top element rather than removing it.
- Finally, the `isEmpty()` function returns `true` or `false` depending on if both `s1, s2` are empty or not.
