#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 100005
#define mod 2000003
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, x, y, i, k, a[N], j, cnt1[30], cnt2[30], m;
string s, t;
vector<pii>sol;

void solve() {
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for(i = 0; i < n; i++) {
        cnt1[s[i] - 'a']++;
        cnt2[t[i] - 'a']++;
    }

    for(i = 0; i < 26; i++)
        if((cnt1[i] + cnt2[i]) % 2) {
            cout << "No\n";
            return;
        }

    cout << "Yes\n";

    for(i = 0; i < n; i++) {
        if(t[i] == s[i])
            continue;

        for(j = i + 1; j < n; j++) {
            if(t[i] == t[j]) {
                sol.pb(mp(i + 1, j + 1));
                swap(s[i], t[j]);
                break;
            }
        }

        if(j == n) {
            for(j = i + 1; j < n; j++)
                if(t[i] == s[j]) {
                    sol.pb(mp(j + 1, j + 1));
                    sol.pb(mp(i + 1, j + 1));
                    swap(s[j], t[j]);
                    swap(s[i], t[j]);
                    break;
                }
        }
    }

    m = sol.size();
    cout << m << "\n";

    for(i = 0; i < m; i++)
        cout << sol[i].X << " " << sol[i].Y << '\n';
}
int main() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin >> k;

    for(; k; k--) {
        cin >> n;
        cin >> s >> t;
        sol.clear();
        sol.resize(0);
        solve();
    }

    return 0;
}
