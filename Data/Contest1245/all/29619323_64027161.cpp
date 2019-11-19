#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N=2005;
int x[N],y[N],c[N],k[N],f[N];
int s[N],st,tu[N],tv[N];
struct node{
	int u,v;ll s;
	bool operator<(const node &p)const{return s<p.s;}
}d[N*N+N];
int dis(int a,int b){
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
void mg(int x,int y){
	int fa=fd(x),fb=fd(y);
    f[fa]=fb;
}
int main(){
	int n,p=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		f[i]=i;
		d[++p].s=c[i];
		d[p].u=i;d[p].v=n+1;
	}
	for(int i=1;i<=n;i++)scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			d[++p].s=1ll*dis(i,j)*(k[i]+k[j]),
			d[p].u=i,d[p].v=j;
	sort(d+1,d+p+1);
	int cnt=0;ll ans=0;
	for(int i=1;i<=p;i++){
		if(fd(d[i].u)==fd(d[i].v))continue;
		if(d[i].v==n+1)s[++s[0]]=d[i].u;
		else{
			st++;
			tu[st]=d[i].u;
			tv[st]=d[i].v;
		}
		mg(d[i].u,d[i].v);
		ans+=d[i].s;
		cnt++;
		if(cnt==n)break;
	}
	printf("%lld\n",ans);
	printf("%d\n",s[0]);
	for(int i=1;i<=s[0];i++)printf("%d ",s[i]);
	puts("");
	printf("%d\n",st);
	for(int i=1;i<=st;i++)printf("%d %d\n",tu[i],tv[i]);
	return 0;
}
