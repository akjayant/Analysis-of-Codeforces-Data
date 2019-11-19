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

char c[300001];

int solve(int a){
	int tmp=0,wyn=0;
	int minx=0;
	tmp=0;
	For(i,0,a){
		tmp+=c[i]=='('?1:-1;
		minx=min(minx,tmp);
	}
	if(tmp<0)return 0;
	For(i,0,a){
		tmp+=c[i]=='('?1:-1;
		wyn+=tmp==minx;
	}
	return wyn;
}

int32_t main(void){
	int a;
	scanf("%i",&a);
	scanf("%s",c);
	int maxn=solve(a);
	pii tmp = mp(0,0);
	For(i,0,a-1)
	For(j,i,a){
		swap(c[i],c[j]);
		int xd = solve(a);
		if(maxn<xd){
			maxn=xd;
			tmp=mp(i,j);
		}
		swap(c[i],c[j]);
	}
	printf("%i\n",maxn);
	printf("%i %i",tmp.ff+1,tmp.dd+1);
}


















