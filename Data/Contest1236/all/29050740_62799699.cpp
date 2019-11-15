#include <stdio.h>
//#include <conio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long LL;
int n;
vector<vector<int>> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i].resize(n);
	int val = 0;
	for (int j = 0; j < n; j++)
		if (j % 2 == 0)
			for (int i = 0; i < n; i++)
				val += 1, v[i][j] = val;
		else
			for (int i = n - 1; i >= 0; i--)
				val += 1, v[i][j] = val;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}






	//_getch();
	return 0;
}