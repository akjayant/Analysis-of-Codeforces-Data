#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const ll mod=1e9+7;
inline ll read()
{
    ll x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll n,a[N],s;
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),s+=a[i];
	sort(a+1, a+n+1);
	ll ans=0,t=0;
	for(int i=1;i<n/2;i++) s-=a[i],t+=a[i];
	
	for(int i=n/2;i<=(n+1)/2;i++){
		t+=a[i]; s-=a[i];
		ans=max(ans, t*t+s*s);
	}
	cout<<ans<<endl;
}