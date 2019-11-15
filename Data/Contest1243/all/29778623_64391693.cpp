#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;

char a[maxn];
char b[maxn];
ll n;

void solve() {
    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            int flag = 0;
            for (int j = i + 1; j <= n; j++) {
                if (b[i] == b[j]) {
                    swap(a[i], b[j]);
                    ans.emplace_back(i, j);
                    flag = 1;
                    break;
                }
                if (b[i] == a[j]) {
                    swap(a[j], b[j]);
                    swap(a[i], b[j]);
                    ans.emplace_back(j, j);
                    ans.emplace_back(i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                //  cout<<"i="<<i<<" flag="<<flag<<endl;
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (pii p: ans) {
        cout << p.first << " " << p.second << endl;
    }
}


int main() {

    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a + 1;
        cin >> b + 1;

        solve();
    }

    return 0;
}