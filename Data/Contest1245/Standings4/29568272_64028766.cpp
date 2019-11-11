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
const int sz=2e5+9;
const ll M=1e9+7;
ll f[sz];
char s[sz];
ll solve(){
	ll n=strlen(s);
	char last=0;int len=0;
	ll ans=1;
	rep(i,0,n){
		if(s[i]=='w'||s[i]=='m') return 0;
		if(s[i]!=last) {
			//calc
			if(last=='n'||last=='u') ans=(ans*f[len])%M;
			last=s[i];len=1;
		}else{
			len++;
		}
	}
	if(last=='n'||last=='u') ans=(ans*f[len])%M;
	return ans%M;
}
int main(){
	scanf("%s",s);
	f[0]=1;f[1]=1;
	rep(i,2,2e5){
		f[i]=(f[i-1]+f[i-2])%M;
	}
	ll ans=solve();
	cout<<ans<<endl;
	return 0;
}