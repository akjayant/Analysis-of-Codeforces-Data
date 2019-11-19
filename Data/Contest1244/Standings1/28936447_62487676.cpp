#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

#define LL long long
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int INF = 2147483600;
const int MAXN = 300010;

int N; LL c[3][MAXN+1];
int Node[MAXN<<1],Next[MAXN<<1],Root[MAXN+1],cnt;
int deg[MAXN+1],sta[MAXN+1],top;

inline void insert(int u,int v){
	Node[++cnt]=v;Next[cnt]=Root[u]; Root[u]=cnt;
} bool vis[4];
inline int Getn(int x,int y){
	vis[0]=vis[1]=vis[2]=0;
	vis[x]=1; vis[y]=1;
	for(int i=0;i<3;i++) if(!vis[i]) return i;
} int col[MAXN+1];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(int i=0;i<3;i++) for(int j=1;j<=N;j++) c[i][j]=read();
	for(int i=1;i<N;i++){
		int u=read(),v=read();
		insert(u,v); insert(v,u);
		++deg[u]; ++deg[v];
	}  int pt;
	for(int i=1;i<=N;i++){
		if(deg[i]>2){
			puts("-1"); return 0;
		}
		if(deg[i]==1) pt=i;
	}
	int Fa=0;
	while(1){
		int to=0;
		sta[++top]=pt;
		for(int x=Root[pt];x;x=Next[x]){
			if(Node[x]!=Fa){
				to=Node[x]; break;
			}
		} 
		if(!to) break;
		Fa=pt; pt=to;
	} LL ret=1e17;
	int tx,ty;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j) continue;
			int x=i,y=j; LL ans=0;
			ans+=c[i][sta[1]];
			ans+=c[j][sta[2]];
			for(int k=3;k<=N;k++){
				ans+=c[x=Getn(x,y)][sta[k]];
				swap(x,y);
			} if(ans<ret){
				ret=ans; tx=i; ty=j;
			}
		}
	} cout<<ret<<endl;
	col[sta[1]]=tx; col[sta[2]]=ty;
	for(int i=3;i<=N;i++){
		col[sta[i]]=tx=Getn(tx,ty);
		swap(tx,ty);
	}
	for(int i=1;i<=N;i++) printf("%d ",col[i]+1);
	return 0;
}
