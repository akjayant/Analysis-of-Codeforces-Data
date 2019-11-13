#include <bits/stdc++.h>
#define MOD (int)(1e9 + 7)
using namespace std;

const int N = 101110;
int DP[N];
string str;
int main() {
    //freopen("a.txt", "r", stdin);
    cin >> str;
    int n = str.length();
    DP[0] = 1;
    for(int i = 1; i <= n; ++i) {
        if(str[i - 1] == 'm' || str[i - 1] == 'w') {
            cout << 0 << endl;
            return 0;
        }
        DP[i] = DP[i - 1];
        if(str[i - 1] == str[i - 2] && (str[i- 1] == 'u' || str[i -1] == 'n'))
            DP[i] = (DP[i - 2] + DP[i - 1]) % MOD;
    }
    cout << DP[n] << endl;
}
