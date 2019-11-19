#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>

#define fuck(x) cerr<<#x<<" = "<<x<<endl;
#define debug(a, x) cerr<<#a<<"["<<x<<"] = "<<a[x]<<endl;
#define lson l,mid,ls
#define rson mid+1,r,rs
#define ls (rt<<1)
#define rs ((rt<<1)+1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int loveisblue = 486;
const int maxn = 200086;
const int maxm = 1200086;
const int inf = 0x3f3f3f3f;
const ll Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);

char s[maxn];
int dp[maxn];
int main() {
    ios::sync_with_stdio(true);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int ans = 0;

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            if(s[i]=='1'){
                dp[i]=max(dp[i],dp[i-1]+2);
            }
        }

        for(int i=0;i<=n;i++){
                ans=max(ans,dp[i]+n-i);
            for(int j=i+1;j<=n;j++){
                if(s[j]=='0'){continue;}
                ans = max(ans,dp[i]+(n-i+1));
                ans = max(ans,dp[i]+(j-i)*2);
            }
        }

        reverse(s+1,s+1+n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            if(s[i]=='1'){
                dp[i]=max(dp[i],dp[i-1]+2);
            }
        }

        for(int i=0;i<=n;i++){
                ans=max(ans,dp[i]+n-i);
            for(int j=i+1;j<=n;j++){
                if(s[j]=='0'){continue;}
                ans = max(ans,dp[i]+(n-i+1));
                ans = max(ans,dp[i]+(j-i)*2);
            }
        }




        printf("%d\n",ans);

    }

    return 0;
}
