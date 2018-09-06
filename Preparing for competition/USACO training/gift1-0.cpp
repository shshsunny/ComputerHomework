/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: shshsun1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<cstdio>
#include <iostream>
#include <fstream>
#include<cstring>
#include <string>

using namespace std;

int pos(string name, string* friends, int num)
{
	for(int i = 0; i < num; i++)
		if (name == friends[i]) return i;
	return -1;
}

int main()
{
	ifstream fin ("gift1.in");
	ofstream fout("gift1.out");
	int NP;
	cin >> NP;
	string friends[NP]; //初始化朋友名称列表
	for (int i = 0; i < NP; i++)
		cin >> friends[i];
	cout << "test " << NP << endl;
	int money[NP]; //初始化朋友钱列表（余额）
	memset(money, 0, sizeof(friends));
	for (int i = 0; i < NP; i++) //模拟进行运算
	{
		string name; fin >> name;
		string afriend;
		int total, count; //这个人的总额和朋友数量
		fin >> total >> count;
		//cout << "test " << total << count << endl;
		for (int j = 0; j < count; j++)
		{
			//cout << "test " << pos(name, friends, NP) << endl;
			money[pos(name, friends, NP)] -= total / count; //送礼者花费钱
			cin >> afriend;
			money[pos(afriend, friends, NP)] += total / count; //收礼者收入钱
		}
	}
	
	for(int i = 0; i < NP; i++)
	{
		cout << friends[i] << ' ';
		cout << money[i] << endl;
	}
	
	return 0;
}
		