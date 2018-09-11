#include<iostream>
#include<string>
using namespace std;


bool search(string word, int N, int M, string matrix[])
{
	//extern matrix;
	int W = word.length();
	bool eq, ok = false;
	// ˙≈≈≤È—Ø
	for(int i = 0; i < N - W + 1; i++)
		for(int j = 0; j < M; j++)
		{
			eq = true;
			for(int k = 0; k < W; k++)
				if(matrix[i + k][j] != word[k]) eq = false;
			if (eq) ok = true;
		} 
	//∫·≈≈≤È—Ø 
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M - W + 1; j++)
		{
			eq = true;
			for(int k = 0; k < W; k++)
				if(matrix[i][j + k] != word[k]) eq = false;
			if (eq) ok = true;
		} 
	return ok;
}
int main()
{
	int N, M;//æÿ’Û≥ﬂ¥Á
	cin >> N >> M;
	string matrix[N]; //æÿ’Û
	for(int i = 0; i < N; i++) 
		cin >> matrix[i];// ‰»Î“ª––
	
	int WNUM;
	cin >> WNUM;
	string In;
	string ans[WNUM]; 
	for(int i = 0; i < WNUM; i++)
	{
		cin >> In;
		ans[i] = (search(In, N, M, matrix) ? "YES" : "NO");
	}
	for(int i = 0; i < WNUM; i++)
		cout << ans[i] << endl;
	return 0;
 } 
