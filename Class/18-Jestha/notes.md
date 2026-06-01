# Recursion

- Stacks are used in recursion.
- Recursion is a problem-solving technique that solves smaller instances of a problem until a **base case** is reached.
- Stacks are used to store intermediate function calls during recursion.

---

# Problems Discussed

## 1. Factorial Using Recursion

### Algorithm

```text
fact(n)
{
    if (n == 0 || n == 1)   // Base case
        return 1;
    else
        return n * fact(n - 1);   // Recursive case
}
```

### Recursive Tree

```text
fact(5)
│
└── 5 × fact(4)
    │
    └── 4 × fact(3)
        │
        └── 3 × fact(2)
            │
            └── 2 × fact(1)
                │
                └── 1
```

---

## 2. GCD (Greatest Common Divisor) Using Recursion

### Algorithm

```text
GCD(a, b)
{
    if (b == 0)      // Base case
        return a;
    else
        return GCD(b, a % b);
}
```

---

## 3. Nth Fibonacci Term Using Recursion

### Sequence

```text
1, 1, 2, 3, 5, 8, 13, ...
```

### Algorithm

```text
fib(n)
{
    if (n == 1 || n == 2)   // Base case
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
```

### 3.1 Memoization

- Memoization stores intermediate function results in a table/cache.
- It speeds up recursion by avoiding repeated calculations.

---

## 4. Tower of Hanoi

### Problem Statement

- There are three towers: **A, B, and C**.
- There are **n disks** initially placed on tower **A**.
- The goal is to move all disks from **A** to **C**.

### Rules

1. Only one disk can be moved at a time.
2. A smaller disk can never be placed on top of a larger disk.

### Algorithm

```text
TOH(n, src, dst, tmp)
{
    if (n == 1)
        display "Move disk 1 from src to dst";

    else
    {
        TOH(n - 1, src, tmp, dst);
        display "Move disk n from src to dst";
        TOH(n - 1, tmp, dst, src);
    }
}
```
