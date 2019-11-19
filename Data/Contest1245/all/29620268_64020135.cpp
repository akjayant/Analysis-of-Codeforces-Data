#include<bits/stdc++.h>
#define cp complex<double>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXINF=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;
const int MAXN=2005;

int read(){
	int s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

ll readll(){
	ll s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

struct Node{
	int id;
	bool f;
	ll cost;
	int a1,a2;
	Node (int x=0,ll y=0,bool z=0,int u=0,int v=0){
		id=x;
		cost=y;
		f=z;
		a1=u;
		a2=v;
	}
	bool operator <(const Node &x)const{
		return x.cost<cost;
	}
};

priority_queue <Node> q; 

int n,s1,s2,q1[MAXN],q2x[MAXN],q2y[MAXN];
ll x[MAXN],y[MAXN],c[MAXN],k[MAXN],dis[MAXN][MAXN];
bool vis[MAXN];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for (register int i=1;i<=n;++i){
		x[i]=readll();
		y[i]=readll();
	}
	for (register int i=1;i<=n;++i){
		c[i]=readll();
	}
	for (register int i=1;i<=n;++i){
		k[i]=readll();
	}
	for (register int i=1;i<=n;++i){
		for (register int j=i+1;j<=n;++j){
			dis[i][j]=dis[j][i]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
		}
	}
	for (register int i=1;i<=n;++i){
		q.push(Node(i,c[i],1,i,0));
	}
	ll ans=0;
	for (register int i=1;i<=n;++i){
		Node top=q.top();
		q.pop();
		int now=top.id;
		ll w;
		bool ff;
		while (vis[now]){
			top=q.top();
			q.pop();
			now=top.id;
		}
		w=top.cost;
		ff=top.f;
		ans+=w;
		vis[now]=true;
		if (ff){
			q1[++s1]=top.a1;
		}
		else{
			q2x[++s2]=top.a1;
			q2y[s2]=top.a2;
		}
		for (register int i=1;i<=n;++i){
			if (!vis[i]){
				q.push(Node(i,dis[now][i],0,min(now,i),max(now,i)));
			}
		}
	}
	cout<<ans<<endl;
	printf("%d\n",s1);
	for (register int i=1;i<=s1;++i){
		printf("%d ",q1[i]);
	}
	printf("\n%d\n",s2);
	for (register int i=1;i<=s2;++i){
		printf("%d %d\n",q2x[i],q2y[i]);
	}
	return 0;
}

