#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const long double pi = acos(-1);
const double PI = acos(-1.);

#define MOD 1000000007

const int N = 2e5 + 5;
const int K = 2e2 + 2;
const int Ai = 1e6 + 6;
const int LOGN = 30;

set<int> adj[N];

int main() {
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    multiset<pii> mse;

    for(int i = 1; i <= n; i++)
        if(!adj[i].empty())
            mse.insert(pii(adj[i].size(), i));

    int cnt = n - 1;
    int res = 0;

    while(!mse.empty()) {
        pii p = *mse.rbegin();
        mse.erase(mse.find(p));

        int c = p.first;
        int x = p.second;

        if(c == cnt)
            res++;

        for(auto nx : adj[x]) {
            int sz = adj[nx].size();

            if(mse.count(pii(sz, nx))) {
                adj[nx].erase(x);
                mse.erase(pii(sz, nx));

                sz = adj[nx].size();

                if(sz != 0)
                    mse.insert(pii(sz, nx));
            }
        }

        cnt--;

//        cout << "MSE:\n";
//        for(auto xx : mse)
//            cout << xx.second << " " << xx.first << "\n";
//        cout << res << "\n";
//        cout << "\n\n";
    }

    cout << res << '\n';

    return 0;
}

