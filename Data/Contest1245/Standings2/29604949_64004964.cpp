#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int d[100001];
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= 100000; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    char p = s[0];
    int c = 1;
    int ans = 1;
    if (s[0] == 'w' || s[0] == 'm'){
        cout << 0;
        return 0;
    }
    s += '$';
    for (int i = 1; i < s.size(); i++){
        if (s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
        if (s[i] != p && (p == 'n' || p == 'u'))
            ans *= d[c];
        if (s[i] != p)
            c = 0;
        ans = ans % mod;
        c++;
        p = s[i];
    }
    cout << (ans + mod) % mod;
    return 0;
}
