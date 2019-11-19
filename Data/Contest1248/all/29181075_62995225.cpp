#include <stdio.h>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
// #include <unordered_map>
#define SZ(a) ((int)(a.size()))
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
#ifdef LOCAL
template<class T>void print_array(T *a,T *end){printf("#[");for(;a<end;++a)cout<<(*a)<<',';cout<<"\b]\n";};
template<class T>ostream &operator<<(ostream&os,vector<T>V){os<<"[";for(auto vv:V)os<<vv<<",";return os<<"\b]";}
void dbg(){cout<<"\b \n";}
template<typename T,typename...A>void dbg(T a,A...x){cout<<(a)<<',';dbg(x...);}
#define LOG(x...) {cout<<'#';dbg(x);}
#else
#define print_array(...)
#define LOG(...)
#endif
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}
//const int sz=;
const ll M=1e9+7;
int x[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool check(ll a,ll b){
	rep(i,1,a+1){
		rep(j,1,b+1){
			int same=0;
			rep(k,0,4){
				if(x[i][j]==x[i+dx[k]][j+dy[k]]) same++;
			}
			if(same>=2) return false;
		}
	}
	return true;
}
ll bt(ll a,ll b){
	mem(x,-1);
	ll ans=0;
	rep(S,0,1LL<<(a*b)){
		ll s=S;
		rep(i,1,a+1){
			rep(j,1,b+1){
				x[i][j]=(s&1);
				s>>=1;
			}
		}
		ans+=check(a,b);
	}
	return ans;
}
const int sz=100009;
ll dp[sz][2][2],f[sz];
void pre(){
	dp[1][0][1]=dp[1][1][0]=1;
	f[1]=2;
	rep(i,2,sz){
		dp[i][0][0]=dp[i-1][1][0];
		dp[i][1][1]=dp[i-1][0][1];
		dp[i][1][0]=(dp[i-1][0][1]+dp[i-1][1][1])%M;
		dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][1][0])%M;
		f[i]=(dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1])%M;
	}
	// print_array(f,f+20);
}
int main(){
	pre();
	// ll x,y;
	// rep(i,1,10){
	// 	rep(j,1,10){
	// 		printf("%5d ",bt(i,j));
	// 	}
	// 	puts("");
	// }
	// while(cin>>x>>y){
	// 	LOG(bt(x,y));
	// }
	// while(true){
	ll a=readll(),b=readll();
	printf("%I64d\n",(f[a]+f[b]-2+M)%M);
		
	// }
	return 0;
}