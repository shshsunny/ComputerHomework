#思路：跳跃之后，每只马返回可能在的位置列表，寻找其中的相同项。
def next(pos, step, N, M): #从pos跳跃step次之后能得到的位置
    queue = [pos]
    for time in range(step):#
        point = queue.pop(0)
        x, y = point
        nexts = [(x+1, y+2),(x+1, y-2),(x+2, y+1),(x+2, y-1),(x-1, y+2),(x-1, y-2),(x-2, y+1),(x-2, y-1)]
        new = []
        for i in nexts:
            if max((N, M), i) == (N, M) and min((0, 0), i) == (0, 0): new.append(i)
        queue.extend(new)
    return queue
def solve(N, M, board):
    horse = []
    pos = []
    for i in range(N):
        for j in range(M):
            if board[i][j] != '.':
                horse.append(int(board[i][j]))
                pos.append((i, j))
    count = 1
    while True:
        new_horses = []
        for i in range(len(horse)):#所有的马走一步
            h = horse.pop(0)
            news = next(pos.pop(0), h, N, M)
            if not news:#没有地方跳的马
                count = float('-inf')
                break
            new_horses.append(news)
            #pos.extend(news)
            #horse.extend([h * len(news)])
        if count < 0: break
        print(horse, new_horses)
        get = set(new_horses.pop(0))
        for i in new_horses:#求交集
            get &= set(i)
        if get: break
        count += 1
    return count

kase = int(input())
for i in range(kase):
    N, M = map(int, input().split())
    board = []
    for n in range(N):
        board.append(input())
    print(solve(N, M, board) if solve(N, M, board) > 0 else -1) 

            

    
