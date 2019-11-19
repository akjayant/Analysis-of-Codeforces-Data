/*
* @Author: XiaoBanni
* @Email:  xjc5069@gmail.com
* @Date:   2019-11-01 23:59:08
* @Last Modified by:   Y
* @Last Modified time: 2019-11-01 23:59:08
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef priority_queue<int> maxpque;
typedef priority_queue<int,vector<int>,greater<int> > minpque;
const int MAXN = 1e5+5;
const int INF=INT_MAX/2;
const ll LLINF=9223372036854775807/2;
#define in(a) scanf("%d",&a)
#define inll(a) scanf("%lld",&a)
#define out(a) printf("%d",a)
#define outll(a) printf("%lld",a)
#define outln(a) printf("%d\n",a)
#define outllln(a) printf("%lld\n",a)
#define fin(i,st,n) for(int i=st;i<n;i++)
#define fin2(i,st,n) for(int i=st;i<=n;i++)
#define c(a) cout<<"***"<<a<<endl;
#define mk make_pair
#define pb push_back
#define f first
#define s second
#define maxpque(type) priority_queue<type>
#define minpque(type) priority_queue<type,vector<type>,greater<type> > //pay attention that no ',' in type
#define gcd __gcd
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0); 

const int MAX_V=2005;

ll cost[MAX_V][MAX_V];//cost[u][v]表示边e=(u,v)的权值(不存在的情况下设为INF)
ll mincost[MAX_V];//从集合X出发的边到每个顶点的最小权值
int belong[MAX_V];
bool used[MAX_V];//顶点i是否包含在集合X中
int V;//顶点数

vector<int> base;
vector<pint> connect;

ll prim(){
	for(int i=0;i<V;i++){
		mincost[i]=LLINF;
		used[i]=false;
	}
	mincost[0]=0;
	ll res=0;

	while(true){
		int v=-1;
		//从不属于X的顶点中选取从X到其权值最小的顶点
		for(int u=0;u<V;u++){
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
		}
		if(v==-1)break;
		used[v]=true;//把顶点v加入X
		res+=mincost[v];//把边的长度加到结构里
		if(v!=0&&belong[v]!=0){
			connect.push_back(mk(v,belong[v]));
		}
		else{
			if(max(v,belong[v])!=0)
				base.push_back(max(v,belong[v]));
		}
		for(int u=0;u<V;u++){
			if(mincost[u]>cost[v][u]){
				mincost[u]=min(mincost[u],cost[v][u]);
				belong[u]=v;
			}
			//因为新添加了v，所以用v更新所有的点到已有树的最小权值
		}
	}
	return res;
}

struct point
{
	int x,y;
}graph[MAX_V];
ll c[MAX_V];
ll k[MAX_V];

ll cal(int i,int j){
	point ii=graph[i];
	point jj=graph[j];
	return 1ll*(abs(ii.x-jj.x)+abs(ii.y-jj.y))*(k[i]+k[j]);
}

int main(){
	int n;
	in(n);
	V=n+1;
	int x,y;
	fin2(i,1,n){
		in(x);in(y);
		graph[i]={x,y};
	}
	fin2(i,0,n) belong[i]=-1;
	fin2(i,1,n) inll(c[i]);
	fin2(i,1,n) inll(k[i]);
	fin2(i,1,n){
		fin2(j,1,n){
			if(i==j) continue;
			cost[i][j]=cal(i,j);
		}
	}
	fin2(i,1,n){
		cost[0][i]=c[i];
	}
	ll res=prim();
	outllln(res);
	outln(base.size());
	for(auto e:base){
		printf("%d ",e);
	}
	printf("\n");
	outln(connect.size());
	for(auto e:connect){
		printf("%d %d\n",e.first,e.second);
	}
	return 0;
}