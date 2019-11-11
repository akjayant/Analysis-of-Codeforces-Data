#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int QQ = 3e5 + 10;
const int maxN = 5e5 + 100;
const int maxM = 3e5 + 10;
const long long oo = 5e17;
const int module = 1e9 + 7;
const long double du = 1e-9;

void doc() {
    freopen(INP ".inp","r",stdin);
    freopen(OUT ".out","w",stdout);
}

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}
void solve() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (GCD(a, b) == 1) cout << "Finite" << '\n';
        else cout << "Infinite" << '\n';
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
   /// doc();
    solve();
}
