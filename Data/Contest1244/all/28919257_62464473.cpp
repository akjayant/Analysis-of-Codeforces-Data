#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

/*
typedef tree<int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        set_t;*/

/*
    find_by_order()
    order_of_key()
*/

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_work {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

const ll INF = 1e18+ 7, NMAX = 1e6 + 5, END = 1e5, MOD = 1000000007, N = 1005, LITTLE_INF = 1e9 + 5, LOG = 25;
const ld EPS = 1e-5;

int main() {
    fast_work;
    int test;
    cin >> test;

    while(test --> 0) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int p_cnt = a / c;
        if(a % c != 0) ++p_cnt;

        int k_cnt = b / d;
        if(b % d != 0) ++k_cnt;

        if(p_cnt + k_cnt <= k) cout << p_cnt << " " << k_cnt << "\n"; else cout << "-1\n";
    }
}
