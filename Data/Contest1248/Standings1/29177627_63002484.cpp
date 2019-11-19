#include <stdio.h>
#include <string.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
const int maxn = 505;

int n, mn, cnt, ans, ans1, ans2, he;
int a[maxn], sum[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char x;
		cin >> x;
		if(x == '(')
			a[i] = 1;
		else
			a[i] = -1;
	}
	for(int i = 1; i <= n; i++)
		sum[i] = a[i] + sum[i - 1], mn = min(mn, sum[i]);
	
	if(sum[n] != 0)
	{
		cout << 0 << endl;
		cout << "1 1" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		if(mn == sum[i])
			cnt++;
	if(cnt > ans)
		ans = cnt, ans1 = 1, ans2 = 1;
		
	for(int i = 1;i < n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			he = 0, mn =0;
			swap(a[i], a[j]);
			for(int k = 1; k <= n; k++)
				he += a[k], mn = min(mn, he);
			he = 0, cnt = 0;
			for(int k = 1; k <= n; k++)
			{
				he += a[k];
				if(he == mn)
					cnt++;
			}
			if(cnt > ans)
				ans = cnt, ans1 = i, ans2 = j;
			swap(a[i], a[j]);
		}
	cout << ans << endl;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
