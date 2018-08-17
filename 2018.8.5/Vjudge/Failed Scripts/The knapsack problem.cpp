#include<stdio.h>
#include<iostream>
using namespace std;
int S, N;//Size, Number
int s[2010], v[2010]; //size, value
int cache[2005][2005];
int solve(int S, int i)
{
	if (cache[S][i] != -1) return cache[S][i];
	if (S < 0 || i < 0) return 0;
	int got;
	if(S - s[i] >= 0)
		got = max(solve(S - s[i], i - 1) + v[i], solve(S, i - 1));
	else got = solve(S, i - 1);
	if (cache[S][i] == -1) cache[S][i] = got;
	return got;
}
void tester()
{
	scanf("%d %d", &S, &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &s[i], &v[i]);
	int Max = solve(S, N - 1);
	printf("%d\n", Max);
}

int main()
{
	for(int i = 0; i < 2000; i++)
		for (int j = 0; j < 2000; j++)
			cache[i][j] = -1;
	tester();
	return 0;
}
	
