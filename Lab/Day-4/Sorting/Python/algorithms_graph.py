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

plt.figure(figsize=(10, 6))
plt.plot(x, bubble_sort, label="Bubble Sort", marker="o")
plt.plot(x, selection_sort, label="Selection Sort", marker="s")
plt.plot(x, insertion_sort, label="Insertion Sort", marker="^")


plt.title("Sorting Algorithms Performance")
plt.xlabel("Array size")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.legend(loc="upper right")


plt.savefig("sorting_algorithms_graph.png", dpi=300, bbox_inches="tight")

plt.show()
