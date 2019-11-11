#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

#define fo(i,a,z) for(ll i=(a);i<(z);++i)
#define MAX 100005
const ll MOD = (1e9+7);

ll n, ans=1, v[MAX];
string s;

int main() {
    cin >> s;
    n = s.size();
    v[0] = 1;
    v[1] = 1;
    fo(i,2,MAX) v[i] = (v[i-1] + v[i-2]) % MOD;
    //fo(i,0,10) cout << v[i] << ' ';
    //cout << '\n';
    fo (i,0,n) if (s[i] == 'm' || s[i] == 'w') {
        cout << "0\n";
        return 0;
    }
    fo (i,0,n) {
        ll chunk=1;
        while (s[i+1] == s[i]) {
            ++chunk;
            ++i;
        }
        //cout << s[i] << ' ' << chunk << '\n';
        if (s[i] == 'u' || s[i] == 'n') ans = (ans * v[chunk]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
