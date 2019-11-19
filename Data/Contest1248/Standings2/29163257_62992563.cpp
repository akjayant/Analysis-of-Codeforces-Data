#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <random>
#include <iostream>
#include <iterator>
#include <stack>
#include <list>
#include <fstream>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MOD = 1000 * 1000 * 1000 + 7;
const int BASE = 257;
const double PI = 2 * acos(0.0);

int dr[]{ 0, 0, 1, -1 };
int dc[]{ 1, -1, 0, 0 };

bool canSet(const vector<vector<char>>& table, int row, int col, char c)
{
	int n = table.size();
	int m = table.front().size();
	if (row > 0 && table[row - 1][col] == c)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;
			int newRow = row - 1 + dr[i];
			int newCol = col + dc[i];
			if (!(0 <= newRow && newRow < n && 0 <= newCol && newCol < m))
				continue;
			if (c == table[newRow][newCol])
				cnt++;
		}
		if (cnt > 0)
			return false;
	}

	if (col > 0 && table[row][col - 1] == c)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0 || i == 2)
				continue;
			int newRow = row + dr[i];
			int newCol = col - 1 + dc[i];
			if (!(0 <= newRow && newRow < n && 0 <= newCol && newCol < m))
				continue;
			if (c == table[newRow][newCol])
				cnt++;
		}
		if (cnt > 0)
			return false;
	}

	return true;
}

void go(int row, int col, int n, int m, vector<vector<char>>& table, int& result)
{
	if (col == m)
	{
		col = 0;
		row++;
		if (row == n)
		{
			bool correct = true;
			for (int i = 0; i < n && correct; i++)
			{
				for (int j = 0; j < m && correct; j++)
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int newRow = i + dr[k];
						int newCol = j + dc[k];
						if (!(0 <= newRow && newRow < n && 0 <= newCol && newCol < m))
							continue;
						if (table[i][j] == table[newRow][newCol])
							cnt++;
					}
					if (cnt > 1)
						correct = false;
				}
			}
			if (correct)
				result++;
			return;
		}
	}

	//if (canSet(table, row, col, true))
	{
		table[row][col] = true;
		go(row, col + 1, n, m, table, result);
	}

	//if (canSet(table, row, col, false))
	{
		table[row][col] = false;
		go(row, col + 1, n, m, table, result);
	}
}

int solve1(int n, int m)
{
	vector<vector<char>> table(n, vector<char>(m, false));
	int result = 0;
	go(0, 0, n, m, table, result);
	return result;
}

int add(int a, int b)
{
	return (a + 0LL + b) % MOD;
}

int sub(int a, int b)
{
	return (a - b + MOD) % MOD;
}

int solve2(int n, int m)
{
	if (n < m)
		return solve2(m, n);
	if (n <= 2)
	{
		if (n == 1 && m == 1)
			return 2;
		if (n == 2 && m == 1)
			return 4;
		if (n == 2 && m == 2)
			return 6;
		throw 2;
	}
	vector<int> f(n);
	f[0] = 2;
	f[1] = 4;
	for (int i = 2; i < n; i++)
		f[i] = add(f[i - 1], f[i - 2]);
	
	return add(f[n - 1], sub(f[m - 1], f.front()));
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", solve2(n, m));
	return 0;
}
