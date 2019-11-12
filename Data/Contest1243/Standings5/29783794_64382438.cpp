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
        string s, t;
        cin >> s >> t;
        int sim = 0;
        re(n) if (s[i] == t[i]) ++sim;
        if (n - sim > 2) {
            cout << "No\n";
            continue;
        }
        vi v;
        re(n) {
            if (s[i] != t[i]) {
                v.push_back(i);
            }
        }
        if (v.size() != 2) {
            cout << "No\n";
            continue;
        }
        swap(s[v[0]], t[v[1]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        swap(s[v[0]], t[v[1]]);
        swap(t[v[0]], s[v[1]]);
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
        ex:;
    }
    return 0;
}
