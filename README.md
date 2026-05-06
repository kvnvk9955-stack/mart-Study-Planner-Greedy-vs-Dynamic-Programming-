# Smart-Study-Planner-Greedy-vs-Dynamic-Programming-

## Overview

The **Smart Study Planner** is an algorithm-based project that compares **Greedy** and **Dynamic Programming (DP)** approaches to optimize study planning. The goal is to efficiently allocate study time across multiple subjects or tasks in order to maximize productivity or learning outcomes.

This project demonstrates how different algorithmic strategies impact decision-making and optimization in real-world scenarios like scheduling and resource allocation.

---

## Objective

* Develop an optimized study planning system
* Compare Greedy and Dynamic Programming approaches
* Analyze efficiency and optimality of both methods
* Demonstrate practical applications of algorithm design

---

## Problem Statement

Students often face difficulty in:

* Managing limited study time
* Prioritizing subjects effectively
* Maximizing output under constraints

This project models the problem as an optimization task and solves it using algorithmic techniques.

---

## Key Concepts

### Greedy Algorithm

* Makes the best local choice at each step
* Faster and simpler to implement
* Works well when local decisions lead to global optimum
* Does not always guarantee optimal solution ([DEV Community][1])

### Dynamic Programming

* Solves problems by breaking them into subproblems
* Stores intermediate results (memoization/tabulation)
* Guarantees optimal solution for complex problems
* Based on optimal substructure and overlapping subproblems ([Informatika ITB][2])

---

## Approach

### Greedy Strategy

* Select tasks based on highest priority or benefit
* Allocate time sequentially
* Focus on immediate best choice

### Dynamic Programming Strategy

* Evaluate all possible combinations of study plans
* Store computed results to avoid recomputation
* Build optimal solution step-by-step

---

## Implementation

### Input

* List of subjects/tasks
* Time required for each subject
* Priority/weight of each subject
* Total available study time

### Processing

* Apply Greedy algorithm to select tasks quickly
* Apply Dynamic Programming for optimal allocation
* Compare outputs of both approaches

### Output

* Selected subjects/tasks
* Total benefit achieved
* Time utilization
* Comparison of results

---

## Comparison: Greedy vs Dynamic Programming

| Feature    | Greedy                 | Dynamic Programming     |
| ---------- | ---------------------- | ----------------------- |
| Approach   | Local optimal choice   | Global optimal solution |
| Complexity | Low                    | Higher                  |
| Speed      | Fast                   | Slower                  |
| Accuracy   | May fail in some cases | Always optimal          |
| Use Case   | Simple problems        | Complex optimization    |

---

## Results

* Greedy approach provides faster results with minimal computation
* Dynamic Programming provides optimal solutions
* In some cases, Greedy may miss better combinations
* DP ensures maximum efficiency in constrained scenarios

---

## Applications

* Study planning and time management
* Task scheduling systems
* Resource allocation problems
* Project planning tools

---

## Advantages

* Demonstrates real-world use of algorithms
* Clear comparison of two major paradigms
* Helps understand when to use Greedy vs DP
* Scalable for similar optimization problems

---

## Limitations

* DP approach can be computationally expensive
* Greedy approach may not always be optimal
* Assumes predefined priorities and time values

---

## Future Enhancements

* Add GUI-based study planner
* Integrate machine learning for priority prediction
* Add real-time scheduling and reminders
* Extend to multi-day or weekly planning

---

## Technologies Used

* Python
* Data Structures and Algorithms
* Greedy Algorithms
* Dynamic Programming

---

## Project Structure

```
├── main.py
├── greedy.py
├── dynamic_programming.py
├── data_input.py
└── README.md
```

---

## Learning Outcomes

* Understanding of Greedy vs Dynamic Programming
* Algorithm design and optimization techniques
* Practical implementation of theoretical concepts
* Performance comparison of different approaches

---

## Conclusion

This project highlights the trade-off between speed and optimality in algorithm design. While Greedy algorithms offer faster solutions, Dynamic Programming ensures accuracy and optimal results. Choosing the right approach depends on the problem structure and constraints.

---

## License

This project is for educational purposes as part of an academic course requirement.
