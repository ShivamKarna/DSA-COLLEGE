import matplotlib.pyplot as plt


x = [10, 100, 1000, 10000, 20000, 100000, 200000]

bubble_sort = [
    2.655e-5,
    9.0449e-5,
    1.87955e-3,
    1.12942e-1,
    5.64069e-1,
    1.6174e1,
    6.547326e1
]

insertion_sort = [
    8.45e-7,
    1.6363e-5,
    5.30263e-4,
    3.25709e-2,
    9.86171e-2,
    1.85394e0,
    6.29461e0
]

selection_sort = [
    5.86e-7,
    1.6062e-5,
    3.87534e-4,
    3.49979e-2,
    9.02373e-1,
    1.86754e0,
    6.274428e0
]


shell_sort = [
    2.378e-6,
    2.7854e-5,
    4.445106e-4,
    2.216492e-3,
    7.56595e-3,
    3.0875561e-2,
    6.9333698e-2
]

merge_sort = [
    1.2086e-5,
    1.4625e-4,
    7.51362e-4,
    2.534649e-3,
    6.317529e-3,
    2.7665229e-2,
    5.7159608e-2
]

quick_sort = [
    2.475e-6,
    8.0742e-5,
    9.11475e-4,
    4.4474876e-3,
    1.2252098e-2,
    5.2433621e-2,
    1.34179137e-1
]

heap_sort = [
    6.598e-6,
    1.53116e-4,
    1.424461e-3,
    5.922564e-3,
    1.3193229e-2,
    7.3031782e-2,
    1.5652162e-1,
]

radix_sort = [
    1.00053e-5,
    4.6459e-5,
    3.37859e-4,
    3.14463e-3,
    2.261352e-3,
    1.0004974e-2,
    2.0776202e-2
]

plt.figure(figsize=(10, 6))
plt.plot(x, bubble_sort, label="Bubble Sort", marker="o")
plt.plot(x, selection_sort, label="Selection Sort", marker="s")
plt.plot(x, insertion_sort, label="Insertion Sort", marker="^")
plt.plot(x, shell_sort, label="Shell Sort", marker="d")
plt.plot(x, merge_sort, label="Merge Sort", marker="v")
plt.plot(x, quick_sort, label="Quick Sort", marker="<")
plt.plot(x, heap_sort, label="Heap Sort", marker=">")
plt.plot(x, radix_sort, label="Radix Sort", marker="x")

plt.title("Sorting Algorithms Performance")
plt.xlabel("Array size")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.legend(loc="upper right")

plt.savefig("sorting_algorithms_graph.png", dpi=300, bbox_inches="tight")

plt.show()
