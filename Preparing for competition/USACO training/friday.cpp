/*
ID: shshsun1
TASK: friday
LANG: C++
*/

//���������1900.1.1��1900 + N - 1.12.31��N��ͳ��13����������һ����������ܴ�����
/* ˼·
 * 1. ��ʼ��7�յ�ͳ��������Ϊ0��
 * 2. ����������ݰ��ղ��Եó��ճ̱�
*/

//#define fin cin
//#define fout cout 

#include<cstdio>
#include<iostream>
#include<fstream>
#include<cstring>

#define START 1900 //��ʼ�����
#define STARTDAY 1 //��ʼ�����ڼ�
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //��ʼ����ʮ�����µĳ��ȣ��ɸ��ģ�

bool leap(int year) //�Ƿ�������
{
    if(year % 100 == 0)//������
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
    int Days[7]; //ͳ����Ϣ
    memset(Days, 0, sizeof(Days)); //ͳ����Ϣ����
    int N; //������1~400
    fin >> N;

    int day = STARTDAY;
    int month = 1; //��ǰ���ڵ��·�
    int date = 1; //��ǰ���ڵ�����Ϊ1
    for(int year = START; year < START + N; year ++)//�ܹ�ΪN�곤
    {
        if(leap(year)) months[2 - 1] = 29;
        else months[2 - 1] = 28;
        //��ʼһ���ģ���ͳ��
        while(month <= 12) {
            if (date == 13) //����
                Days[day - 1] += 1;
            //�ƽ�ʱ��
            date++;
            day++;
            //�������ܻ�����
            if (day > 7) day = 1;//����
            if (date > months[month - 1])//����
            {
                month++;
                date = 1;
            }
        }
        //���ò���ͳ�Ʊ��������ڲ���
        month = date = 1;
    }
    fout << Days[5] << ' ' << Days[6] << ' ';
	for(int i = 0; i < 4; i++)
		fout << Days[i] << ' ';
	fout << Days[4] << endl;
    return 0;
}
