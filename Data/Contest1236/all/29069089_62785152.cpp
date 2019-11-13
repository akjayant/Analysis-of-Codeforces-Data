#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/

int dp[105][105][105];

int main(){

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            for(int k = 0; k <= 100; k++){
                int &ret = dp[i][j][k];

                ret = 0;
                if(i >= 1 && j >= 2){
                    ret = max(ret, dp[i - 1][j - 2][k] + 3);
                }

                if(j >= 1 && k >= 2){
                    ret = max(ret, dp[i][j - 1][k - 2] + 3);
                }
            }
        }
    }

    int t; cin >> t;

    while(t--){
        int a, b, c; cin >> a >> b >> c;

        cout << dp[a][b][c] << "\n";
    }
}
