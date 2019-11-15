#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define re(n) for (int i = 0; i < (n); ++i)
#define rej(n) for (int j = 0; j < (n); ++j)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pair <int, int>> vii;
typedef vector <vector <int>> vvi;

const ld PI = acos((ld)-1);

int main() {
    #ifndef LOCALDEBUG
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif  // LOCALDEBUG
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        re(n) cin >> v[i];
        sort(all(v));
        reverse(all(v));
        int ans = 0;
        re(n) {
            ans = max(ans, min(i + 1, v[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}
