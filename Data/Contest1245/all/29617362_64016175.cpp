#include <bits/stdc++.h>

using namespace std;

string tostr(int x) {
    string s;
    while(x > 0) {
        s += char((x % 10) + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
int a, b;
long long memo[33][2][2][2][2];
int F(int x, int w) {
    return (x >> w) & 1;
}
long long dp(int bit, bool sm1, bool sm2, bool g1, bool g2) {

    if(bit == -1) {
        if(sm1 && sm2 && g1 && g2)return 1;
        else return 0;
    }
    if(memo[bit][sm1][sm2][g1][g2] != -1)return memo[bit][sm1][sm2][g1][g2];
    int i1 = sm1 ? 1 : F(b, bit);
    int i2 = sm2 ? 1 : F(b, bit);
    int bb = F(b, bit), aa = F(a, bit);
    long long rez = 0;
    for(int i = 0; i <= i1; i++) {
        for(int j = 0; j <= i2; j++) {
            if(i == 1 && j == 1) continue;
            if(i < aa && !g1) continue;
            if(j < aa && !g2) continue;
            rez += dp(bit - 1, sm1 || (i < bb), sm2 || (j < bb), g1 || (i > aa), g2 || (j > aa));
        }
    }
    return memo[bit][sm1][sm2][g1][g2] = rez;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        memset(memo, -1, sizeof memo);
        cin >> a >> b;
        long long s = 0;
        if(a == 0) {
            s = 2 * (b - a + 1) - 1;
            a = 1;
        }

        a--, b++;
        cout << s + dp(30, 0, 0, 0, 0) << '\n';
    }
    return 0;
}
