#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<set<int>>& g) {
        set<int> v;
        for (int i = 0; i < n; ++i)
            v.insert(i);
        int result = 0;
        while (!v.empty()) {
            result += v.size() < n;
            queue<int> q;
            q.push(*v.begin());
            v.erase(*v.begin());
            while (!q.empty()) {
                if (v.empty())
                    break;
                int u = q.front();
                q.pop();
                auto it = v.begin();
                while (it != v.end()) {
                    if (g[u].find(*it) == g[u].end()) {
                        q.push(*it);
                        it = v.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].insert(b - 1);
        g[b - 1].insert(a - 1);
    }
    int result = Solution().solve(n, g);
    cout << result << endl;
    return 0;
}
