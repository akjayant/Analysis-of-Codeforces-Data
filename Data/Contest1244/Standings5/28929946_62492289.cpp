#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pr;
#define mpr make_pair
#define int ll
#define case int ___T; scanf("%d", &___T); for(int cas=1;cas<=___T;cas++)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
const ll INF = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
const ll maxn = 1e6+5;
const ll maxm = 1e7;
const ll mod = 1e9+7;

int	dp[maxn][3];
vector<int> vs[maxn];
vector<int> as,tp;
int ans = INF;int st;
void dfs(int s,int pre,int n1,int n2,int num)
{
	if(s==st)
	{
		for(int i=0;i<3;i++){
			n1 = i;
			n2 = -1;
			num = dp[s][i];
			as[s] = i;
			for(int k=0;k<vs[s].size();k++){
				int v = vs[s][k];
				if(v==pre) continue;
				dfs(v,s,n1,n2,num);
			}
		}
	}
	else if(n2==-1){
		for(int i=0;i<3;i++)
		{
			if(i!=n1){
				num += dp[s][i];
				n2 = i;
				as[s] = i;
				for(int k=0;k<vs[s].size();k++){
					int v = vs[s][k];
					if(v==pre) continue;
					dfs(v,s,n1,n2,num);
				}
				num -= dp[s][i];
			}
		}
	}
	else{
		for(int i=0;i<3;i++)
		{
			if(i!=n1&&i!=n2){
				num += dp[s][i];
				as[s] = i;
				for(int k=0;k<vs[s].size();k++){
					int v = vs[s][k];
					if(v==pre) continue;
					dfs(v,s,n2,i,num);
				}
				if(vs[s].size()==1&&s!=st&&num<ans){
					ans = min(ans,num);
					tp = as;
				}
				num -= dp[s][i];
			}
		}
	}
}

signed main()
{
	int n;
	rd(n);
	for(int i=1;i<=n;i++) rd(dp[i][0]);
	for(int i=1;i<=n;i++) rd(dp[i][1]);
	for(int i=1;i<=n;i++) rd(dp[i][2]);
	for(int i=0;i<n-1;i++){
		int x,y;
		rd(x);rd(y);
		vs[x].push_back(y);
		vs[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(vs[i].size()>=3){
			cout<<-1;
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(vs[i].size()==1){
			st = i;
			break;
		}
	}
	for(int i=0;i<=n;i++) as.push_back(0);
	dfs(st,-1,-1,-1,0);
	pt(ans,'\n');
	for(int i=1;i<=n;i++)
		pt(tp[i]+1,' ');
	return 0;
}
