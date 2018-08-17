#include<stdio.h>
int max(int a, int b)
{
	return a > b ? a : b;
}

int solve(int C, int i, int* s, int* v)
{
	if (C < 0 || i < 0) return 0;
	if(C - s[i] >= 0)
		return max(solve(C - s[i], i - 1, s, v) + v[i], solve(C, i - 1, s, v));
	return solve(C, i - 1, s, v);
}

int main()
{
	int S, N;
	scanf("%d %d", &S, &N);
	int s[N], v[N];
	for(int i = 0; i < N; i++)
		scanf("%d %d", &s[i], &v[i]);
	printf("%d\n", solve(S, N - 1, s, v));
	return 0;
}
