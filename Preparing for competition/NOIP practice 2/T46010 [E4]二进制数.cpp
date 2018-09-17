//思路：使用cache
//Top-down
#include<iostream>
#define MAXN 100005
long long nums[MAXN]; //所输入的数 

int solve(int I, int N)
{
	if (I==N) return 0; //结束了
	//使用或者不使用，不能把重复的算入内
	//solve(I+1, N) + 1, solve(I + 1, N)
	if(nums[I] == nums[I+1])//相同意味着它们不能同时被选上 
}
int main()
{
	int kase, N; cin >> kase;
	for(int i = 1; i <= kase; i++)
	{
		cin >> N;
		for(int j = 1; j <= N; j++)
			cin >> nums[j];
		cout << solve(1, N) << endl;
		
	}
} 
