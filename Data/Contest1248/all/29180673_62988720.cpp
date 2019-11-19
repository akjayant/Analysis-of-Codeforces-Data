#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const ll mod=1e9+7;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,m,p[N],q[N],cnt[2];
void solve()
{
	n=read();
	clr(cnt, 0);
	for(int i=1;i<=n;i++) p[i]=read(),cnt[p[i]%2]++;
	m=read();
	ll ans=0;
	for(int i=1;i<=m;i++){
		int t=read()%2;
		ans+=cnt[t];
	}
	cout<<ans<<endl;
}
int main()
{
	int T=read();
	while(T--) solve();
}