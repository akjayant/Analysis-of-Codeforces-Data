#include<bits/stdc++.h>
#define LL long long int
#define FIO ios::sync_with_stdio(false)
#define FRD freopen("input.txt","r",stdin)
#define lowbit(x) (x&-(x))
#define INF 1e18
#define ms(x) memset(x,0,sizeof x)
#define pb(x) push_back(x)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
#define UNIQUE(x) unique(x.begin(),x.end())
#define SORT(x) sort(x.begin(),x.end())
#define LISAN(x) x.erase(UNIQUE(x),x.end())
#define pii pair<int,int>
#define pll pair<LL,LL>
#define N 200010
const LL MOD=1e9+7;
using namespace std;
template<class T> inline T Min(const T& a,const T& b){return a<b?a:b;}
template<class T> inline T Max(const T& a,const T& b){return a<b?b:a;}
inline void inc(int &x,int &v,int &mod){x+=v;if(x>=mod) x-=mod;}
inline void dec(int &x,int &v,int &mod){x-=v;if(x<0) x+=mod;}
inline int read(){char ch = getchar();int x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline LL readl(){char ch = getchar();LL x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
vector<int> vec[N];
int dfn[N],tot;
void dfs(int x,int fa){
	dfn[++tot]=x;
	for(auto to:vec[x]){
		if(to==fa)	continue;
		dfs(to,x);
	}
}
LL cost[10][N];
int col[10]={0,1,2,3};
int id[N];
int main(){
	#ifndef ONLINE_JUDGE
    	int startTime = clock();
		FRD;
	#endif
	int n=read();
	for(int i=1;i<=n;i++)
		cost[1][i]=read();
	for(int i=1;i<=n;i++)
		cost[2][i]=read();
	for(int i=1;i<=n;i++)
		cost[3][i]=read();
	bool tag=true;
	int rt=1;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		vec[u].pb(v);
		vec[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(vec[i].size()>2){
			tag=false;
		}
		if(vec[i].size()==1)	rt=i;
	}
	if(!tag){
		cout<<"-1\n";
		return 0;
	}
	else{
		dfs(rt,rt);
		LL ans=1e18;
		do{
			int cnt=1;
			LL sum=0;
			for(int i=1;i<=tot;i++){
				sum+=cost[col[cnt]][dfn[i]];
				cnt++;
				if(cnt==4)	cnt=1;
			}
			if(sum<ans){
				ans=sum;
				for(int i=1;i<=n;i++){
					id[dfn[i]]=col[(i-1)%3+1];
				}
			}
		}while(next_permutation(col+1,col+1+3));
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
			cout<<id[i]<<' ';
	}
	#ifndef ONLINE_JUDGE
    	printf("Time = %dms\n", clock() - startTime);
	#endif
	return 0;
}









