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
const ll mod=1e9+7;
using namespace std;
int n,i,j;
string s;
ll f[nmax],rs;
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>s;
	n=(int)s.size();
	f[0]=f[1]=1;
	for(i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	rs=1;
	for(i=0;i<n;i++)
	{
		if(s[i]=='m' || s[i]=='w')rc(0);
		if(s[i]!='n' && s[i]!='u')continue;
		for(j=i;j<n;j++)
		{
			if(s[j]!=s[i])break;
		}
		rs=(rs*f[j-i])%mod;
		i=j-1;
	}
	cout<<rs<<endl;
	return 0;
}
