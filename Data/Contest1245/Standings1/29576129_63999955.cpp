#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef ONLINE_JUDGE
const int N = 1e6+50;
#else
const int N = 1e2+10;
#endif





int n,a,b,c;
char s[N],pos[N];

void work() {
	scanf("%d%d%d%d",&n,&a,&b,&c);
	scanf("%s",s+1);
	int ans = 0;
	REP(i,0,n+5) pos[i]=0;
	REP(i,1,n) {
		if (s[i]=='R') {
			if (b) --b,++ans,pos[i]='P';
		}
		else if (s[i]=='P') {
			if (c) --c,++ans,pos[i]='S';
		}
		else if (s[i]=='S') {
			if (a) --a,++ans,pos[i]='R';
		}
	}
	REP(i,1,n) if (!pos[i]) { 
		if (a) --a,pos[i]='R';
		else if (b) --b,pos[i]='P';
		else if (c) --c,pos[i]='S';
	}
	if (ans>=(n+1)/2) { 
		puts("YES");
		puts(pos+1);
	}
	else puts("NO");
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) work();
}






