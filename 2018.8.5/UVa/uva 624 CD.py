def tester():
    #每行一组资料：[0]空录音带长 [1]歌曲数量 [...]歌曲列表
    args = list(map(int, input().split()))
    while True:
        N = args[0] #空白录音带的长度
        #T = args[1] #歌曲数量
        songs = args[2:]#直接取得所有歌的长度信息
        get = CD(N, songs, i = len(songs) - 1)
        print(' '.join(map(str, get)), 'sum:' + str(sum(get)))
        try:
            args = list(map(int, input().split()))
            if not args: break
        except:
            break
        
def cmpkey(List):
    return sum(List) #算法应当按照最大化利用的原则选择
def CD(N, songs, i, choice = []):#尽可能多装下歌
    if N <= 0 or i < 0: return choice#刻录不了更多歌曲，返回选择的结果
    if N - songs[i] >= 0:
        #假设用上这首歌
        new_choice = choice[:]; new_choice.append(songs[i])
        Yes = CD(N - songs[i], songs, i - 1, new_choice) #添加这首歌之后的解
        No  = CD(N, songs, i - 1, choice) #不添加这首歌的解
        best = max(Yes, No, key = cmpkey) #两者中最佳的选择
        return best
    return CD(N, songs, i - 1, choice)


tester()
