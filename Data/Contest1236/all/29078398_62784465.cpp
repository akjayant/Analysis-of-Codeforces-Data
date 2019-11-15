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

void solve() {
    int Test;
    cin >> Test;
    while (Test--) {
        int a, b, c;
        cin >> a >> b >> c;
        int Res = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int x = i;
                int y = 2 * i + j;
                int z = 2 * j;
                if (x <= a && y <= b && z <= c) Res = max(Res, x + y + z);
            }
        }
        cout << Res << '\n';
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
