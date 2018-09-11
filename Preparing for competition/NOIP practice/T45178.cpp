#include<iostream>
using namespace std;


int solve(int a, int b, int c, int x, int y)//now：当前分支的方案数量 
{
	//应当保证x，y非负
	cout << x << ' ' << y << endl;
	if(x == y == 0) return 1; //此方案是成功结束的
	if(x != y && (x == 0 or y == 0)) return 0;
	int tries[] = {0, 0, 0};
	if (x - 1 >= 0)
	{
		if (y - a >= 0) tries[0] = solve(a, b, c, x - 1, y - a); //可以钢笔
		if (y - b >= 0) tries[1] = solve(a, b, c, x - 1, y - b); //可以圆珠笔
		 if (y - c >= 0) tries[2] = solve(a, b, c, x - 1, y - c); //可以铅笔 
	}
	cout << tries[0] + tries [1] + tries[2] << "test" << endl;
	return tries[0] + tries [1] + tries[2];
}
int main()
{
	int a, b, c;
	int x, y;
	cin >> a >> b >> c >> x >> y;
	cout << solve(a, b, c, x, y) << endl;
	return 0;
 } 
