#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;
const int MOD = 1000000007;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

long long f[maxN];
void Fib(){
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= 1e5; i++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++)
    if (s[i] == 'm' || s[i] == 'w'){
        cout << 0;
        return;
    }
    vector<int> c;
    c.clear();
    int i = 0;
    while (i < n){
        int j = i + 1;
        while (s[i] == s[j] && j < n) j++;
        if (s[i] == 'n' || s[i] == 'u') c.push_back(j - i);
        i = j;
    }
    Fib();
    long long res = 1;
    for(int i = 0; i < c.size(); i++){
        res = (res * f[c[i]]) % MOD;
     //   cout << f[c[i]] << '\n';
    }
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    //doc();
//    int T;
//    cin >> T;
//    while (T--)

    solve();
}

