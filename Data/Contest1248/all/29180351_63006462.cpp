#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> E[1000005];

int V[1000005], low[1000005];
int stk[1000005], top;
bool instk[1000005];
int scc[1000005];
int used[1000005];
vector<vector<int>> SCC;
int ts;
void dfs(int i) {
	V[i] = low[i] = ++ts;
	stk[top++] = i;
	instk[i] = 1;
	for(auto x : E[i]) {
		if(!V[x])
			dfs(x), low[i] = min(low[i], low[x]);
		else if(instk[x])
			low[i] = min(low[i], V[x]);
	}
	if(V[i] == low[i]) {
		int j;
        SCC.push_back({});
		do {
			j = stk[--top];
			instk[j] = 0;
			scc[j] = i;
            SCC.back().push_back(j);
		}while(j != i);
	}
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) E[i].clear(), V[i] = low[i] = 0;
        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            if(a != b)
                E[a].push_back(b);
        }

        ts = 0; top = 0;
        SCC.clear();
        for(int i = 1; i <= n; ++i)
            if(!V[i])
                dfs(i);

        if(SCC.size() == 1) {
            cout << "No" << '\n';
            continue;
        }
        for(auto &comp : SCC) {
            bool isEnd = 1;
            for(auto v : comp) {
                for(auto x : E[v]) {
                    if(scc[x] != scc[v]) {
                        isEnd = 0;
                        break;
                    }
                }
                if(!isEnd) break;
            }
            if(isEnd) {
                cout << "Yes" << '\n';
                cout << comp.size() << ' ' << n - comp.size() << '\n';
                for(int i = 1; i <= n; ++i)
                    used[i] = 0;
                for(auto x : comp)
                    cout << x << ' ', used[x] = 1;
                cout << '\n';
                for(int i = 1; i <= n; ++i)
                    if(!used[i])
                        cout << i << ' ';
                cout << '\n';
                break;
            }
        }
    }


    return 0;
}
