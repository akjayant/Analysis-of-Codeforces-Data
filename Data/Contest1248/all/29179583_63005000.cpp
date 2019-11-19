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

vector<int>c[1000001],rc[1000001];
int stos[1000001],_end;
bitset<1000001>odw;
int kol[1000001];
int ss[1000001];

void dfs(int x){
	odw[x]=1;
	for(auto s:c[x])if(!odw[s])dfs(s);
	stos[++_end]=x;
}

void rfs(int x, int d){
	kol[x]=d;
	for(auto s:rc[x])if(!kol[s])rfs(s,d);
}

void solve(){
	int a,b;
	scanf("%d%d", &a,&b);
	For(i,0,b){
		int g,h;
		scanf("%d%d", &g,&h);
		c[g].pb(h);
		rc[h].pb(g);
	}
	For(i,1,a+1)if(!odw[i])dfs(i);
	int all = 0;
	while(_end){
		if(!kol[stos[_end]])rfs(stos[_end],stos[_end]);
		--_end;
	}
	
	For(x,1,a+1)for(auto s:c[x])if(kol[s]!=kol[x])++ss[kol[x]];
	bool ok = 0;
	For(i,1,a+1)if(kol[1]!=kol[i]){
		ok=1;break;
	}
	if(ok){ok=0;
	For(i,1,a+1){
		if(ss[kol[i]]==0){
			vector<int>wyn;
			vector<int>jud;
			For(x,1,a+1)if(kol[x]==kol[i])jud.pb(x);
			For(x,1,a+1)if(kol[x]!=kol[i])wyn.pb(x);
			puts("YES");
			printf("%i %i\n",(int)jud.sz,(int)wyn.sz);
			for(auto s:jud)printf("%i ",s);
			puts("");
			for(auto s:wyn)printf("%i ",s);
			ok=1;
			puts("");
			break;
		}
	}}
	if(!ok)puts("NO");
	For(i,1,a+1)c[i].clear(),rc[i].clear(),odw[i]=0,kol[i]=ss[i]=0;
	_end=0;
	
}

int32_t main(void){
	ZAPS
}
