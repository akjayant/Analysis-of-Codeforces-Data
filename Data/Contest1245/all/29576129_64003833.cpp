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


char s[N];
int n,dp[N][2];

int main() {
	scanf("%s",s+1);
	n = strlen(s+1);
	REP(i,1,n) {
		if (s[i]=='m'||s[i]=='w') return puts("0"),0;
	}
	//dp[i][0]不转换,dp[i][1]转换
	dp[0][0] = 1;
	REP(i,1,n) {
		dp[i][0] = (dp[i-1][0]+dp[i-1][1])%P;
		if (s[i]=='n'&&s[i-1]=='n') {
			dp[i][1] = (dp[i-2][0]+dp[i-2][1])%P;
		}
		else if (s[i]=='u'&&s[i-1]=='u') {
			dp[i][1] = (dp[i-2][0]+dp[i-2][1])%P;
		}
	}
	int ans = (dp[n][0]+dp[n][1])%P;
	printf("%d\n",ans);
}






