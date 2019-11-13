#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <set>
#include<stack>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

using ll = long long;
#define var auto
#define endl '\n'


void solve()
{
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		int firstNumber = 1;
		int lastNumber = n * n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n / 2; ++j)
				cout << firstNumber++ << " ";
			for (int j = n / 2; j < n; ++j)
				cout << lastNumber-- << " ";
			cout << endl;
		}
	}
	else
	{
		vector<vector<int>> answers=vector<vector<int>>(n);
		bool frwrd = true;
		int curNum = 1;
		for (int i = 0; i < n; ++i)
		{
			if (frwrd)
			{
				for (int j = 0; j < n; ++j)
					answers[j].push_back(curNum++);
			}
			else
				for (int j = n - 1; j >= 0; --j)
					answers[j].push_back(curNum++);
			frwrd = !frwrd;
		}
		for (auto a : answers)
		{
			for (auto b : a)
				cout << b << " ";
			cout << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	//cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}