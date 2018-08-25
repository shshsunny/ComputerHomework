#include<cstdio>
#include<iostream>
using namespace std;

int f(int C, int i, int* w, int* v)
{
	if(i > 0)
	{
		if (w[i] > C)
			return f(C, i - 1, w, v);
		else
			return max(f(C, i - 1, w, v), f(C - w[i], i - 1, w, v) + v[i]);
	}
	else
		if (w[i] > C)
			return 0;
		else
			return v[i];
		
}

int main()
{
	int S, N;
	scanf("%d %d", &S, &N);
	int v[N], w[N];
	for(int i = 0; i < N; i++)
		scanf("%d %d", &w[i], &v[i]);
	printf("%d\n", f(S, N, w, v));
	return 0;
}
