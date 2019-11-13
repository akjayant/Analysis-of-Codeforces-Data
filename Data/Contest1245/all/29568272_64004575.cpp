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
const int sz=1009;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll a,b,c;
ll A,B,C;
ll rema,remb,remc;
char s[sz];
char t[sz];
int main(){
	int _=readll();
	while(_--){
		int n=readll();
		a=readll(),b=readll(),c=readll();
		A=B=C=0;
		scanf("%s",s);
		rep(i,0,n){
			if(s[i]=='S') A++;
			if(s[i]=='R') B++;
			if(s[i]=='P') C++;
		}
		// LOG(a,b,c);
		// LOG(A,B,C);
		ll ma=min(a,A);
		ll mb=min(b,B);
		ll mc=min(c,C);
		ll win=ma+mb+mc;
		rema=a-min(a,A);
		remb=b-min(b,B);
		remc=c-min(c,C);
		rep(i,0,n){
			if(s[i]=='S'&&ma){
				t[i]='R';ma--;
			}else if(s[i]=='R'&&mb){
				t[i]='P';mb--;
			}else if(s[i]=='P'&&mc){
				t[i]='S';mc--;
			}else{
				if(rema) t[i]='R',rema--;
				else if(remb) t[i]='P',remb--;
				else if(remc) t[i]='S',remc--;
			}
		}
		t[n]='\0';
		// LOG(win);
		if(win>=(n+1)/2){
			puts("YES");
			puts(t);
		}else{
			puts("NO");
		}
	}
	return 0;
}
/*
2
 3
 1 1 1
RPS
3
3 0 0
RPS

*/