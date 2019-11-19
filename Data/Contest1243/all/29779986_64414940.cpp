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
vector<int> get_p(int n) {
    vector<int> p;
    for(int i = 1; i <= sqrt(n); ++i) {
        if(n % i != 0) continue;
        p.push_back(i);
        p.push_back(n/i);
    }

    return p;
}

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int n;
    cin >> n;

    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int g = 0;
    vector<int> p = get_p(n);
    for(auto i : p)
        if(i != 1) g = __gcd(i, g);

    cout << g << "\n";

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
