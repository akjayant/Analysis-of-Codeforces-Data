#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>

#define fastIO do { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); } while (false);

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;

    vector<vector<int>> c(3, vector<int>(n));
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> c[j][i];
        }
    }

    vector<set<int>> graph(n);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].insert(b);
        graph[b].insert(a);
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (2 < graph[i].size()) {
            cout << -1 << endl;
            return 0;
        }
        if (root == -1 && graph[i].size() == 1) {
            root = i;
        }
    }

    vector<int> tonew(n);
    vector<int> fromnew(n);
    fromnew[0] = root;

    for (int i = 1; i < n; i++) {
        int next = *graph[root].begin();
        fromnew[i] = next;
        graph[next].erase(root);
        root = next;
    }

    vector<vector<ull>> ans(3, vector<ull>(3, 0));
    for (int fc = 0; fc < 3; fc++) {
        for (int sc = 0; sc < 3; sc++) {
            if (sc == fc) continue;
            for (int i = 0; i < n; i++) {
                switch (i%3) {
                    case 0:
                        ans[fc][sc] += c[fc][fromnew[i]];
                        break;
                    case 1:
                        ans[fc][sc] += c[sc][fromnew[i]];
                        break;
                    case 2:
                        int tc = 6 - (sc + 1) - (fc + 1) - 1;
                        ans[fc][sc] += c[tc][fromnew[i]];
                        break;
                }
            }
        }
    }

    ull answer = ans[0][1];
    int mf = 0, ms = 1;

    for (int fc = 0; fc < 3; fc++) {
        for (int sc = 0; sc < 3; sc++) {
            if (sc == fc) continue;
            if (ans[fc][sc] < answer) {
                mf = fc;
                ms = sc;
                answer = ans[fc][sc];
            }
        }
    }

    cout << answer << endl;
    mf++;
    ms++;

    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        switch (i % 3) {
            case 0:
                col[fromnew[i]] = mf;
                break;
            case 1:
                col[fromnew[i]] = ms;
                break;
            case 2:
                col[fromnew[i]] = 6 - mf - ms;
                break;
        }
    }

    for (int co : col ) {
        cout << co << " ";
    }
    return 0;
}