//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
const int N = 100005, mod = 1e9 + 7;
char str[N];
int memo[N];

int solve(int idx) {
    if (str[idx] == 'm' || str[idx] == 'w') return 0;
    if (str[idx] == 0) return 1;
    int &res = memo[idx];
    if (~res) return res;
    res = 0;
    res = solve(idx + 1);
    if (str[idx] == 'n' && str[idx + 1] == 'n') res = (res + solve(idx + 2)) % mod;
    if (str[idx] == 'u' && str[idx + 1] == 'u') res = (res + solve(idx + 2)) % mod;
    return res;
}


int main() {
    //freopen("in.txt", "rt", stdin);
    scanf("%s", str);
    memset(memo, -1, sizeof memo);
    printf("%d", solve(0));
}