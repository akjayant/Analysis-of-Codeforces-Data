#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sd(T&x){
	char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c==45)y=-1;x=c-48;
	while(c=gc(),47<c&&c<58)x=x*10+c-48;x*=y;
}
const int N=1e6+5;
typedef int arr[N];
typedef long long ll;
int n,m,Cnt;arr col;
vector<int>a[N],b[N];
void dfs(int u){
	col[u]=Cnt;
	for(auto v:a[u])if(!col[v])
		dfs(v);
}
inline void sol(){
	sd(n),sd(m);
	fp(i,1,n)a[i].clear(),b[i].clear();
	fp(i,1,m){
		int x,y;
		sd(x),sd(y);
		a[x].push_back(y);
		b[y].push_back(x);
	}
	Cnt=0;
	fp(i,1,n)col[i]=0;
	fp(i,1,n)if(!col[i])
		++Cnt,dfs(i);
	if(Cnt>1){
		puts("Yes");
		int Jury=0;
		fp(i,1,n)if(col[i]==1)++Jury;
		printf("%d %d\n",Jury,n-Jury);
		fp(i,1,n)if(col[i]==1)printf("%d ",i);puts("");
		fp(i,1,n)if(col[i]!=1)printf("%d ",i);puts("");
		return;
	}
	Cnt=0;
	fp(i,1,n)col[i]=0,swap(a[i],b[i]);
	fp(i,1,n)if(!col[i])
		++Cnt,dfs(i);
	if(Cnt>1){
		puts("Yes");
		int Contestants=0;
		fp(i,1,n)if(col[i]==1)++Contestants ;
		printf("%d %d\n",n-Contestants,Contestants);
		fp(i,1,n)if(col[i]!=1)printf("%d ",i);puts("");
		fp(i,1,n)if(col[i]==1)printf("%d ",i);puts("");
		return;
	}
	puts("No");
}
int main(){
	#ifndef ONLINE_JUDGE
		file("s");
	#endif
	int q;sd(q);
	while(q--)sol();
return 0;
}