#include <bits/stdc++.h>
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define pb push_back
#define MOD 1000000007
#define MOD2 1000000009
#define BASE 29
#define BASE2 31
#define eps 1e-9
#define INF 1000000002

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<pii,pii> piiii;
const int N = 100002;
const int BIT = 50;
int n,m, dpGeneral[N][2][2], dpFlip[N];

ll solve_general(int i, bool last, bool beforeLast) {
    if(i >= m)
        return 1;
    if(dpGeneral[i][last][beforeLast] != -1)
        return dpGeneral[i][last][beforeLast];
    int ans = 0;
    if(last && beforeLast) {
        ans = solve_general(i+1, false, last);
    } else if (last || beforeLast) {
        ans = (solve_general(i+1, true, last) + solve_general(i+1, false, last)) % MOD;
    } else {
        ans = solve_general(i+1, true, last);
    }
    return dpGeneral[i][last][beforeLast] = ans;
}

ll solve_flip(int i) {
    if(i == n)
        return 1;
    if(i > n)
        return 0;
    if(dpFlip[i] != -1)
        return dpFlip[i];
    return dpFlip[i] = (solve_flip(i+1) + solve_flip(i+2)) % MOD;
}

int main() {
    scanf("%d%d",&n,&m);
    memset(dpGeneral, -1, sizeof dpGeneral);
    memset(dpFlip, -1, sizeof dpFlip);
    ll a = 0, b = 0;
    if(m>=2)
        a = (solve_general(2, 0, 0) + solve_general(2, 0, 1) - 1 + MOD)% MOD;
    b = solve_flip(0);
    printf("%lld",(a+b)*2 % MOD);
    return 0;
}
