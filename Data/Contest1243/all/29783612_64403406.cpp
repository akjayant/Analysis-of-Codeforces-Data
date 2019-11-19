#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) if(DEBUG) cout << #x _ "=" _ x << endl
#define TRACE_VEC(v) if(DEBUG){ cout << #v << _ "="; for(auto e : v) cout _ e; cout << endl; }
#define _ << " " <<
#define endl "\n"
#define IN_VEC(v, n) int temp_inv_var; REP(i, n){ cin >> temp_inv_var; v.push_back(temp_inv_var); }
#define IN_ARR(a, n) REP(i, n) cin >> (a)[i]
#define ll int64_t
#define i32 int32_t

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


bool P[1000001];

void crible(){
    fill(P, P+1000001, true);
    FOR(p, 2, 1000001){
        if(P[p]){
            int k = 2;
            while(k*p < 1000001){
                P[k*p] = false;
                k++;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    int64_t n;
    cin >> n;
    int d = -1;
    crible();
    for(int64_t k = 2; k*k <= n; k++){
        if(P[k] && n % k == 0){
            d = k;
            break;
        }
    }
    if(d == -1) cout << n << endl;
    else{
        bool ok = true;
        while(n > 1){
            if(n % d == 0) n = n / d;
            else{
                ok = false;
                break;
            }
        }
        if(ok) cout << d << endl;
        else cout << 1 << endl;
    }

}
