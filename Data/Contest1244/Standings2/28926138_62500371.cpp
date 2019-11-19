#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=110000;
int n, a[MAXN];
ll m, s[MAXN];
bool check(int k)
{
	for (int i=1; i<=n; i++)
	{
		int j=lower_bound(a+1, a+n+1, a[i]+k)-a;
		if (1ll*i*a[i]-s[i] + s[n]-s[j-1]-1ll*(n-j+1)*(a[i]+k) <= m) return 1;
		j=upper_bound(a+1, a+n+1, a[i]-k)-a-1;
		if (s[n]-s[i-1]-1ll*(n-i+1)*a[i] + 1ll*j*(a[i]-k)-s[j] <= m) return 1;
	}
	return 0;
}
int main()
{
//	freopen("E.in", "r", stdin);
//	freopen("E.out", "w", stdout);
	scanf("%d%I64d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	int l=0, r=1E9;
	while (l<r)
	{
		int mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n", l);
	return 0;
}