#include<bits/stdc++.h>


using namespace std;

const int N = 1e6 + 2, MOD = 1e9 + 7;

#define ss second
#define ff first
#define int long long

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int fact[N];

int power (int x, int y) {
    if (y == 0) return 1;
    int k = power(x, y / 2);
    k*= k;
    k%= MOD;
    if (y % 2) k*= x;
    k%= MOD;
    return k;

}

int divis (int s, int k) {
    return s * power(k, MOD - 2) % MOD;
}
int cc(int n, int k) {
    int x = fact[n], y = fact[k], z = fact[n - k];
    int kek = divis(x, y);
    return divis(kek, z);
}


signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    int ans = 1;
    fact[0] = 1;
    fact[1] = 1;
    cin >> s;
    for (int i = 2; i <= s.size(); i++) {
        fact[i] = fact[i - 1] * i % MOD;
        fact[i]%= MOD;
    }
    int i = 0;
    for (int j = 0; j < s.size(); j++) if (s[j] == 'm' || s[j] == 'w') {
        cout << 0;
        return 0;
    }
    while (i < s.size()) {
        int kol = 0;
        if (s[i] == 'n') {
            while (i < s.size() && s[i] == 'n') kol++, i++;

            int oo = 0;
            for (int j = 0; j < kol; j++) {
                if (j * 2 > kol) break;
                oo+= cc(kol - j, kol - j * 2);
                oo%= MOD;
               // cout << kol << endl;
                ans%= MOD;
            }
            oo%= MOD;
            ans*= oo;
            ans%= MOD;
            continue;
        }
        if (s[i] == 'u') {
            kol = 0;
            while (i < s.size() && s[i] == 'u') kol++, i++;
            int oo = 0;
            for (int j = 0; j < kol; j++) {
                if (j * 2 > kol) break;
                oo+= cc(kol - j, kol - j * 2);
                oo%= MOD;
               // cout << kol << endl;
                ans%= MOD;
            }
            oo%= MOD;
            ans*= oo;
            ans%= MOD;
            continue;
        }
        i++;
    }
    cout << ans;
}
