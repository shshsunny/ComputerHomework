# SuperSale.py
# 只计算一次，得出全家人的解——方法：用二维数组解法，保存下所有人的解的信息，就可以一次过了。
N = P = W = G = MW = None

def solve(C):# 只用最大提起量，得到整个二维解数组
    global N, P, W
    I = N# I作为索引，相当于+1，这是前面的原因
    # Grid[N + 1][I + 1] # 因为两个都有0值
    Grid = [[0 for i in range(I + 1)] for c in range(C + 1)]
    for c in range(C + 1):# 索引为0 ~ C
        for i in range(1, I + 1):# 索引为1 ~ I
            Grid[c][i] = max(Grid[c][i - 1], Grid[c - W[i]][i - 1] + P[i]) if c >= W[i] else Grid[c][i - 1]
    return Grid
def In():# 输入函数
    '''
    输入格式：
    T # 测试用例的总数
    N # 物品种类数量
    P W # N行，每种的价值和重量
    ...
    G # 家人的数量
    MW # G行，每个人能提起的最大值
    ...
    '''
    global N, P, W, G, MW
    N = int(input())
    P, W = [None], [None]# 预留位置，方便索引
    for i in range(N):
        dat = list(map(int, input().split()))
        P.append(dat[0]); W.append(dat[1])
    G = int(input())
    MW = []
    for i in range(G):
        MW.append(int(input()))

    # 处理
    Max = max(MW) #得到最重的能提起的量
    # 0 <= MW <= C
    # 1 <= i <= I
    result = solve(C = Max)# 调用解决方案：最大提起量
    Sum = 0
    for i in MW:
        Sum += result[i][-1]
    return Sum


####Test
for i in range(int(input())):
    print(In())

