# Knapsack.py

def f(i, C):
    if C < 0: return 0
    if i < 0: return 0
    if C - w[i] >= 0:
        return max(f(i - 1, C), f(i - 1, C - w[i]) +v[i])
    return f(i - 1, C)

