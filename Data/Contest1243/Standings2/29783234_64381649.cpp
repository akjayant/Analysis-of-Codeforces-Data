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


int main() {
    IOS

    ll k;
    cin >> k;
    while (k--) {
        bool check = true;
        ll n;
        cin >> n;
        string s;
        string t;
        cin >> s >> t;
        pair<char, char> l, r;
        l = {0, 0};
        r = {0, 0};
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                if (l.first == 0) {
                    l.first = s[i];
                    l.second = t[i];
                } else if (r.first == 0) {
                    r.first = s[i];
                    r.second = t[i];
                } else {
                    check = false;
                    cout << "No\n";
                    break;
                }
            }
        }
        if (check) {
            if (l == r) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;

}