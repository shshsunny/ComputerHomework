def times(S):
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
def solve(S, K):
    if S == '': 
        return [S]
    if K == 0:
        return [S]
    got1 = solve(S[1:], K - 1)
    got0 = solve(S[1:], K)
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
    
    return result

'''def main(S, K):
    S = input()
    K = int(input())
    print(do(S, K))'''
