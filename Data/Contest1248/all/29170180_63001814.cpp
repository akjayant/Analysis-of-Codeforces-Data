#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 3e5+5;
const int mxm = 3e5+5 ;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dp[mxn],c[mxn];

int M(int x){
    return (x%mod+mod)%mod;
    }

signed main(){
    int n,m;
    scanf("%lld%lld",&n,&m);

    dp[1]=2,dp[2]=4;
    for(int i=3;i<=max(n,m)+5;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    int res = M(dp[n]+dp[m] - 2);
    printf("%lld",res);
    return 0;
}
