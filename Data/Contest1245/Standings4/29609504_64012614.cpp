#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
typedef pair<int,int> pr;
#define mpr make_pair
#define int ll
#define case int ___T; scanf("%d", &___T); for(int cas=1;cas<=___T;cas++)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
const ll INF = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
const ll maxn = 1e6+5;
const ll maxm = 1e7;
const ll mod = 1e9+7;

int dp[maxn];
char uu[maxn];

signed main()
{
	scanf("%s",&uu);
	int n = strlen(uu);
	dp[1] = 1;dp[2] = 2;
	for(int i=3;i<=n;i++) dp[i] = (dp[i-1]+dp[i-2])%mod;
	int pre = -1;
	char s;
	int ans = 1;
	for(int i=0;i<n;i++)
	{
		if(uu[i]=='u'){
			int j;
			for(j=i;j<n;j++){
				if(uu[j]!='u') break;
			}
			ans = ans * dp[j-i]%mod;
			i = j-1;
		}
		if(uu[i]=='n'){
			int j;
			for(j=i;j<n;j++){
				if(uu[j]!='n') break;
			}
			ans = ans * dp[j-i]%mod;
			i = j-1;
		}
		if(uu[i]=='m'||uu[i]=='w') ans = 0;
	}
	cout<<ans;
	
	return 0;
}
