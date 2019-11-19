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

ll mn, k, pref[N], MN[N], ans, mx, n, l, r;
string s, s1;

int main() {
    fast_io

    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            s1 = s;
            swap(s1[i], s1[j]);
            mn = INF, k = 0;
            for(int p = 0; p < s1.size(); ++p) {
                k += (s1[p] == '(');
                k -= (s1[p] == ')');
                pref[p] = k;
                mn = min(mn, k);
                MN[p] = mn;
            }
            if(pref[s1.size() - 1] != 0) {
                continue;
            }
            mn = INF;
            k = ans = 0;
            for(int p = s1.size() - 1; p >= 0; --p) {
                k += (s1[p] == '(');
                k -= (s1[p] == ')');
                mn -= (s1[p] == ')');
                mn += (s1[p] == '(');
                mn = min(mn, (s1[p] == ')' ? -1LL : 1LL));
                if(mn < 0) {
                    continue;
                }
                if(MN[p - 1] + k < 0) {
                    continue;
                }
                ++ans;
            }
            if(ans > mx) {
                mx = ans;
                l = i, r = j;
            }
        }
    }
    cout << mx << '\n' << l + 1 << ' ' << r + 1 << '\n';



	return 0;
}
