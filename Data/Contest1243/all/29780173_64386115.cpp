#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

int q;

int _find(string &s, int pos, char c){
    for (int i = pos; i < s.size(); i++)
        if (s[i] == c) return i;
    return s.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        int can = 1;
        vector <pair <int, int> > ans;
        for (int i = 0; i < n; i++){
            if (s[i] == t[i]) continue;
            int sps = _find(s, i + 1, t[i]), tps = _find(t, i + 1, t[i]);
            if (sps + tps == 2 * n) {
                can = 0;
                break;
            }
            if (tps == n){
                ans.push_back({sps + 1, sps + 1});
//                cout << sps << " " << sps << "\n";
                swap(s[sps], t[sps]);
                tps = sps;
            }
            ans.push_back({i + 1, tps + 1});
            swap(s[i], t[tps]);
//            cout << i + 1 << " " << tps << "\n";
        }
        if (!can) cout << "No\n";
        else{
            cout << "Yes\n";
            cout << ans.size() << "\n";
            for (auto u: ans) cout << u.first << " " << u.second << "\n";
        }
    }
}
