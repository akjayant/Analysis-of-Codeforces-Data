#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())
#define pb push_back
#define mp make_pair

#define forr(i, n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i, n)
#define forj(n) forr(j, n)
#define fork(n) forr(k, n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forim fori(m)

#define debug(x) cout << #x << " == " << x << endl;
#define GG return 0;

//#define int ll

int solve(const string& s) {
    int n = sz(s);
    int mn = n;
    forin {
        if (s[i] == '1') {
            mn = min({mn, 2 * i, (n - 1 - i) * 2});
        }
    }
    return 2 * n - mn;
}

signed main() // check the limits, dummy
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve(s) << "\n";
    }
}
