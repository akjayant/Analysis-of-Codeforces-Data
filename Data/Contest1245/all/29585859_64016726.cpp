#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100010];
ll m[100010][2];
ll mod = 1e9+7;
int main()
{
    int i, j, k;
    int n, t;
    int a, b, c;
    scanf("%s", s);
    m[1][0] = 1;
    for(i = 2; i <= 100000; i++) {
        m[i][0] = (m[i-1][0]+m[i-1][1]) % mod;
        m[i][1] = m[i-1][0];
    }
    ll ans = 1;
    int cnt = 1;
    int flag  = 1;
    if(s[0] == 'w' || s[0] == 'm') flag = 0;
    for(i = 1; s[i]; i++) {
        if(s[i] == 'u' || s[i] == 'n') {
            if(s[i] == s[i-1]) {
                cnt++;
            }
            else {
                ans = (ans*(m[cnt][0]+m[cnt][1])) % mod;
                cnt = 1;
            }
        }
        else {
                ans = (ans*(m[cnt][0]+m[cnt][1])) % mod;
                cnt = 1;
        }
        if(s[i] == 'w' || s[i] == 'm') flag = 0;
    }
    ans = (ans*(m[cnt][0]+m[cnt][1])) % mod;
    cnt = 1;
    printf("%lld\n", flag? ans: 0);
    return 0;
}
