#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200100;
int a[MAXN];
ll S[MAXN];
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll check(int n, int x)
{
	ll mi=1LL<<62;
	for(int i = 1; i <= n; i++)
    {
		int p = upper_bound(a + 1, a + 2 + n, a[i] + x) - a;
		ll nd = (ll)(i - 1) * a[i] - S[i - 1] + S[n] - S[p - 1] - (ll)(n - p + 1) * (a[i] + x);
		mi=min(mi,nd);
	}
	for(int i = n; i >= 1; i--)
    {
		int p = upper_bound(a, a + 1 + n, a[i] - x) - a;
		ll nd = (ll)(p - 1) * (a[i] - x) - S[p - 1] + S[n] - S[i] - (ll)(n - i) * a[i];
		mi=min(mi,nd);
	}
	return mi;
}
int n;
ll k;
void solve()
{
	int l=0,r=1000000000,res=1000000000;
	while(l <= r)
    {
		int mid=(l + r) >> 1;
		if(check(n, mid) <= k) res = mid, r = mid - 1;
		else l = mid + 1;
	}
    printf("%d\n", res);
}
int main()
{
	cin>>n>>k;
	for(int i = 1; i <= n; i++) a[i]=read();
	sort(a + 1, a + 1 + n); a[n + 1] = 2147483647; a[0] = -a[n];
	for(int i = 1; i <= n; i++) S[i] = S[i - 1] + a[i];
    S[n + 1] = S[n];
    solve();
	return 0;
}