#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
#define ff first
#define dd second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz size()
#define For(i,s,a) for(lld i=(lld)s;i<(lld)a;++i)
#define rpt(s,it) for(auto it=s.begin();it!=s.end();++it)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,lld> pll;
typedef pair<lld,int> pli;		///
typedef pair<int,lld> pil;
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define ZAPS int t;scanf("%d",&t);while(t--)solve();
inline void scan(int *i)
{
	int t=0;
	char z='a';
	while((z<'0')||(z>'9'))z=getchar_unlocked();
	while((z>='0')&&(z<='9'))t=(t<<3ll)+(t<<1ll)+z-'0',z=getchar_unlocked();
	*i=t;
}

inline void scanll(lld *i)
{
	lld t=0;
	char z='a';
	while((z<'0')||(z>'9'))z=getchar_unlocked();
	while((z>='0')&&(z<='9'))t=(t<<3ll)+(t<<1ll)+z-'0',z=getchar_unlocked();
	*i=t;
}

void solve(){
	int n;
	scanf("%i", &n);
	lld c[2]={0,0};
	For(i,0,n){
		int g;
		scanf("%i", &g);
		++c[g&1];
	}
	int m;
	scanf("%i", &m);
	lld d[2]={0,0};
	For(i,0,m){
		int g;
		scanf("%i", &g);
		++d[g&1];
	}
	printf("%lli\n", c[1]*d[1]+c[0]*d[0]);
}






int32_t main(void){
	ZAPS
	
}


















