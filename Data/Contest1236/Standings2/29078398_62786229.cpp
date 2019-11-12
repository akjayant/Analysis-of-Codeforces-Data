#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int QQ = 3e5 + 10;
const int maxN = 3e5 + 100;
const int maxM = 3e5 + 10;
const long long oo = 1e15;
const int module = 1e9 + 7;
const long double du = 1e-9;

void doc() {
    freopen(INP ".inp","r",stdin);
    freopen(OUT ".out","w",stdout);
}

int pw(int a, int n) {
    int Res = 1;
    for (; n; n = n >> 1, a = 1LL * a * a % module) {
        if (n & 1) Res = 1LL * Res * a % module;
    }
    return Res;
}
void solve() {
    int n, m;
    cin >> n >> m;
    cout << pw(pw(2, m) - 1, n);
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
