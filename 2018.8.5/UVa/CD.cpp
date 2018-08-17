#include<stdio.h>
#include<iostream>
using namespace std;
int sum(int arr[20], int i)
{
	if (i == 20) return 0;
	return arr[i] + sum(arr, ++i);
}
int max(int* x, int* y)
{
	return sum(x, 0) > sum(y, 0) ? x : y;
}
int* CD(int N, int* songs, int i, int* choice, int val)//容量，歌曲列表，前i项，选择，当前占用的最高位val默认为0
{
	if(N < 0 || i < 0 || val > 19) return choice;
	if(N - songs[i] >= 0)//先计算不使用这首歌的，再计算使用这首歌的
	{
		//先声明新的数组，将旧的拷贝一下
		int new_choice[20]; memcpy(new_choice, choice, sizeof(new_choice)); //copy
		int* No = CD(N, songs, i - 1, choice, val); //No
		new_choice[val] = songs[i]; //添加新的歌曲
		int* Yes= CD(N - songs[i], songs, i - 1, new_choice, val + 1);
		return max(No, Yes);
	}
	else
		return CD(N, songs, i - 1, choice, val);
}

		

		
int main()
{
	int N, T;
	while(scanf("%d %d", &N, &T) == 1)
	{
		int songs[20];
		for(int i = 0; i < T; i++)
			scanf("%d", &songs[i]);
		int arr[20];
		memset(arr, 0, sizeof(arr));
		int get[20] = CD(N, songs, T - 1, arr, 0);
		int j = 0;
		while(j < 20 && get[j] != 0)
		{
			printf("%d ", get[j]);
			++j;
		}
		printf("sum:%d", sum(get, 0));
	}
	return 0;
}
	
