#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int int64_t
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
const int N = 1e5+5;
const int INF = 1e18+7;
const int MOD = 1e9+7;
typedef tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update> SET; // *find_by_order(), order_of_key()

int dp[N][2][2];
int dp2[N][2][2];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("diet.in","r",stdin);
//    freopen("diet.out","w",stdout);
//    setlocale(LC_ALL,"russian");
//    clock_t StartTime = clock();
//    cout<<"Time = "<<(long double)(clock()-StartTime)/CLOCKS_PER_SEC;
    int n,m;
    cin>>n>>m;
    if(n<m) swap(n,m);
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int c=0;c<2;c++){
                for(int pc=0;pc<2;pc++){
                    if(c==pc){
                        if(j==1) continue;
                        dp[i+1][j+1][c]+=dp[i][j][pc];
                        dp[i+1][j+1][c]%=MOD;
                    }else{
                        dp[i+1][0][c]+=dp[i][j][pc];
                        dp[i+1][0][c]%=MOD;
                    }
                }
            }
        }
    }
    int sum1 = dp[n-1][0][0]+dp[n-1][1][0]+dp[n-1][0][1]+dp[n-1][1][1];
    sum1%=MOD;
    dp2[0][0][0]=1;
    dp2[0][0][1]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            for(int c=0;c<2;c++){
                for(int pc=0;pc<2;pc++){
                    if(c==pc){
                        if(j==1) continue;
                        dp2[i+1][j+1][c]+=dp[i][j][pc];
                        dp2[i+1][j+1][c]%=MOD;
                    }else{
                        dp2[i+1][0][c]+=dp[i][j][pc];
                        dp2[i+1][0][c]%=MOD;
                    }
                }
            }
        }
    }
    int sum2 = dp2[m-1][0][0]+dp2[m-1][1][0]+dp2[m-1][0][1]+dp2[m-1][1][1];
    sum2%=MOD;
    cout<<(sum1+sum2-2)%MOD<<endl;
}
