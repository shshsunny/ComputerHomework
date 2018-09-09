/*
ID: shshsun1
TASK: friday
LANG: C++
*/

//任务：输入从1900.1.1至1900 + N - 1.12.31的N，统计13日落在星期一至星期天的总次数。
/* 思路
 * 1. 初始化7日的统计数量（为0）
 * 2. 遍历，将年份按照测试得出日程表
*/

//#define fin cin
//#define fout cout 

#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>

#define START 1900 //开始的年份
#define STARTDAY 1 //开始的星期几
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //初始定义十二个月的长度（可更改）

bool leap(int year) //是否是闰年
{
    if(year % 100 == 0)//世纪年
        if(year % 400 == 0)
            return true;
        else return false;
    else
        if(year % 4 == 0)
            return true;
        else
            return false;
}

int main()
{
    ifstream fin ("friday.in");
    ofstream fout("friday.out");
    int Days[7]; //统计信息
    memset(Days, 0, sizeof(Days)); //统计信息清零
    int N; //间隔年份1~400
    fin >> N;

    int day = STARTDAY;
    int month = 1; //当前处于的月份
    int date = 1; //当前处于的日期为1
    for(int year = START; year < START + N; year ++)//总共为N年长
    {
        if(leap(year)) months[2 - 1] = 29;
        else months[2 - 1] = 28;
        //开始一年的模拟和统计
        while(month <= 12) {
            if (date == 13) //满足
                Days[day - 1] += 1;
            //推进时间
            date++;
            day++;
            //管理满周或满月
            if (day > 7) day = 1;//满周
            if (date > months[month - 1])//满月
            {
                month++;
                date = 1;
            }
        }
        //重置部分统计变量，星期不变
        month = date = 1;
    }
    fout << Days[5] << ' ' << Days[6] << ' ';
	for(int i = 0; i < 4; i++)
		fout << Days[i] << ' ';
	fout << Days[4] << endl;
    return 0;
}
