/* 
 * Author: Imagine_I
 * Time: 2019-10-13 17:21:50
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll x,y;
	ll g=exgcd(w,d,x,y);
	if(p%g) cout<<-1<<'\n';
	else
	{
		ll nowx=p/w;
		p-=nowx*w;
		ll up=min((ll)100000,nowx);
		for(int i=0;i<=up;i++)
		{
			if((p+i*w)%d==0)
			{
				ll a=nowx-i,b=(p+i*w)/d;
				if((a+b)<=n&&a>=0&&b>=0) cout<<a<<' '<<b<<' '<<n-a-b<<'\n';
				else cout<<-1<<'\n';
				return 0;
			}
		}
		cout<<-1<<'\n';
	}
	
	return 0;
}
