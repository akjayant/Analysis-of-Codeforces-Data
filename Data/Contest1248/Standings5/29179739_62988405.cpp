#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxV = 90010;
const int maxN = 1e5+10;
const int MOD = 1e9+7;
const ll INF = 1000000000000000010LL;
const ll inf = 1e9+10;

int a[maxN];
int cnt[maxN];
int b[maxN];
vector<int> v;
vector<int> s;
int m;

int main() {
	int n;
	scanf("%d",&n);
	ll sum = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	sort(a+1,a+1+n);
	ll cnt = 0;
	for(int i=1;i<=n/2;i++)
	{
		cnt += a[i];
	}
	ll ans = cnt*cnt + (sum - cnt)*(sum - cnt);
	cout<<ans<<endl;
    return 0;
}