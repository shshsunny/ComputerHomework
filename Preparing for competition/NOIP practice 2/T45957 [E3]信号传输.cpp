#include<iostream>
#include<cstring> 
#define MAXN 505
#define MAXM 100005 
#define signal my_signal
using namespace std;
//���ԣ�ģ�⣬�����еĽڵ㶼�Ѿ�����֮�����

/*struct road {
	int from, to, dist; //��ʼ�ڵ㣬ȥ���ڵ㣬·��
	road(int from, int to, int dist):from(from), to(to), dist(dist){} 
}; */

int N, M, K; //�ڵ�������·�����źŷ���ڵ� 
int arrived; //�ź��Ѿ��ִ�Ľڵ����� 
//bool arrived[MAXN]; //�ڵ��Ƿ��Ѿ����� 
int signal[MAXN]; //�źŵ��������δ����Ϊ-1���������0������֮������������ ����ʼ��memsetΪ-1 
int froms[MAXM]; //��·����ʼ�ڵ�
int tos[MAXM]; //��·��ȥ���ڵ�
int dists[MAXM]; //��·��·�� 

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
		ans = 0; //�� 
		memset(signal, -1, sizeof(signal)); //���ó�ʼΪû�е���
		//arrived = 0; //�����Ѿ��źŵִ�Ľڵ����� 
		cin >> N >> M >> K;
		signal[K] = 0; //����㣬�ź�ֵΪ0����Ϊ0��Ϳ��Ե���ѽ�� 
		int u, v, w;
		for(int i = 1; i <= M; i++) //������·
		{
			cin >> u >> v >> w;
			froms[i] = u;
			tos[i] = v;
			dists[i] = w;
		}
		//�������Ȳ���һ�£��Ƿ��нڵ��޷�����
		bool yes = true; 
		for(int i = 1; i <= N; i++)
		{
			bool ok = false;
			if(i == K) continue; //��������ʼ�ڵ㣬��Ϊ��Ĭ��Ϊ������ 
			for(int j = 1; j <= M; j++)
				if(tos[j] == i) {ok = true; break;} //����������
			if(!ok) {yes = false; break;}
			
		 } 
		 
		if(!yes) //�нڵ��޷����� 
		{
		 	cout << -1 << endl;
		 	continue;
		}
		 //����������ʼִ�� 
		//cout << "started..." << endl;
		bool notyet = true; //�źŻ�û��ȫ���ִ�
		while(notyet)
		{
			//print(signal); 
			//cout << "in loop..." << arrived << ' ' <<N<< endl;
		 	for(int i = 1; i <= M; i++) //�����е���·����һ��
			{
				/*
				*���from�ڵ��ѵ��
					���to�ڵ���δ�����ô��to�ڵ���Ϊfrom + dist 
				*/
				if(signal[froms[i]] != -1) //from�ڵ��ѵ���
					if(signal[tos[i]] == -1 || signal[froms[i]] + dists[i] < signal[tos[i]]) //to�ڵ���δ��������źŴ��ݵ�������������ʵ�и����·�ߣ� 
					{ 
						signal[tos[i]] = signal[froms[i]] + dists[i]; //�ɹ���һ���ڵ�ִ� 
						//arrived ++; 
					} 
			}
			/*if(N == arrived + 1) //���нڵ��ѳɹ��ִ������Ҫȡ��ʱ���ֵ���ʱ�䣩  -> max(signal)
			{
				for(int i = 1; i <= N; i++)
					ans = signal[i] > ans ? signal[i] : ans;
					
				notyet = false; //���Խ����� 
			}*/
			//print(signal);
			notyet = false;
			for(int i = 1; i <= N; i++) //�������ֵͬʱ�����ǲ��ǻ�û��ȫ���ִ�
			{
				if(signal[i] == -1){notyet=true; ans = 0; break;}
				ans = signal[i] > ans ? signal[i] : ans;
			 } 
		}
		cout << ans << endl;
	 } 
}
