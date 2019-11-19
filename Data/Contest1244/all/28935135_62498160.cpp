#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
 
const int N = 111111;
const int M = 666;
const ll md = 1e9 + 7;
 
int n, m, k, q;
ll ans;
ll x;
ll a[N];
ll s[N], ss[N];

int work()
{
	return 1;
}

int main()
{
	ios::sync_with_stdio(false); cout<<setprecision(20);
 
	scanf("%d%I64d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%I64d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	ans = a[n] - a[1];
	for (int i = 2; i <= n; i++)
	{
		s[i] = s[i - 1] + 1LL * (i - 1) * (a[i] - a[i - 1]);
	}
	for (int i = n - 1; i > 0; i--)
	{
		ss[i] = ss[i + 1] + 1LL * (n - i) * (a[i + 1] - a[i]);
	}
	for (int r = 1, l = 1; r <= n; r++)
	{
		while (l < r && l <= n + 1 - r && s[l + 1] + ss[r] <= x)
		{
			l++;
		}
		while (l > n + 1 - r)
		{
			l--;
		}
		//printf("%d %d\n", l, r);
		if (s[l] + ss[r] > x)
		{
			continue;
		}
		ll t = x - s[l] - ss[r];
		ll cnt = 0;
		if (l != r)
		{
			ll cntl = min(a[l + 1] - a[l], t / l);
			cnt += cntl;
			t -= cntl * l;
			ll lb = max(a[r - 1], a[l] + cntl);
			ll cntr = min(a[r] - lb, t / (n + 1 - r));
			cnt += cntr;
		}
		ans = min(ans, a[r] - a[l] - cnt);
	}
	printf("%I64d\n", ans);
	
	return 0;
}