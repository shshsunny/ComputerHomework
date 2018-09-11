#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#include<set>
int main()
{
	//思路：跳跃之后，每只马返回可能在的位置列表，寻找其中的相同项。 
	int kase;
	cin >> kase;
	int horses[10];
	int hp;
	for(int akase = 0; akase < kase; akase ++)
	{
		int N, M; //棋盘的行列数
		memset(horses, 0, sizeof(horses)); hp = 0;
		string line; //输入的行 
		cin >> N >> M;
		for(int i = 0; i < N; i++)
		{
			cin >> line;
			for(int c = 0; c < line.length(); c++)
				if (line[c] != '.')
				{
					
				}
		}
	 } 
}
