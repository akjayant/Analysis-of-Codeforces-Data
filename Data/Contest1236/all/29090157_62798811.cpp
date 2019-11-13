#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 310;
vector<int> seq[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= n; j++)
			{
				seq[j].push_back((i - 1)*n + j);
			}
		}
		else if (i % 2 == 0)
		{
			for (int j = n; j >=1 ; j--)
			{
				seq[j].push_back(i*n - j + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < seq[i].size(); j++)
		{
			cout << seq[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}