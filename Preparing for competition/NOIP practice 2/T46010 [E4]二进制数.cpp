//˼·��ʹ��cache
//Top-down
#include<iostream>
#define MAXN 100005
long long nums[MAXN]; //��������� 

int solve(int I, int N)
{
	if (I==N) return 0; //������
	//ʹ�û��߲�ʹ�ã����ܰ��ظ���������
	//solve(I+1, N) + 1, solve(I + 1, N)
	if(nums[I] == nums[I+1])//��ͬ��ζ�����ǲ���ͬʱ��ѡ�� 
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
