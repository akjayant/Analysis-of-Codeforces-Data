#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int MN = 3e5 + 5;
const int P = 998244353;

int c[5][MN],ans[10][MN];
ll sm[10];

int n,m,tot=1;	//�������������ߺ�
int fst[MN],to[MN<<1],nxt[MN<<1],val[MN<<1],deg[MN];

inline void add(int x,int y,int v=0){
	to[++tot] =y;
//	val[tot] =v;
	nxt[tot] =fst[x];
	fst[x] =tot;
}

bool inv[MN];
vector<int>v;
void init(int x,int f){
	v.push_back(x);
	for(int i=fst[x]; i; i=nxt[i]){
		int y=to[i];
		if(y==f)continue;
		init(y,x);
	}
}

inline void solve(){
	int n; scanf("%d",&n);
	for__(i,1,3) for__(j,1,n) scanf("%d",c[i]+j);
	for_(i,1,n){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y), add(y,x);
		++deg[x],++deg[y];
	}
	int stt=0;
	for__(i,1,n){
		if(deg[i]>2) return puts("-1"), void();
		if(deg[i]==1) stt=i;
	}
	v.reserve(n+5);
	v.push_back(0);
	init(stt,stt);
//for__(i,1,n) printf("%d ",v[i]);
	ans[1][v[1]]=ans[2][v[1]]=ans[3][v[2]]=ans[5][v[2]]=1;
	ans[1][v[2]]=ans[3][v[1]]=ans[4][v[1]]=ans[6][v[2]]=2;
	ans[2][v[2]]=ans[4][v[2]]=ans[5][v[1]]=ans[6][v[1]]=3;
//	ans[1][1]=ans[2][1]=ans[3][2]=ans[4][3]=ans[5][2]=ans[6][3]=1;
//	ans[1][2]=ans[2][3]=ans[3][1]=ans[4][1]=ans[5][3]=ans[6][2]=2;
//	ans[1][3]=ans[2][2]=ans[3][3]=ans[4][2]=ans[5][1]=ans[6][1]=3;
	for__(i,1,6){
		for__(j,3,n) ans[i][v[j]]=6-ans[i][v[j-1]]-ans[i][v[j-2]];
		for__(j,1,n) sm[i]+=c[ans[i][v[j]]][v[j]];
	}
	ll mi=1;
	for__(i,2,6) if(sm[i]<sm[mi]) mi=i;
	printf("%lld\n",sm[mi]);
	for__(i,1,n) printf("%d ",ans[mi][i]);
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}
