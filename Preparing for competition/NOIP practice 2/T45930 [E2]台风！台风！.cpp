//��������
//˼·��ֱ�ӽ�����ת��Ϊ������ͳһ����
#include<iostream>
using namespace std;
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //2018������·ݵ�����
int dtd(int month, int date) //��x��y��תΪ����ĵڼ���
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
