#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int S, N;
	scanf("%d %d", &S, &N);
	int v[N+1], w[N+1];
	for(int i = 0; i < N; i++)
		scanf("%d %d", &w[i+1], &v[i+1]);
	
	int solve[S + 1][N + 1];
	for(int i = 0; i <= S; i++)
		for(int j = 0; j <= N; j++)
			solve[i][j] = 0;
	
	for(int c = 0; c < S+1; c++){
		for(int i = 1; i < N + 1; i++)
		{
			//printf("%d %d / ", w[i], c);
			solve[c][i] = w[i] <= c ? max(solve[c][i - 1], solve[c - w[i]][i - 1] + v[i]) : solve[c][i - 1];
			//printf("%d ", solve[c][i]);
		}
		//printf("\n");
	}
	/*for(int i = 0; i <= S; i++)
	{for(int j = 0; j <= N; j++)
			printf("%d ", solve[i][j]);
		printf("\n");
	}*/
	printf("%d\n", solve[S][N]);
	return 0;
}