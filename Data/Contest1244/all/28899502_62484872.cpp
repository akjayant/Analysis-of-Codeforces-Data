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
ll n,p,w,d,p1,nr;
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n>>p>>w>>d;
	p1=p;
	while(nr<=50*max(w,d)+1 && p1>=0)
	{
		if(p1%d==0 && (p1/d)+nr<=n)
		{
			cout<<nr<<" "<<p1/d<<" "<<n-(p1/d)-nr<<endl;
			return 0;
		}
		nr++;
		p1-=w;
	}
	p1=p,nr=0;
	while(nr<=50*max(w,d)+1 && p1>=0)
	{
		if(p1%w==0 && (p1/w)+nr<=n)
		{
			cout<<p1/w<<" "<<nr<<" "<<n-(p1/w)-nr<<endl;
			return 0;
		}
		nr++;
		p1-=d;
	}
	rc(-1);
	return 0;
}
