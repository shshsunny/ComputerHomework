def search(word, matrix, N, M):
    W = len(word)#单词长度
    #应该判断一下能够横着或者竖着
    #print(word, W)
    ok = False
    '''for i in range(0, N - W + 1):#最右下方的单词开始点：N - W, M - W
        for j in range(0, M - W + 1):
            #纵列比较
            eq = True
            for k in range(W):
                if matrix[i + k][j] != word[k]:
                    eq = False
            if eq: ok = True
            eq = True
            for k in range(W):
                if matrix[i][j + k] != word[k]:
                    eq = False
            if eq: ok = True'''
    for i in range(0, N - W + 1):#竖排查询
        for j in range(0, M):
            eq = True
            for k in range(W):
                if matrix[i + k][j] != word[k]:
                    eq = False
            if eq: ok = True
    for i in range(0, N):#横排查询
        for j in range(0, M - W + 1):
            eq = True
            for k in range(W):
                if matrix[i][j + k] != word[k]:
                    eq = False
            if eq: ok = True
    return ok
N, M = map(int, input().split())#阵列大小

matrix = []
for i in range(N):
    matrix.append(input())
    
for i in matrix: print(i)

WNUM = int(input())
for i in range(WNUM):
    print('YES' if search(input(), matrix, N, M) else 'NO')
