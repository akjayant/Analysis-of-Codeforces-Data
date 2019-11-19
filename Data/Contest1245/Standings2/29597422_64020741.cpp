#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define MAXN 5000500
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while('0'>ch || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
struct node{
	int x,y,z;
}b[MAXN];
bool cmpp(node t,node u){
	return t.z<u.z;
}
int n,m,cnt,tx[2050],ty[2050],f[2050],fa[2050],ans,num,c[2050],tmp,d[2050],e[2050];
void work(int i){
	if(b[i].x==0) c[++num]=b[i].y;
	else ++tmp,d[tmp]=b[i].x,e[tmp]=b[i].y;
	ans+=b[i].z;
    cnt++;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return 0;
    fa[fx]=fy;
    return 1;
}
main(){
    n=read();
    rep(i,1,n) tx[i]=read(),ty[i]=read();
    rep(i,1,n){
    	int x=read();
    	b[++m]=(node){0,i,x};
	}
	rep(i,1,n) f[i]=read();
	rep(i,1,n) rep(j,i+1,n) b[++m]=(node){i,j,(f[i]+f[j])*(abs(tx[i]-tx[j])+abs(ty[i]-ty[j]))};
	sort(b+1,b+m+1,cmpp);
	rep(i,0,n) fa[i]=i;
	rep(i,1,m){
		if(cnt==n) break;
		if(merge(b[i].x,b[i].y)) work(i);
	}
	printf("%lld\n%lld\n",ans,num);
	rep(i,1,num) cout<<c[i]<<" ";cout<<endl;
	printf("%lld\n",tmp);
	rep(i,1,tmp) cout<<d[i]<<" "<<e[i]<<endl;
	return 0;
}
