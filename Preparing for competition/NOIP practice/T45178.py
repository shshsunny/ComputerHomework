cac = {}

def solve(a, b, c, x, y, d):
    print(d)
    if (x, y) in cac:
        return 0
    cac[(x, y)] = 1
    #print(x, y)
    if x == y == 0: print('success!');return 1
    if x <= 0 or y <= 0: return 0
    if x - 1 >= 0:
        temp = [solve(a, b, c, x - 1, y - a, d+1) if y - a >= 0 else 0, solve(a, b, c, x - 1, y - b, d+1) if y - b >= 0 else 0, solve(a, b, c, x - 1, y - c, d+1) if y - c >= 0 else 0]
        #print(temp)
        return sum(temp)
    return 0
a, b, c, x, y = map(int, input().split())
print(solve(a, b, c, x, y, 1))
        
