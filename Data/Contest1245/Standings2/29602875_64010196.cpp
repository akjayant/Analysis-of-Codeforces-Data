#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;


#define ll long long
const ll mod = 1e9 + 7;

char s[100005];
ll dp[100005][2];
int n;
int main() {
    //freopen("in", "r", stdin);
    scanf("%s", s);
    n = strlen(s);

    dp[1][0] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = dp[i - 1][0];
    }

    ll ans = 1;
    for(int i = 0; i < n;) {
        if(s[i] == 'w' || s[i] == 'm') {
            ans = 0;
            i++;
        }
        else if(s[i] == 'u') {
            int cnt = 0;
            while(i < n && s[i] == 'u') {
                cnt += 1;
                i++;
            }
            ans = ans * (dp[cnt][0] + dp[cnt][1]) % mod;
        }
        else if(s[i] == 'n'){
            int cnt = 0;
            while(i < n && s[i] == 'n') {
                cnt += 1;
                i++;
            }
            ans = ans * (dp[cnt][0] + dp[cnt][1]) % mod;
        }
        else {
            i++;
        }
    }
    cout << ans << endl;

    return 0;
}