# Sunny
# DarkRoads.py
# 问题类型：最小生成树

def find(a):
    if U[a] == a:
        return a
    return find(U[a])
def takeWeight(element):
    return element[0]
m, n = map(int, input().split())#m表示交叉路口的总数，n表示街道总数，当m=n=0表测试资料结束。(1 <= m <= 200000; m-1 <= n <= 200000)
f = open('out.txt', 'w')
while not (m == n == 0):
    Map = []#存放所有街道的数据
    for i in range(n):
        x, y, z = map(int, input().split())
        Map.append([z, (x, y)])
    Map.sort(key = takeWeight)
#################################################
    #现在Map包含已经排好序的边
    sum = 0#总开销
    for i in Map:
        sum += i[0]
    #print (Map)
    cost = 0#实际开销
    U = list(range(m))
    for [z, (x, y)] in Map:
        itx = find(x)
        ity = find(y)
        if itx != ity:
            cost += z
            U[itx] = ity
    #print(sum, cost)
    print (sum  - cost, file = f)
    m, n = map(int, input().split())
f.close()
