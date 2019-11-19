#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int d[100005][4][2];

inline int invmod(int x){
    int p = MOD - 2, aux = x, ans = 1;
    for(int i = 1; i <= p ; i = i << 1){
        if((i & p)) ans = (1LL * ans * aux) % MOD;
        aux = (1LL * aux * aux) % MOD;
    }

    return ans;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    d[1][1][0] = 1;
    d[1][2][0] = 1;

    /**
        0 - a a
        1 - a b
        2 - b a
        3 - b b
    **/

    for(int i = 2; i <= max(n, m) ; ++i){
        d[i][0][1] = (d[i - 1][2][0] + d[i - 1][2][1]) % MOD;

        d[i][1][0] = d[i - 1][2][0];
        d[i][1][1] = (d[i - 1][0][1] + d[i - 1][2][1]) % MOD;

        d[i][2][0] = d[i - 1][1][0] % MOD;
        d[i][2][1] = (d[i - 1][3][1] + d[i - 1][1][1]) % MOD;

        d[i][3][1] = (d[i - 1][1][0] + d[i - 1][2][1]) % MOD;
    }

    int Sum0 = 0, Sum1 = 0, Sum = 0;
    for(int i = 0; i < 4 ; ++i) Sum0 = (Sum0 + d[n][i][0]) % MOD;
    for(int i = 0; i < 4 ; ++i) Sum1 = (Sum1 + d[n][i][1]) % MOD;

    for(int i = 0; i < 4 ; ++i) Sum = (Sum + d[m][i][0] + d[m][i][1]) % MOD;

    int Sol = (Sum1 + 1LL * (1LL * Sum0 * Sum) % MOD * invmod(2)) % MOD;

    printf("%d", Sol);

    return 0;
}