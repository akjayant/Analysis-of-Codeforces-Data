/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int MAXN = 53;
char s[MAXN], t[MAXN];
unordered_map<char, int> f;
unordered_map<char, set<int>> fs, ft;
void my_swap(int x, int y) {
    fs[s[x]].erase(x);
    ft[t[y]].erase(y);
    ft[s[x]].insert(y);
    fs[t[y]].insert(x);
    swap(s[x], t[y]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int tt = clock();
    int tc;
    cin >> tc;
    int n;
    while(tc--) {
        cin >> n >> (s + 1) >> (t + 1);
        f.clear();
        fs.clear();
        ft.clear();
        for (int i = 1; i <= n; ++i) {
            f[s[i]]++;
            fs[s[i]].insert(i);
            f[t[i]]++;
            ft[t[i]].insert(i);
        }
        bool can = true;
        for (auto &v : f) {
            if (v.second & 1) {
                can = false;
                break;
            }
        }
        if (!can) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == t[i]) {
                fs[s[i]].erase(i);
                ft[t[i]].erase(i);
                continue;
            }
            fs[s[i]].erase(i);
            if (!fs[s[i]].empty()) {
                auto v = *fs[s[i]].begin();
                my_swap(v, i);
                ft[t[i]].erase(i);
                ans.emplace_back(v, i);
                continue;
            }
            auto v = *ft[s[i]].begin();
            my_swap(n, v);
            ans.emplace_back(n, v);
            my_swap(n, i);
            ans.emplace_back(n, i);
            ft[t[i]].erase(i);
        }
        if (!can) {
            cout << "No\n";
            continue;
        }
        cout << ans.size() << '\n';
        for (auto &v : ans) cout << v.first << ' ' << v.second << '\n';
    }



    cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
