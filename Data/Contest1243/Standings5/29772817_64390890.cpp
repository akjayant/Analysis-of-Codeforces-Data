#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 100000007

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int t; cin >> t;
        while ( t-- ) {
                int n; cin >> n;
                string a, b; cin >> a>> b;
                int f[27] = {};
                lp(i, n) {
                        f[a[i] - 'a']++;
                        f[b[i] - 'a']++;
                }
                bool is = 1;
                lp(i, 26) if (f[i] % 2 != 0) {
                        cout << "No\n";
                        is = 0;
                        break;
                }
                if (is) {
                        cout << "Yes\n";
                        vector<pair<int, int>> v;
                        for (int i = 0; i < n; i++) {
                                if (a[i] == b[i]) continue;
                                bool pr = 1;
                                for (int j = i + 1; j < n; j++) {
                                        if (a[i] == a[j]) {
                                                v.push_back({j + 1, i + 1});
                                                swap(b[i], a[j]);
                                                pr = 0;
                                                break;
                                        }
                                }
                                if (pr)
                                        for (int j = i + 1; j < n; j++) {
                                                if (b[j] == a[i]) {
                                                        v.push_back({i + 2, j + 1});
                                                        v.push_back({i + 2, i + 1});
                                                        swap(a[i + 1], b[j]);
                                                        swap(a[i + 1], b[i]);
                                                        break;
                                                }
                                        }
                        }
                        cout << v.size()<< "\n";
                        lp(i, v.size()) cout << v[i].first<< " "<< v[i].second<< "\n";
                }
        }
return 0;
}
