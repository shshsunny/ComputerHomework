#include<iostream>
using namespace std;

int turn[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; //��� 
long long number, mod, div;

int main()
{
	cin >> number;
	mod = 10; div = 1;
	int sum = 0;
	//number % mod / div
	while(number % mod != number) //���������δ�������λ
	{
		sum += turn[number % mod / div];
		div *= 10;
		mod *= 10;
	 } 
	cout << sum + 2 << endl;
	return 0;
}
