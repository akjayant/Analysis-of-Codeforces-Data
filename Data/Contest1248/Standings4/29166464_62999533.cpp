#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 2 * N + 5;

ll MOD(1e9 + 7);
ll base[N];

ll basep1[N];

ll basep2[N];

ll a5r[N];

inline ll fix(ll a, ll b){
    return (((a - b) % MOD) + MOD) % MOD;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if(n > m)swap(n, m);

    base[1] = 2;
    base[2] = 6;
    base[3] = 10;
    for(int i = 4 ; i <= n ; ++i)
        base[i] = (base[i - 1] + fix(base[i - 1], base[i - 2]) + fix(base[i - 2], base[i - 3])) % MOD;

    basep1[1] = 4;
    basep1[2] = 8;
    basep1[3] = 14;

    for(int i = 4 ; i <= n ; ++i)
        basep1[i] = (basep1[i - 1] + fix(basep1[i - 1], basep1[i - 2]) + fix(basep1[i - 2], basep1[i - 3])) % MOD;

    basep2[1] = 6;
    basep2[2] = 12;
    basep2[3] = 20;

    for(int i = 4 ; i <= n ; ++i)
        basep2[i] = (basep2[i - 1] + fix(basep2[i - 1], basep2[i - 2]) + fix(basep2[i - 2], basep2[i - 3])) % MOD;

    a5r[1] = base[n];
    a5r[2] = basep1[n];
    a5r[3] = basep2[n];

    for(int i = 4 ; i <= m ; ++i)
        a5r[i] = (a5r[i - 1] + fix(a5r[i - 1], a5r[i - 2]) + fix(a5r[i - 2], a5r[i - 3])) % MOD;

    printf("%lld\n", a5r[m - n + 1]);

}