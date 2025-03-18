# 📌 COMP3027: Algorithm Design (Tutorial 2)

A collection of C++ implementations for problems from my 3rd year Algorithm Design class Tutorial 2.

# 📘 Problem Questions

## Question 1.

We have a set of print jobs, where each job $j$ has:
- A **weight** $w_j > 0$ (indicating importance).
- A **processing time**  $t_j$ (indicating how long it takes to complete).

A schedule $\sigma$ is an ordering of jobs that determines their processing sequence. The goal is to **minimize the sum of weighted completion times**, which is given by:

$$
\sum_{j} w_j C^\sigma_j
$$

where $C^\sigma_j$ is the completion time of job $j$ under schedule $\sigma$.

### Greedy Algorithm for Optimal Scheduling

A **greedy algorithm** that minimizes the sum of weighted completion times follows these steps:

1. **Sort** the jobs in **decreasing order of** $\frac{w_j}{t_j}$ (i.e., jobs with higher weight-to-time ratio should be processed first).
2. **Schedule** the jobs in this order.
3. **Compute** the completion times and sum of weighted completion times accordingly.

---

