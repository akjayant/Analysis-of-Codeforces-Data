#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		ans += min(b, c / 2)*3;
		b -= min(b, c / 2);
		c -= min(b, c / 2) * 2;
		ans += min(a, b / 2)*3;
		cout << ans << endl;
	}

	return 0;
}