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

void Get() {
    int n;
    cin >> n;
    int a, b, C;
    cin >> a >> b >> C;
    string s;
    cin >> s;
    int Res = 0;
    int KT[n];
    memset(KT, 0, sizeof(KT));
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'R') {
            if (b > 0) {
                Res += 1;
                b -= 1;
                KT[i] = 2;
            }
        }
        if (c == 'P') {
            if (C > 0) {
                Res += 1;
                C -= 1;
                KT[i] = 3;
            }
        }
        if (c == 'S') {
            if (a > 0) {
                Res += 1;
                a -= 1;
                KT[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (KT[i] == 0) {
            if (a) {
                KT[i] = 1;
                a--;
            }
            else {
                if (b) {
                    KT[i] = 2;
                    b--;
                }
                else {
                    KT[i] = 3;
                    C--;
                }
            }
        }
    }
    if (Res >= (n + 1) / 2) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            if (KT[i] == 1) cout << "R";
            if (KT[i] == 2) cout << "P";
            if (KT[i] == 3) cout << "S";
        }
        cout << '\n';
    }
    else cout << "NO" << '\n';
}
void solve() {
    int T;
    cin >> T;
    while (T--) Get();
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
