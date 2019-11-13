#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

long long mod_pow(long long a, long long n){
    long long res = 1;
    while(n > 0){
        if(n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

signed main(){
    ll n,m;
    cin >> n >> m;
    cout << mod_pow(mod_pow(2, m) - 1, n) << endl;;
    return 0;
}