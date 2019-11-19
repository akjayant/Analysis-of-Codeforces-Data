#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define MOD 1000000007


int solve(string str)
{
	int n = str.size();
	vector<int> min_value(n, n + 10);
	vector<int> left_balance(n, 0);

	int x = 0;
	int min_x = n;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
			x++;
		else
			x--;

		if (i == 0)
			min_value[i] = x;
		else
			min_value[i] = min_value[i - 1];

		if (str[i] == ')')
		{
			min_value[i] = min(min_value[i], x);
		}

		left_balance[i] = x;
	}

	int ans = 0;
	int balance = 0, unpaired = 0;
	for (int j = n - 1; j >= 0; j--)
	{
		if (str[j] == '(')
		{
			balance++;
			if (unpaired > 0)
				unpaired--;
		}
		else
		{
			balance--;
			unpaired++;
		}

		if (unpaired != 0)
			continue;

		if (j == 0)
		{
			if (balance == 0)
				ans++;
			break;
		}

		int other_balance = left_balance[j - 1];
		int other_min = min_value[j - 1];
		if (other_balance > 0 || other_balance != other_min)
		{
			continue;
		}

		if (other_balance == -balance)
			ans++;
	}

	return ans;
}


int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	string str;
	cin >> str;

	int best_ans = 0;
	pair<int, int> best_swap = { 1,1 };


	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			swap(str[i], str[j]);

			int ret = solve(str);
			if (ret >= best_ans)
			{
				best_ans = ret;
				best_swap = { i+1,j+1 };
			}

			swap(str[i], str[j]);
		}
	}

	cout << best_ans << "\n";
	cout << best_swap.first << " " << best_swap.second;


	return 0;
}