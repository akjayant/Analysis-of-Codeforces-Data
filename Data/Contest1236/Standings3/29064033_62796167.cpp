#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

typedef long long LL;
typedef pair <LL, LL> PLL;

const LL maxn = 100010;
const LL mod = 1000000007;
const LL inf = 2000000000;
const LL inf64 = inf*inf;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> arr[n];
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) for (int i = 0; i < n; i++) arr[i].push_back(cnt++);
        else for (int i = n-1; i >= 0; i--) arr[i].push_back(cnt++);
    }

    for (auto &i : arr)
    {
        for (auto a : i) cout << a << " ";
        cout << endl;
    }

    return 0;
}
