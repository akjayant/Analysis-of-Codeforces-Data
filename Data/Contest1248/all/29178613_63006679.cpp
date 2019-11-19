#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const double PI = acos(-1.0);

const int MAX_N = 300005;
int bl[MAX_N];
int mincnt[MAX_N];
int pre1mincnt[MAX_N], pre2mincnt[MAX_N];

int getmincnt(int l, int r)
{
	if (l == 0)
		return mincnt[r];
	else
		return mincnt[r] - mincnt[l - 1];
}

int getpre1mincnt(int l, int r)
{
	if (l == 0)
		return pre1mincnt[r];
	else
		return pre1mincnt[r] - pre1mincnt[l - 1];
}

int getpre2mincnt(int l, int r)
{
	if (l == 0)
		return pre2mincnt[r];
	else
		return pre2mincnt[r] - pre2mincnt[l - 1];
}

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int bal = 0;
	int mini = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			bal++;
		else
			bal--;
		bl[i] = bal;
		mini = min(mini, bal);
	}

	if (bal != 0)
	{
		cout << 0 << endl;
		cout << "1 1";
		return 0;
	}

	mincnt[0] = (bl[0] == mini);
	pre1mincnt[0] = (bl[0] == mini + 1);
	pre2mincnt[0] = (bl[0] == mini + 2);
	for (int i = 1; i < n; i++)
	{
		mincnt[i] = mincnt[i - 1] + (bl[i] == mini);
		pre1mincnt[i] = pre1mincnt[i - 1] + (bl[i] == mini + 1);
		pre2mincnt[i] = pre2mincnt[i - 1] + (bl[i] == mini + 2);
	}

	int maxi = mincnt[n - 1];
	int ansl = 0, ansr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
				continue;
			if (s[i] == '(')
			{
				if (getmincnt(i, j - 1) == 0)
				{
					int res;
					if (getpre1mincnt(i, j - 1) > 0)
					{
						res = getpre1mincnt(i, j - 1);
					}
					else
					{
						res = mincnt[n - 1] + getpre2mincnt(i, j - 1);
					}
					if (res > maxi)
					{
						maxi = res;
						ansl = i;
						ansr = j;
					}
				}
			}
			else
			{
				if (getmincnt(i, j - 1) == mincnt[n - 1])
				{
					int res;
					if (getpre1mincnt(i, j - 1) == pre1mincnt[n - 1])
					{
						res = mincnt[n - 1] + pre2mincnt[n - 1] - getpre2mincnt(i, j - 1);
					}
					else
					{
						res = pre1mincnt[n - 1] - getpre1mincnt(i, j - 1);
					}
					if (res > maxi)
					{
						maxi = res;
						ansl = i;
						ansr = j;
					}
				}
			}
		}
	}

	cout << maxi << endl;
	cout << ansl + 1 << " " << ansr + 1;

	//system("pause");
	return 0;
}