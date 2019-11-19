#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 2;
int a[N],b[N];
bool fuck[N];
signed main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	if(k < n * (n + 1) / 2)
	{
		cout << -1 << endl;
		return 0;
	}
	int now = n * (n + 1) / 2;
	int cnt = 2 * n + 1;
	for(int i = n;i >= 1;i--)
	{
		if(now + cnt / 2 - i <= k)
			a[i] = cnt / 2,now += cnt / 2 - i,cnt--;
		else
		{
			a[i] = i + k - now;
			now = k;
			for(int j = i - 1;j >= 1;j--)
				a[j] = j;
			break;
		}
	}
	cnt = 0;
	for(int i = 1;i <= n;i++)
		if(a[i] != a[i + 1])
			b[++cnt] = a[i],fuck[a[i]] = true;
	for(int i = 1;i <= n;i++)
		if(!fuck[i])
			b[++cnt] = i;
	cout << now << endl;
	for(int i = 1;i <= n;i++)
		cout << i << " ";
	cout << endl;
	cnt = 0;
	for(int i = 1;i <= n;i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}