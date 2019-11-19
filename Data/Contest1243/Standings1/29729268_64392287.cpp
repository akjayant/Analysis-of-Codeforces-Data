#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define INF 2147483647
#define LLINF 9223372036854775807
#define xyx AKIOI
#define Dilute AKIOI
#define Chtholly_Tree AKIOI
#define time_interspace AKIOI
#define memset0 AKIOI
#define Isonan AKIOI
#define Sooke AKIOI
#define yeID AKIOI
#define _szh_ AKIOI
#define scimoon AKIOI
#define xay5421 AKIOI
#define dzh caibi
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
const int maxn=100010;
int n,cnt,m;
int fa[maxn],b[maxn],head[maxn];
struct Edge{int nxt,to;}edge[maxn<<1];
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
void add_edge(int x,int y){edge[++cnt].nxt=head[x];edge[cnt].to=y;head[x]=cnt;}
vector<int>s;vector<int>res;int h[maxn];
int bfs(int x){
	int tot=0;queue<int>que;que.push(x);h[x]=1;
	while(!que.empty()){
		int x=que.front();b[x]=1;tot++;que.pop();
		for(int i=head[x];i;i=edge[i].nxt)h[edge[i].to]=1;
		vector<int>tmp=s;s.clear();
		for(int i=0;i<tmp.size();i++){
			if(h[tmp[i]])s.push_back(tmp[i]);else que.push(tmp[i]);
		}
		for(int i=head[x];i;i=edge[i].nxt)h[edge[i].to]=0;
	}return tot;
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add_edge(u,v);add_edge(v,u);
	}for(int i=1;i<=n;i++)s.push_back(i);
	int ans=0;for(int i=1;i<=n;i++)if(b[i]==0)res.push_back(bfs(i));cout<<res.size()-1<<endl;
	return 0;
}