#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fast_io    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x)     cerr << #x << " = " << x << "\n"
#define m_p        make_pair
#define se         second
#define fi         first
#define y1         CNik
#define dist(a, b, c, d) sqrt((a - c) * (a - c) + (b - d) * (b - d))

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 4e18;
const int N = 5e5 + 5;
const ll mod = 1e9 + 7;

ll n, a[N], sum1, sum2;

int main() {
    fast_io

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        if(i < n / 2) {
            sum1 += a[i];
        } else {
            sum2 += a[i];
        }
    }
    cout << sum1 * sum1 + sum2 * sum2 << '\n';



	return 0;
}
