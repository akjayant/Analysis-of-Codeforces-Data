#include <bits/stdc++.h>
using namespace std;

#define taskname "TEST"
typedef long long ll;
typedef long double ld;

int test, n;
string s, t;

void inp() {
    cin >> test;
}
void solve() {
    while (test--) {
        cin >> n >> s >> t;
        if (s == t) {cout << "YES\n"; continue;}
        int dem = 0, pos = -1, pos2 = -1;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) {
                if (pos == -1) pos = i;
                dem++;
            }
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) pos2 = i;
        if (dem > 2 || dem == 1) {cout << "NO\n"; continue;}
        if ((s[pos] == s[pos2] && t[pos] == t[pos2])) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 //   freopen (taskname".INP", "r", stdin);
 //   freopen (taskname".OUT", "w", stdout);
    inp();
    solve();
}
