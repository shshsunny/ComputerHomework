#include<iostream>
#include<fstream>
#include<string>
#include<map>

//#define fin cin
//#define fout cout
/*
ID: shshsun1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */


using namespace std;

int main()
{
	ifstream fin ("gift1.in");
	ofstream fout("gift1.out");
	int NP, i; //声明总人数
	fin >> NP;
	
	string friends[NP]; //对应的人名
	map<string, int> money; //人名与钱数的键值对
	for(i = 0; i < NP; i++)
	{
		fin >> friends[i];
		money[friends[i]] = 0;
	}
	
	//for(int i = 0; i < NP; i++)
	//	fout << i << friends[i] << money[friends[i]] << endl;
	for(i = 0; i < NP; i++)
	{
		//fout << ">>> turn " << i << endl << endl;
		string afriend; //送出礼物的朋友的名字
		fin >> afriend;
		int gift, count; //礼金金额，朋友数量
		fin >> gift >> count;
		//fout << afriend << gift << ' ' << count << endl;
		if(count == 0) continue;
		string name;
		for(int j = 0; j < count; j++)
		{
			fin >> name; //获得要送给的朋友的名字
			//fout << "*** " << name << endl;
			money[name] += gift / count;
		}
		money[afriend] -= gift - gift % count;
	}
	for(int i = 0; i < NP; i++)
		fout << friends[i] << ' ' << money[friends[i]] << endl;
	return 0;
}