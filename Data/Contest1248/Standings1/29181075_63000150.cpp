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
const int sz=600;
int n;
char s[sz];
int f[sz];
int check(){
	rep(i,1,n+1){
		f[i]=f[i-1];
		if(s[i-1]=='(') f[i]++;
		else f[i]--;
	}
	if(f[n]) return 0;
	int minn=*min_element(f+1,f+n+1);
	int cnt=0;
	rep(i,1,n+1) if(f[i]==minn) cnt++;
	return cnt;
}
void solve(){
	int a=0,b=0,c=-1;
	rep(i,0,n){
		rep(j,0,n){
			if(i!=j) swap(s[i],s[j]);
			int kk=check();
			if(i!=j) swap(s[i],s[j]);
			if(kk>c) a=i,b=j,c=kk;
		}
	}
	printf("%d\n%d %d\n",c,a+1,b+1);

}

int main(){
	n=readll();
	scanf("%s",s);
	solve();
	return 0;
}