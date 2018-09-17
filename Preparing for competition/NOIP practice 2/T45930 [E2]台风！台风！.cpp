//计算日期
//思路：直接将月日转换为天数后统一计算
#include<iostream>
using namespace std;
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //2018年各个月份的天数
int dtd(int month, int date) //将x月y日转为当年的第几天
{
	int days = date;
	
	for(int i = 1; i < month; i++)
	{
		//cout << "test " << days <<endl;
		days += months[i - 1];
	}
	//cout << "test " << days <<endl;
	return days; 
} 

int main()
{
	int month, date, days1, days2;
	cin >> month >> date;
	days1 = dtd(month, date);
	cin >> month >> date;
	days2 = dtd(month, date);
	cout << days2 - days1 << endl;
	return 0;
}
