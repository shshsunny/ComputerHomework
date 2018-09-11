def times(S):#测试一条指令序列返回原点的次数
    pos = [0, 0]
    count = 0
    for i in S:
        if i == 'U':
            pos[1] += 1
        elif i == 'D':
            pos[1] -= 1
        elif i == 'L':
            pos[0] -= 1
        elif i == 'R':
            pos[0] += 1

        if pos == [0, 0]:
            count += 1
    return count
def solve(S, K):#l为长度
    #对于每一个指令的修改选项：4个修改和1个不修改
    if S == '': #修改完成，返回
        return [S]
    if K == 0:
        return [S]
    got1 = solve(S[1:], K - 1)#一个列表
    got0 = solve(S[1:], K)#一个列表
    mine = [n + m for n in 'UDLR' for m in got1]
    mine.extend([S[0] + m for m in got0])
    #print(mine)
    return mine

def do(S, K):
    ans = solve(S, K)
    nums = list(map(times, ans))
    result = max(nums)
    owl = []
    for i in range(len(ans)):
        if nums[i] == result:
            owl.append(ans[i])
    #print('final', list(set(owl)), len(list(set(owl))))
    return result

S = input()# 指令序列
K = int(input()) # 最多允许修改指令数量


print(do(S, K))
