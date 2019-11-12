/// Quality Over Quantity
 
#include <bits/stdc++.h>
 
#define FILE_NAME "A"
 
using namespace std;
using ll = long long;
 
#define f first
#define s second 
#define pb push_back
#define pp pop_back
#define SZ(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define what_is(x) cerr << #x << " is " << x << endl;
 
void freekick() {
#ifndef ONLINE_JUDGE
    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);
#endif
}
 
const int DX[] = {+1, 0, -1, 0, +1, +1, -1, -1};
const int DY[] = {0, +1, 0, -1, +1, -1, +1, -1};
 
void freegoal() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
}
 
signed main() {
    freekick();
    freegoal();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= n - i)
                ans = max(ans, n - i);
        }
        cout << ans << endl;
    }
    return false;
}