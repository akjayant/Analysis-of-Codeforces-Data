#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;
const int MOD = 1000000007;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

int GCD(int a, int b){
    if (b == 0) return a;
    if (a < b) swap(a,b);
    return GCD(b, a % b);
}

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a,b);
    if (GCD(a, b) != 1) cout << "Infinite";
    else cout << "Finite";
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //doc();
    int T;
    cin >> T;
    while (T--)

    solve();
}

