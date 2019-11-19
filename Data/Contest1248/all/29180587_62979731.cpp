#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<ll, ll>;
using P3 = pair<ll, P>;
using PP = pair<P ,P>;
constexpr ll MOD = ll(1e9+7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(2e5) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()



int main(){
    int T;
    cin >> T;
    for(;T>0;T--){
        int n, m;
        cin >> n;
        ll cnt[2]{};
        for(int i=0;i<n;i++){
            int p;
            cin >> p;
            cnt[p%2]++;
        }
        ll ans = 0;
        cin >> m;
        for(int i=0;i<m;i++){
            int q;
            cin >> q;
            ans += cnt[q%2];
        }
        cout << ans << endl;

    }

    return 0;
}