import sys
def tester():
    S, N = list(map(int, input().split()))
    s, v =[], []
    for i in range(N):
        get = list(map(int, input().split()))
        s.append(get[0]), v.append(get[1])
    Max = solve(S, s, v, i = N - 1)
    print(Max)

cache = {}
def solve(S, s, v, i):
    if (S, i) in cache:
        return cache[(S, i)]
    if S < 0 or i < 0: return 0
    if S - s[i] >= 0:
        get = max(solve(S - s[i], s, v, i - 1) + v[i], solve(S, s, v, i-1))
    else:
        get = solve(S, s, v, i - 1)
    if (S, i) not in cache: cache[(S, i)] = get
    return get


tester()
