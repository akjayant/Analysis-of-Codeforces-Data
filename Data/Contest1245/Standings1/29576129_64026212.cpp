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

ll f[33][2][2];
//求0<=i<=x,0<=j<=y,i+j=i^j的个数
ll calc(int x, int y) {
	memset(f,0,sizeof f);
	f[31][1][1] = 1;
	PER(i,0,30)REP(a1,0,1)REP(a2,0,1) {
		ll &r = f[i+1][a1][a2];
		if (!r) continue;
		int l1=a1&&!(x>>i&1),l2=a2&&!(y>>i&1);
		REP(b1,0,1) REP(b2,0,1) {
			if (l1&&b1) continue;
			if (l2&&b2) continue;
			if ((b1^b2)!=b1+b2) continue;
			int c1=a1&&b1>=(x>>i&1),c2=a2&&b2>=(y>>i&1);
			f[i][c1][c2]+=r;
		}
	}
	ll ans = 0;
	REP(i,0,1)REP(j,0,1) ans+=f[0][i][j];
	return ans;
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int l,r;
		scanf("%d%d",&l,&r);
		if (l==0&&r==0) {
			puts("1");
			continue;
		}
		ll ans = 0;
		if (l==0) ans += 2*r+1,++l;
		ans += calc(r,r)+calc(l-1,l-1)-2ll*calc(l-1,r);
		printf("%lld\n",ans);
	}
}







