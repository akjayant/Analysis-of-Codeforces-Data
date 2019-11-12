#include <bits/stdc++.h>
#define int unsigned int
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);

///---Some Code---///
bool solve(string s, string t) {
    int n = s.size();

    vector<int> same(n, 0);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == t[i])
            same[i] = 1;
        else
            cnt++;
    }

    if(cnt != 2) return false;
    int p1 = -1, p2 = -1;
    for(int i = 0; i < n; ++i) {
        if(p1 == -1 && !same[i]) p1 = i;
        if(!same[i]) p2 = i;
    }

    swap(s[p1], t[p2]);
    return s == t;
}

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        cout << (solve(s, t) ? "Yes" : "No") << "\n";
    }

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
