#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector < int > g[N];

int d[N];

void dfs(int v, int p, int dd){
    d[v] = dd;
    for(int to : g[v]){
        if(to == p) continue;
        dfs(to, v, dd + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int c[3][n];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < n; ++j){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int root;
    for(int i = 0; i < n; ++i){
        if(g[i].size() == 1) root = i;
        if(g[i].size() >= 3){
            return cout << -1, 0;
        }
    }

    dfs(root, -1, 0);

    int v[n];

    long long ans = 1e18;
    for(int h1 = 0; h1 < 3; ++h1){
        for(int h2 = 0; h2 < 3; ++h2){
            if(h1 == h2) continue;
            for(int h3 = 0; h3 < 3; ++h3){
                if(h3 != h1 && h3 != h2){
                    long long sum = 0;
                    for(int i = 0; i < n; ++i){
                        if(d[i] % 3 == 0) sum += c[h1][i];
                        if(d[i] % 3 == 1) sum += c[h2][i];
                        if(d[i] % 3 == 2) sum += c[h3][i];
                    }
                    if(sum < ans){
                        ans = sum;
                        for(int i = 0; i < n; ++i){
                            if(d[i] % 3 == 0) v[i] = h1;
                            if(d[i] % 3 == 1) v[i] = h2;
                            if(d[i] % 3 == 2) v[i] = h3;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    for(int to : v){
        cout << to + 1 << ' ';
    }
}
