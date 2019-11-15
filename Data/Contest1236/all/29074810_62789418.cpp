#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second


using namespace std;
typedef pair <int, int> ii;
int64_t const MOD = 1e9 + 7;
int64_t calPow (int64_t x, int k){
    if (k == 1) return x;
    int64_t res = calPow(x, k/2);
    if (k % 2) return ((res * res) % MOD * x) % MOD;
    else return (res * res) % MOD;
}



int main(){
    int n, m;
    cin >> n >> m;
    int64_t base = (calPow(2, m) - 1 + MOD) % MOD;
    cout << calPow(base, n);
}
