/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: shshsun1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<cstdio>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int getNumber(string S) //获取字符串对应数值
{
	int M = 1; //累乘积
	for(int i = 0; i < S.length(); i++)
		M *= S[i] - 'A' + 1;
	return M % 47;
}
int main()
{
	ofstream fout ("ride.out");
	ifstream fin  ("ride.in");
	string UFO, group;int UFOn, groupn;
	fin >> UFO;
    fin >> group;
	UFOn = getNumber(UFO); groupn = getNumber(group);
	fout << (UFOn == groupn ? "GO" : "STAY") << endl;
	//cout << "OK";
	return 0;
}
	
	