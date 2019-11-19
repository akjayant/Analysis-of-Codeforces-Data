#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long 
using namespace std;
const int maxn = 2e3+10;
const int mod = 1e9+7;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int m,n,cnt=0;
struct node{
	int x,y;
}a[maxn],ans[maxn*maxn];
int dis[maxn][maxn];
int c[maxn],k[maxn],fa[maxn];
int find(int x){
	if(x==fa[x])return x;	
	return x=find(fa[x]);
}

struct L {
	int l,r,C;
}line[maxn*maxn];

int cmp(L x,L y){
	return x.C<y.C;
}
int tot=0,summ[maxn],num=0;
signed main(){
	n=read();
	for(register int i=1;i<=n;i++){
		a[i].x=read();a[i].y=read();
	}
	for(register int i=0;i<=n;i++)fa[i]=i;
	for(register int i=1;i<=n;i++){c[i]=read();line[++tot]=(L){0,i,c[i]};}
	for(register int i=1;i<=n;i++)k[i]=read();
	for(register int i=1;i<=n;i++){
		for(register int j=i+1;j<=n;j++){
			line[++tot]=(L){i,j,(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(k[i]+k[j])};
		}
	}
	sort(line+1,line+tot+1,cmp);
	int anss=0,numm=0;
	for(register int i=1;i<=tot;i++){
		int x=line[i].l,y=line[i].r;
		if(find(x)!=find(y)){
			fa[find(x)]=find(y);
			anss+=line[i].C;numm++;
			if(x==0 || y==0)summ[++num]=x+y;
			else ans[++cnt]=(node){x,y};
			if(numm==n)break;
		}
	}
	printf("%lld\n",anss);
	printf("%lld\n",num);
	for(register int i=1;i<=num;i++)printf("%lld ",summ[i]);puts("");
	printf("%lld\n",cnt);
	for(register int i=1;i<=cnt;i++)printf("%lld %lld\n",ans[i].x,ans[i].y);
	return 0;
}