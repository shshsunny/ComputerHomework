#include<cstdio>
#include<iostream>
using namespace std;
int S, N;
int cache[2000][2000];
/*int test()
{
	extern int cache[2000][2000];
	for(int i = 0; i < S; i++)
	{for(int j = 0; j < N; j++)
			printf("%d ", cache[i][j]);
	printf("\n");}
}*/
int f(int C, int i, int* w, int* v)
{
	//test();
	extern int cache[2000][2000];
	//test();
	//printf("%d%dtf%d\n", C, i, cache[C][i] != -1);
	if (cache[C][i] != -1){return cache[C][i];}
	int result;
	if(i > 0)
	{
		if (w[i] > C)
		    result = f(C, i - 1, w, v);
		else
			result = max(f(C, i - 1, w, v), f(C - w[i], i - 1, w, v) + v[i]);
	}
	else
		if (w[i] > C)
			result = 0;
		else
			result = v[i];
	cache[C][i] = result;
	//printf("%d\n", result);
	return result;
}
int main()
{
	scanf("%d %d", &S, &N);
	int v[N], w[N];
	extern int cache[2000][2000];
	for(int i = 0; i < 2000; i++)
        for(int j = 0; j < 2000; j++)
			cache[i][j] = -1;
	//test();
		//printf("a%d\n", cache[i][j]);}
	for(int i = 0; i < N; i++)
		scanf("%d %d", &w[i], &v[i]);
	printf("%d\n", f(S, N, w, v));
	return 0;
}