#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define lowbit(x) ((x)&(-x))
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define Endl '\n'
#define caze(T) for(cin>>T;T;T--)
#define i16 __int128
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
int a[100010];
int main()
{
	ll n,p,d,w;
	cin>>n>>p>>w>>d;
	clr(a,-1);
	int cnt=0,now=0;
	for(int i=0;a[now]==-1;++i)
	{
		a[now]=cnt++;
		now=(d+now)%w;
	}
	int mx=-1;
	for(int i=0;i<w;++i)
	{
		if(a[i]==-1) continue;
		if((p-i)%w==0)
		{
			ll y=a[i],x=(p-y*d)/w;
			if(x+y<=n&&x>=0&&y>=0)
			{
				cout<<x<<' '<<y<<' '<<n-x-y<<endl;
				return 0;
			}
		}
	}
	puts("-1");
}