def tester():
    #注意：每种商品每人都能用超低的价格各买一件（每人只能买一件东西）
    #输出：全家人能买到的东西的最高价值总额
    T = int(input()) #测试用例数量
    for i in range(T):
        N = int(input()) #接下来共有N件物品
        p, w = [], [] #价格，重量
        for j in range(N):
            get = list(map(int, input().split()))
            p.append(get[0]), w.append(get[1])
        G = int(input()) #群组内的人数
        MW = [] #每个人最大能提起的重量
        for j in range(G):
            MW.append(int(input()))

        print(MaxVal(MW, p, w))


def MaxVal(MW, p, w): #提起最重，价格，重量
    #Way01: 背包问题，将MW视作背包容量，家里的人可以购买重复的东西，但是每人只能买一件
    #认为所有人的最大购买价值 = 每个人的最大购买价值之和
    All = []#所有人的购买最大价值列表
    for C in MW:
        All.append(solve(C, p, w, i = len(p) - 1))
    return sum(All)

def solve(C, p, w, i):
    if C < 0:
        return 0
    if i < 0:
        return 0
    if C - w[i] >= 0:
        return max(solve(C - w[i], p, w, i - 1) + p[i], solve(C, p, w, i - 1))
    return solve(C, p, w, i - 1)

tester()
