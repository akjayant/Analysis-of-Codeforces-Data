#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu_alter
const int N=1e5+5;
int n,a[3][N],an[N];
vector<int>g[N];
//
inline bool isline(){
	int c=0;
	rep(i,n)if(g[i].size()>2)return false;
	else if(g[i].size()==1)++c;
	return c<=2;
}
ll go(int x,int p,int c,int cp){
	ll ans=a[c][x];
	rep(i,g[x].size()){
		int to=g[x][i];
		if(to==p)continue;
		ans+=go(to,x,3-c-cp,c);
	}
	return ans;
}
void doit(int x,int p,int c,int cp){
	an[x]=c;
	rep(i,g[x].size()){
		int to=g[x][i];
		if(to==p)continue;
		doit(to,x,3-c-cp,c);
	}
}
const ll inf=2e18;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=getint();
	rep(i,3)rep(j,n)a[i][j]=getint();
	rep(i,n-1){
		int x=getint()-1,y=getint()-1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(!isline()){
		return !printf("%d\n",-1);
	}
	rep(i,n)if(g[i].size()==1){
		ll res=inf;
		rep(j,3)rep(k,3)if(j!=k){
			ll tmp=go(i,-1,j,k);
			if(tmp<res){
				res=tmp;
				doit(i,-1,j,k);
			}
		}
		cout<<res<<endl;
		rep(i,n)printf("%d ",an[i]+1);
		break;
	}
	return 0;
}