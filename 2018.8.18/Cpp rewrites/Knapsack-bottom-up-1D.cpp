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
	
	int solve[S + 1];
	for(int i = 0; i <= S; i++)
			solve[i] = 0;
	
	for(int i = 1; i < N+1; i++){
		for(int c = S; c > w[i] - 1; c--)
		{
			//printf("%d %d / ", w[i], c);
			solve[c] = max(solve[c], solve[c - w[i]] + v[i]);
			//printf("%d ", solve[c][i]);
		}
		//printf("\n");
	}
	/*for(int i = 0; i <= S; i++)
	{for(int j = 0; j <= N; j++)
			printf("%d ", solve[i][j]);
		printf("\n");
	}*/
	printf("%d\n", solve[S]);
	return 0;
}