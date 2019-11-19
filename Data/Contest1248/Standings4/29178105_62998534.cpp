#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
LL mod=1000000007;
LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    LL n,m;cin >> n >> m;
    if(n==1&&m==1){
        puts("2");
        return 0;
    }
    LL t = max(n,m);
    LL dp[t+1][2][2];
    memset(dp,0,sizeof(dp));
    dp[1][0][0] = 2;
    for (int i = 1; i < t; i++) {
        for (int j = 0; j < 2; j++) {
            for (int f = 0; f < 2; f++) {
                if(j==0){
                    dp[i+1][0][f] = (dp[i+1][0][f] + dp[i][j][f])%mod;
                    dp[i+1][1][1] = (dp[i+1][1][1] + dp[i][j][f])%mod;
                }
                else{
                    dp[i+1][0][f] = (dp[i+1][0][f] + dp[i][j][f])%mod;
                }
            }
        }
    }
    LL k = min(n,m);
    LL dp1[k+1][2];
    memset(dp1,0,sizeof(dp1));
    dp1[1][0] = 2;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < 2; j++) {
            if(j==0){
                dp1[i+1][0] = (dp1[i+1][0] + dp1[i][j])%mod;
                dp1[i+1][1] = (dp1[i+1][1] + dp1[i][j])%mod;
            }
            else{
                dp1[i+1][0] = (dp1[i+1][0] + dp1[i][j])%mod;
            }
        }
    }
    cout << (dp1[k][1] + dp1[k][0]%mod + dp[t][0][1] + dp[t][1][1]%mod)%mod << endl;
    return 0;
}
