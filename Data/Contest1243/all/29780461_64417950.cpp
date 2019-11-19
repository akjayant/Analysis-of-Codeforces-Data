#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return f?-x:x;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);putchar(x%10+'0');
}
void writeln(ll x){write(x);puts("");}
void writep(ll x){write(x);putchar(' ');}
const int N=100005,M=100005;
int n,m,head[N],opt,A,B,dis[N];
struct info{int to,nxt;}e[M<<1];
void add(int x,int y){
	e[++opt]=(info){y,head[x]};head[x]=opt;
	e[++opt]=(info){x,head[y]};head[y]=opt;
}
queue<int> q;
set<int> s,ss;
set<int>::iterator it;
void bfs2(int st){
	s.clear();ss.clear();
	For(i,1,n) if(i!=st) s.insert(i);
	q.push(st);dis[st]=0;
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int k=e[i].to;
			it=s.find(k);
			if(it!=s.end()) s.erase(it),ss.insert(k);
		}
		for(it=s.begin();it!=s.end();++it){
			int k=*it;
			dis[k]=0;
			q.push(k);
		}
		s=ss;ss.clear();
	}
}
int main(){
	n=read();m=read();
	memset(dis,-1,sizeof(dis));
	For(i,1,m){
		int x=read(),y=read();
		add(x,y);
	}
	int cnt=0;
	For(i,1,n) if(dis[i]==-1){
		++cnt;bfs2(i);
	}
	cout<<cnt-1;
}