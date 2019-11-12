#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int q, n;
vector<pair<int, int> > ans;

int main(){



    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        ans.clear();
        int l = 0;
        bool f = false;
        while (l != n){
            if (a[l] == b[l]){++l; continue;}
            bool ff = false;
            for (int i = l + 1; i < n; ++i){
                if (a[l] == a[i]){
                    ff = true;
                    ans.push_back({i + 1, l + 1});
                    swap (a[i], b[l]);
                    break;
                }
            }
            if (!ff){
                for (int i = l + 1; i < n; ++i){
                    if (a[l] == b[i]){
                        ff = true;
                        ans.push_back({l + 2, i + 1});
                        ans.push_back({l + 2, l + 1});
                        swap (a[l + 1], b[i]);
                        swap (a[l + 1], b[l]);
                        break;
                    }
                }
            }
            if (!ff){f = true; break;}
            ++l;
        }
        if (f){
            cout << "No\n";
            continue;
        }
        if (ans.size() > 2 * n) assert (false);
        cout << "Yes\n" << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
    }


}
