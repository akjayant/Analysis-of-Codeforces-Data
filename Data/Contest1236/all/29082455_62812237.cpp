#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define MAX 20
#define MOD 1000000007

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

ll count(int min_r, int max_r, int min_c, int max_c, int x, int y, int dir,
        vector<vector<int>>& tr, vector<vector<int>>& tc) {
    if (dir == 0) {
        int pos = max_c;
        for (int i = 0; i < tr[x].size(); i++) {
            if (tr[x][i] > y) {
                pos = tr[x][i] - 1;
                break;
            }
        }
        pos = min(pos, max_c);
        if (pos != y) {
            return pos - y + count(min_r+1, max_r, min_c, pos, x, pos, 1, tr, tc);
        }

        return 0;
    } else if (dir == 1) {
        int pos = max_r;
        for (int i = 0; i < tc[y].size(); i++) {
            if (tc[y][i] > x) {
                pos = tc[y][i] - 1;
                break;
            }
        }
        pos = min(pos, max_r);
        if (pos != x) {
            return pos - x + count(min_r, pos, min_c, max_c-1, pos, y, 2, tr, tc);
        }

        return 0;
    } else if (dir == 2) {
        int pos = min_c;
        for (int i = 0; i < tr[x].size(); i++) {
            if (tr[x][tr[x].size() - 1 - i] < y) {
                pos = tr[x][tr[x].size() - 1 - i] + 1;
                break;
            }
        }
        pos = max(pos, min_c);
        if (pos != y) {
            return y - pos + count(min_r, max_r-1, pos, max_c, x, pos, 3, tr, tc);
        }

        return 0;
    } else {
        int pos = min_r;
        for (int i = 0; i < tc[y].size(); i++) {
            if (tc[y][tc[y].size() - 1 - i] < x) {
                pos = tc[y][tc[y].size() - 1 - i] + 1;
                break;
            }
        }
        pos = max(pos, min_r);
        if (pos != x) {
            return x - pos + count(pos, max_r, min_c+1, max_c, pos, y, 0, tr, tc);
        }

        return 0;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> tr(n), tc(m);

	for (int i = 0; i < k; i++) {
	    int a, b;
	    cin >> a >> b;
	    a--, b--;
	    tr[a].emplace_back(b);
	    tc[b].emplace_back(a);
	}
	for (int i = 0; i < n; i++) {
	    if (tr[i].size() > 1) {
	        sort(tr[i].begin(), tr[i].end());
	    }
	}
    for (int i = 0; i < m; i++) {
        if (tc[i].size() > 1) {
            sort(tc[i].begin(), tc[i].end());
        }
    }

    ll cnt = count(0, n-1, 0, m-1, 0, -1, 0, tr, tc);

    cout << ((cnt + k == n * m) ? "Yes\n" : "No\n");




	return 0;
}

