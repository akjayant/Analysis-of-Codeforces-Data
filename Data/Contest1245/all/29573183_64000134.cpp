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
int i,n,a,b,c,nr,t;
char ch,rs[150];
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>c;
		nr=0;
		for(i=1;i<=n;i++)rs[i]='.';
		for(i=1;i<=n;i++)
		{
			cin>>ch;
			if(ch=='R' && b)b--,nr++,rs[i]='P';
			else if(ch=='P' && c)c--,nr++,rs[i]='S';
			else if(ch=='S' && a)a--,nr++,rs[i]='R';
		}
		for(i=1;i<=n;i++)
		{
			if(rs[i]!='.')continue;
			if(a)a--,rs[i]='R';
			else if(b)b--,rs[i]='P';
			else if(c)c--,rs[i]='S';
		}
		if(nr>=(n+1)/2)
		{
			cout<<"YES\n";
			for(i=1;i<=n;i++)cout<<rs[i];
			cout<<'\n';
		}
		else cout<<"NO\n";
	}
	return 0;
}
