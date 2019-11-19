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
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		scanf("%d",&n);
		int ca0=0,ca1 = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%2 == 0)
				ca0++;
			else
				ca1++;
		} 
		int m;
		scanf("%d",&m);
		int cb0=0,cb1 = 0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			if(b[i]%2 == 0)
				cb0++;
			else
				cb1++;
		}
		ll ans = (ll)ca0*cb0 + (ll)ca1*cb1;
		cout<<ans<<endl;
	}
	
    return 0;
}