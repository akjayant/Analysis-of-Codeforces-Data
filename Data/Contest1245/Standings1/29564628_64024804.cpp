#include<bits/stdc++.h>
#define maxn 2005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll nx[maxn],ny[maxn],w[maxn];
ll d[maxn][maxn],dis[maxn],frm[maxn];

inline ll read(){
    ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	memset(d,127,sizeof(d));
	ll n=read(),ans=0;
	for(ll i=1;i<=n;i++) nx[i]=read(),ny[i]=read();
	for(ll i=1;i<=n;i++) d[0][i]=d[i][0]=read();
	for(ll i=1;i<=n;i++) w[i]=read();
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++)
			d[i][j]=d[j][i]=(w[i]+w[j])*(abs(nx[i]-nx[j])+abs(ny[i]-ny[j]));
	memset(dis,127,sizeof(dis)),dis[0]=0;
	for(int nd=0;;){
		for(ll i=1;i<=n;i++){
			if(dis[i]==-1) continue;
			if(dis[i]>d[nd][i]) dis[i]=d[nd][i],frm[i]=nd;
		}
		ans+=dis[nd],dis[nd]=-1;
		for(ll i=1;i<=n;i++){
			if(dis[i]==-1) continue;
			if(dis[nd]==-1 || dis[i]<dis[nd]) nd=i;
		}
		if(dis[nd]==-1) break;
	}
	cout<<ans<<endl;
	ll r1=0,r2=0;
	for(ll i=1;i<=n;i++){
		if(frm[i]) r1++; 
		else r2++;
	}
	cout<<r2<<endl;
	for(ll i=1;i<=n;i++)
		if(!frm[i]) cout<<i<<" ";
	cout<<endl<<r1<<endl;
	for(ll i=1;i<=n;i++) if(frm[i]) cout<<i<<" "<<frm[i]<<endl;
	return 0;
}
