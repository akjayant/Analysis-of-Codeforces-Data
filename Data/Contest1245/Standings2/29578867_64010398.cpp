#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;

int f[N];

int32_t main() {
       f[0] = 1;
       f[1] = 1;
       f[2] = 2;

       int flg = 1;
       for(int i = 1; i < N; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;

       string str; cin >> str; str.push_back('a');

       for(auto ch: str) {
            if(ch == 'm' || ch == 'w') flg = 0;
       }

       int res = 1, cnt = str[0] == 'n' || str[0] == 'u';
       for(int i = 1; i < str.size(); i++) {
            if(str[i] != 'u' && str[i] != 'n') {
                res = (res * f[cnt]) % mod;
                cnt = 0;
            }
            if(str[i] == 'u' && str[i - 1] != 'u') {
                res = (res * f[cnt]) % mod;
                cnt = 1;
            }
            if(str[i] == 'u' && str[i - 1] == 'u') {
                ++cnt;
            }

            if(str[i] == 'n' && str[i - 1] != 'n') {
                res = (res * f[cnt]) % mod;
                cnt = 1;
            }
            if(str[i] == 'n' && str[i - 1] == 'n') {
                ++cnt;
            }

       }

       cout << res * flg << endl;


}
