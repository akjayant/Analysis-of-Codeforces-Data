#include<bits/stdc++.h>
typedef long long LL;
typedef double db;
#define REP(i,s,t) for(register int i=s;i<=t;++i)
#define PER(i,s,t) for(register int i=s;i>=t;--i)
#define FOREDGE(i,x,v) for(int i=fir[x],v=to[i];i;i=nex[i],v=to[i])
template<typename T>inline T in(){
    T ans=0;bool b=0;char ch=getchar();
    while(ch<'0'||ch>'9')b=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
    return b?-ans:ans;
}
#define II in<int>()
#define IL in<LL>()
//<-----QAQ----->
const int Mx=2005;
const LL INF=LLONG_MAX/4;
int n;
struct City{int x,y;LL c,k;}C[Mx];
LL dis(City x,City y){return std::abs(x.x-y.x)+std::abs(x.y-y.y);}
struct Edge{int x,y;LL v;}E[Mx*Mx]; 
int top,fa[Mx];
LL ans;
std::vector<int>bld,lnk;
void addEdge(int x,int y,LL v){
	E[++top]=(Edge){x,y,v};
}
bool cmp(Edge a,Edge b){
	return a.v<b.v;
}
int ask(int x){
	return fa[x]==x?x:fa[x]=ask(fa[x]);
}
int main(){
	scanf("%d",&n);
	REP(i,1,n)fa[i]=i;
	REP(i,1,n)scanf("%d%d",&C[i].x,&C[i].y);
	REP(i,1,n)scanf("%lld",&C[i].c);
	REP(i,1,n)scanf("%lld",&C[i].k);
	REP(i,1,n)addEdge(0,i,C[i].c);
	REP(i,1,n){
		REP(j,i+1,n){
			addEdge(i,j,dis(C[i],C[j])*(C[i].k+C[j].k));
		}
	}
	std::sort(E+1,E+1+top,cmp);
	for(int i=1,sum;i<=top;i++){
		int xx=ask(E[i].x);
		int yy=ask(E[i].y);
		if(xx==yy)continue;
		fa[xx]=yy;
		ans+=E[i].v;
		if(E[i].x==0)bld.push_back(E[i].y);
		else lnk.push_back(i);
		sum++;
		if(sum==n)break;
	}
	printf("%lld\n",ans);
	printf("%d\n",bld.size());
	for(int i=0;i<bld.size();++i)printf("%d ",bld[i]);puts("");
	printf("%d\n",lnk.size());
	for(int i=0;i<lnk.size();++i)printf("%d %d\n",E[lnk[i]].x,E[lnk[i]].y);
}