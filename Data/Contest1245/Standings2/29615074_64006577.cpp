#define IOS ios::sync_with_stdio(false);
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int M = 3e5 + 7;
const int INF = 1e8 + 7;
ll mod = 1e9 + 7;

int n;
ll dp[N];
char s[N];


int main(){

    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }
    }


    dp[0] = 1;
    for(int i = 1; i <= n; ++ i){
        dp[i] += dp[i-1];
        if(i >= 2){
            if(s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n')){
                dp[i] += dp[i-2];
            }
        }
        dp[i] %= mod;
    }


    cout << dp[n] << endl;

    return 0;
}