cache = {}
def solve(a, b, c, x, y):
    print(x, y)
    # 选项：
    # 1a
    # 1b
    # 1c
    if x == y == 0: return 1
    # if x < 0 or y < 0: 不允许出现这种情况
    Sum = 0
    if x - 1 >= 0:
        if y - a >= 0 and (x, y, 1) not in cache: Sum += solve(a, b, c, x-1, y-a); cache[(x, y, 1)] = 1
        if y - b >= 0 and (x, y, 2) not in cache: Sum += solve(a, b, c, x-1, y-b); cache[(x, y, 2)] = 1
        if y - c >= 0 and (x, y, 3) not in cache: Sum += solve(a, b, c, x-1, y-c); cache[(x, y, 3)] = 1
    return Sum
a, b, c, x, y = map(int, input().split())
print(solve(a, b, c, x, y))
