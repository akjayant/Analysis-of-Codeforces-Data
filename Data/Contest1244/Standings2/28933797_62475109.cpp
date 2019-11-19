#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef long long ll;
inline ll read ()
{
	ll s=0,w=1;
	char ch=getchar ();
	while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
	while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
	return s*w;
}
ll n,p,w,d;
ll x,y,z=-1;
bool used[MAXN];
int main()
{
	n=read (),p=read (),w=read (),d=read ();
	while (!used[y*d%w])
	{
		used[y*d%w]=1;
		if (y*d%w==p%w)
		{
			if (p<y*d) continue;
			x=(p-y*d)/w;
			if (x+y<=n)
			{
				z=n-x-y;
				break;
			}
		}
		y++;
	}
//	if (x*w+y*d==p&&x+y+z==n) cout<<"Yes"<<endl;
	if (z==-1) return puts ("-1"),0;
	else printf ("%lld %lld %lld",x,y,z);
	return 0;
}
