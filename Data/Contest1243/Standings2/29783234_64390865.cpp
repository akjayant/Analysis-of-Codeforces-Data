#include "bits/stdc++.h"

using namespace std;
//vector<long long> factors;
#define ll long long

#define pii pair<int,int>
#define pll pair<ll,ll>
#define _ <<'\n'
#define __ << ' '
#define all(x) (x).begin(), (x).end()
#define gcd __gcd
int IT_MAX = 1 << 17;
int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x0f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
#define szz(x) (int)(x).size()
#define IOS ios_base::sync_with_stdio(false); cout.tie(0);cin.tie(0);
#define flush fflush(stdout)

ll mod(ll a, ll m) { return (a + (abs(a) / m) * m + m) % m; }

//****************************don't use int!!!!!!!****************************//
//***************************code starts here!!!!!****************************//

pll get_next(string &s, string &t, ll cur_pos) {
    auto ind = find(s.begin() + cur_pos + 1, s.end(), s[cur_pos]);
    if (ind != s.end()) {
        ll s_pos = ind - s.begin();
        swap(t[cur_pos], s[s_pos]);
        return {s_pos, cur_pos};
    } else {
        ind = find(t.begin() + cur_pos, t.end(), s[cur_pos]);
        ll t_pos = ind - t.begin();
        swap(s[cur_pos + 1], t[t_pos]);
        return {cur_pos + 1, t_pos};
    }
}

int main() {
//    IOS

    ll k;
    cin >> k;
    while (k--) {
        vector<pll > ans;
        ll n;
        cin >> n;
        string s;
        string t;
        cin >> s >> t;
        string cs = s;
        string ct = t;
        unordered_map<char, ll> cnt;
        for (auto i : s) {
            cnt[i]++;
        }
        for (auto i : t) {
            cnt[i]++;
        }
        bool check = true;
        for (auto i : cnt) {
            if (i.second % 2 == 1) {
                check = false;
                cout << "No\n";
                break;
            }
        }
        if (!check) {
            continue;
        }
        cout << "Yes\n";
        ll cur_pos = 0;
        while (cur_pos < n) {
            if (s[cur_pos] == t[cur_pos]) {
                ++cur_pos;
                continue;
            } else {
                ans.push_back(get_next(s, t, cur_pos));
            }
        }
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i.first + 1 << ' ' << i.second + 1 << '\n';
        }

    }

    return 0;

}