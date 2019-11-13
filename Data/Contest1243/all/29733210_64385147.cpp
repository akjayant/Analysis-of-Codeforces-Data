/// Quality Over Quantity
 
#include <bits/stdc++.h>
 
#define FILE_NAME "B"
 
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
        string a, b;
        cin >> a >> b;
        vector<bool> v(n);
        for (int i = 0; i < n; i++)
            if (a[i] == b[i])
                v[i] = true;
        int cet = 0;
        for (int i = 0; i < n; i++)
            cet += !v[i];
        if (cet == 0)
            cout << "Yes" <<endl;
        else if (cet != 2)
            cout << "No" << endl;
        else {
            vector<int> x;
            for (int i = 0; i < n; i++)
                if (v[i] == 0)
                    x.pb(i);
            swap(a[x[0]], b[x[1]]);
            if (a == b)
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return false;
}