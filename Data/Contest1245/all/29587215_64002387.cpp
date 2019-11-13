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

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int F[n + 1];
    memset(F, 0, sizeof(F));
    F[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'm' || s[i - 1] == 'w') {
            cout << 0;
            return;
        }
        F[i] = F[i - 1];
        if (i >= 2 && s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
            F[i] = (F[i] + F[i - 2]) % module;
    }
    cout << F[n];
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    ///doc();
    solve();
}
