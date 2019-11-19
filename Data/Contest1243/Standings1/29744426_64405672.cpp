#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;


const int MAXN = 4e5 + 50;
const ll MOD = 1e9 + 7;


char ff[55];
char ss[55];

void dof() {

    int n;
    cin >> n;

    string s1;
    string s2;
    cin >> s1 >> s2;

    for (int i = 0; i < n; ++ i){
        ff[i]  = s1[i];
        ss[i] = s2[i];
    }

    vector<pair<int, int>> answr;

    bool was_bad = false;

    for (int i = 0; i < n; ++ i){


        if (ff[i] != ss[i]){

            bool ok = false;

            for (int j = i + 1; j< n; ++ j){
                if (ff[j] == ff[i]){
                    ok = true;

                    swap(ss[i], ff[j]);
                    answr.push_back({i, j});

                    break;
                }

            }

            if (!ok){

                for (int j = i + 1; j< n; ++ j){
                    if (ss[i] == ss[j]){
                        ok = true;

                        swap(ss[j], ff[i]);
                        answr.push_back({j, i});

                        break;
                    }

                }
            }

            if (!ok){

                for (int j = i + 1; j< n; ++ j){
                    if (ff[i] == ss[j]){
                        ok = true;

                        swap(ss[j], ff[j]);
                        swap(ff[j], ss[i]);
                        answr.push_back({j, j});
                        answr.push_back({j, i});

                        break;
                    }

                }
            }

            if (!ok){

                for (int j = i + 1; j< n; ++ j){
                    if (ss[i] == ff[j]){
                        ok = true;

                        swap(ss[j], ff[j]);
                        swap(ff[i], ss[j]);
                        answr.push_back({j, j});
                        answr.push_back({i, j});

                        break;
                    }

                }
            }


            if (!ok)
                was_bad = true;
        }

    }

    if (was_bad){
        cout << "No\n";
    }else {
        cout << "Yes\n";
        cout << answr.size() << "\n";

        for (auto el : answr){
            cout << el.first + 1 << " " << el.second + 1 << "\n";
        }
    }

}

const int nn = 1e5 + 9;

set<pair<int, int>> edgees;
set<int> not_usd;

int start[nn];

void dfs(int vertex, int color) {

    if (start[vertex] != 0)
        return;

    not_usd.erase(vertex);
    start[vertex] = color;
    vector<int> look;

    for (auto el : not_usd) {
        if (edgees.find({vertex, el}) == edgees.end()) {
            look.push_back(el);
        }
    }

    for (auto el : look) {
        not_usd.erase(el);
    }

    for (auto el : look) {
        dfs(el, color);
    }
}

void solve() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; ++ i){
        int u, v;
        cin >> u >> v;
        edgees.insert({u, v});
        edgees.insert({v, u});
    }

    for (int i = 1; i <= n; ++ i)
        not_usd.insert(i);

    for (int i = 1; i <= n; ++i)
        dfs(i, i );

    set<int> answr;

    for (int i = 1; i <= n; ++ i)
        answr.insert(start[i]);

    cout << answr.size() - 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(1);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    //cout << '\n' << (double)clock() / CLOCKS_PER_SEC << '\n';
#endif
}