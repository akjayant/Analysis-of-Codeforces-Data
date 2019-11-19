#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int n,i,m,nr,l,r;
ll a[nmax],k,d;
pair<ll,ll>b[nmax];
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	nr=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			b[++m]=mkp(a[i-1],nr);
			nr=1;
		}
		else nr++;
	}
	b[++m]=mkp(a[n],nr);
	//for(i=1;i<=m;i++)cout<<b[i].fr<<" "<<b[i].sc<<endl;
	l=1,r=m;
	while(1)
	{
		if(k<=0 || l==r)break;
		if(b[l].sc<=b[r].sc)
		{
			d=b[l+1].fr-b[l].fr;
			if(d*b[l].sc<=k)
			{
				k-=d*b[l].sc;
				b[l+1].sc+=b[l].sc;
				l++;
			}
			else
			{
				b[l].fr+=(k/b[l].sc);
				k=0;
				break;
			}
		}
		else
		{
			d=b[r].fr-b[r-1].fr;
			if(d*b[r].sc<=k)
			{
				k-=d*b[r].sc;
				b[r-1].sc+=b[r].sc;
				r--;
			}
			else
			{
				b[r].fr-=(k/b[r].sc);
				k=0;
				break;
			}
		}
	}
	cout<<b[r].fr-b[l].fr<<endl;
	return 0;
}
