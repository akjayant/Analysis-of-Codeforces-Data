#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);

///---Some Code---///
struct Point {
    int x, y;
    Point() {x = y = 0;};
    Point(int x, int y): x(x), y(y) {}
};

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(5);
//    srand(time(0));
    ///---------///

    int n;
    cin >> n;

    vector<Point> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;

    vector<int> c(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> c[i];

    vector<int> k(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> k[i];

    vector<vector<int>> d(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            d[i][j] = abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y);
            d[i][j] *= (k[i] + k[j]);
        }
    }

    vector<int> dist(n, inf);
    vector<int> used(n, 0);

    for(int i = 0; i < n; ++i)
        dist[i] = c[i];

    vector<int> pr(n, -1);

    vector<int> build;
    vector<pair<int, int>> ans;

    int res = 0;
    for(int i = 0; i < n; ++i) {
        int cur = -1;
        for(int j = 0; j < n; ++j) {
            if(used[j]) continue;
            if(cur == -1 || dist[j] < dist[cur])
                cur = j;
        }

//        cout << "CUR: " << cur << "\n";
        if(pr[cur] == -1) {
            build.push_back(cur);
            res += c[cur];
        }

        else {
            ans.push_back({cur, pr[cur]});
            res += d[cur][pr[cur]];
        }

        used[cur] = 1;
        for(int j = 0; j < n; ++j) {
            if(used[j]) continue;
            if(d[cur][j] < dist[j]) {
                dist[j] = d[cur][j];
                pr[j] = cur;
            }
        }
    }

    cout << res << "\n";

    cout << build.size() << "\n";
    for(auto i : build)
        cout << i+1 << " ";
    cout << "\n";

    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i.first+1 << " " << i.second+1 << "\n";

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
