#include <bits/stdc++.h>

using namespace std;

#define int long long
#define reg register
#define clr(a,b) memset(a,b,sizeof a)
#define Mod(x) (x>=mod)&&(x-=mod)
#define abs(a) ((a)<0?-(a):(a))
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define debug2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define debug3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
#define rep(a,b,c) for(reg int a=(b),a##_end_=(c); a<=a##_end_; ++a)
#define ret(a,b,c) for(reg int a=(b),a##_end_=(c); a<a##_end_; ++a)
#define drep(a,b,c) for(reg int a=(b),a##_end_=(c); a>=a##_end_; --a)
#define erep(i,G,x) for(int i=(G).Head[x]; i; i=(G).Nxt[i])
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(3,"Ofast","inline")

inline int Read(void) {
	int res = 0, f = 1;
	char c;
	while (c = getchar(), c < 48 || c > 57)if (c == '-')f = 0;
	do res = (res << 3) + (res << 1) + (c ^ 48);
	while (c = getchar(), c >= 48 && c <= 57);
	return f ? res : -res;
}

template<class T>inline bool Min(T &a, T const&b) {
	return a > b ? a = b, 1 : 0;
}
template<class T>inline bool Max(T &a, T const&b) {
	return a < b ? a = b, 1 : 0;
}

const int N=1e5+5;

int n,m,cost[N][3],fa[N];

vector<int>a[N];

bool bo=1;

void dfs(int x,int f) {
	fa[x]=f;
	if(!bo)return;
	if(a[x].size()>=3) {
		bo=0;
		return;
	}
	ret(i,0,a[x].size()) {
		int y=a[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
}

int col[N],res,ans=1e18,col1[N];

void dfs1(int x) {
	int f1=fa[x],f2=fa[fa[x]];
	col[x]=3-col[f1]-col[f2];
	res+=cost[x][col[x]];
	ret(i,0,a[x].size()) {
		int y=a[x][i];
		if(y==fa[x])continue;
		dfs1(y);
	}
}

void Copy() {
	rep(i,1,n)col1[i]=col[i]+1;
}

void solve1() {
	int x=a[1][0];
	ret(i,0,3)ret(j,0,3)if(i^j) {
		res=cost[1][i]+cost[x][j];
		col[1]=i,col[x]=j;
		ret(k,0,a[x].size()) {
			int y=a[x][k];
			if(y==1)continue;
			dfs1(y);
		}
		if(res<ans)ans=res,Copy();
	}
	printf("%lld\n",ans);
	ret(i,1,n)printf("%lld ",col1[i]);
	printf("%lld\n",col1[n]);
}

void solve2() {
	int x1=0,x2=0;
	ret(i,0,a[1].size()) {
		int x=a[1][i];
		if(x1==0)x1=x;
		else if(x2==0)x2=x;
	}
	ret(i,0,3)ret(j,0,3)if(i^j)ret(k,0,3)if(i!=k&&j!=k) {
			res=cost[1][i]+cost[x1][j]+cost[x2][k];
			col[1]=i,col[x1]=j,col[x2]=k;
			ret(l,0,a[x1].size()) {
				int y=a[x1][l];
				if(y==1)continue;
				dfs1(y);
			}
			ret(l,0,a[x2].size()) {
				int y=a[x2][l];
				if(y==1)continue;
				dfs1(y);
			}
			if(res<ans)ans=res,Copy();
		}
	printf("%lld\n",ans);
	ret(i,1,n)printf("%lld ",col1[i]);
	printf("%lld\n",col1[n]);
}

signed main() {
	n=Read();
	rep(i,1,n)cost[i][0]=Read();
	rep(i,1,n)cost[i][1]=Read();
	rep(i,1,n)cost[i][2]=Read();
	rep(i,2,n) {
		int x=Read(),y=Read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	if(!bo) {
		puts("-1");
		return 0;
	}
	if(a[1].size()==1)solve1();
	else solve2();
	return 0;
}