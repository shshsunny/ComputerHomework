#include<iostream>
#include<cstring> 
#define MAXN 505
#define MAXM 100005 
#define signal my_signal
using namespace std;
//策略：模拟，在所有的节点都已经到达之后结束

/*struct road {
	int from, to, dist; //开始节点，去往节点，路程
	road(int from, int to, int dist):from(from), to(to), dist(dist){} 
}; */

int N, M, K; //节点数，链路数，信号发起节点 
int arrived; //信号已经抵达的节点数量 
//bool arrived[MAXN]; //节点是否已经到达 
int signal[MAXN]; //信号到达情况（未到达为-1，发起点是0，到达之后是正整数） ，初始化memset为-1 
int froms[MAXM]; //链路：开始节点
int tos[MAXM]; //链路：去往节点
int dists[MAXM]; //链路：路程 

void print(int sig[MAXN])
{
	cout << "test ";
	for(int i = 1; i < N; i++)
		cout << sig[i] << ' ';
	cout << sig[N] << endl;
}
int main()
{
	int T; cin >> T; int ans;
	for(int kase = 0; kase < T; kase++)
	{
		ans = 0; //答案 
		memset(signal, -1, sizeof(signal)); //设置初始为没有到达
		//arrived = 0; //重置已经信号抵达的节点数量 
		cin >> N >> M >> K;
		signal[K] = 0; //发起点，信号值为0（因为0秒就可以到达呀） 
		int u, v, w;
		for(int i = 1; i <= M; i++) //输入链路
		{
			cin >> u >> v >> w;
			froms[i] = u;
			tos[i] = v;
			dists[i] = w;
		}
		//接下来先测试一下，是否有节点无法到达
		bool yes = true; 
		for(int i = 1; i <= N; i++)
		{
			bool ok = false;
			if(i == K) continue; //不包括起始节点，因为它默认为到达了 
			for(int j = 1; j <= M; j++)
				if(tos[j] == i) {ok = true; break;} //满足条件了
			if(!ok) {yes = false; break;}
			
		 } 
		 
		if(!yes) //有节点无法到达 
		{
		 	cout << -1 << endl;
		 	continue;
		}
		 //接下来：开始执行 
		//cout << "started..." << endl;
		bool notyet = true; //信号还没有全部抵达
		while(notyet)
		{
			//print(signal); 
			//cout << "in loop..." << arrived << ' ' <<N<< endl;
		 	for(int i = 1; i <= M; i++) //将所有的链路遍历一遍
			{
				/*
				*如果from节点已到达：
					如果to节点尚未到达，那么将to节点设为from + dist 
				*/
				if(signal[froms[i]] != -1) //from节点已到达
					if(signal[tos[i]] == -1 || signal[froms[i]] + dists[i] < signal[tos[i]]) //to节点尚未到达，满足信号传递的条件（或者其实有更快的路线） 
					{ 
						signal[tos[i]] = signal[froms[i]] + dists[i]; //成功让一个节点抵达 
						//arrived ++; 
					} 
			}
			/*if(N == arrived + 1) //所有节点已成功抵达，接下来要取耗时最大值（最长时间）  -> max(signal)
			{
				for(int i = 1; i <= N; i++)
					ans = signal[i] > ans ? signal[i] : ans;
					
				notyet = false; //可以结束了 
			}*/
			//print(signal);
			notyet = false;
			for(int i = 1; i <= N; i++) //在求最大值同时留意是不是还没有全部抵达
			{
				if(signal[i] == -1){notyet=true; ans = 0; break;}
				ans = signal[i] > ans ? signal[i] : ans;
			 } 
		}
		cout << ans << endl;
	 } 
}
