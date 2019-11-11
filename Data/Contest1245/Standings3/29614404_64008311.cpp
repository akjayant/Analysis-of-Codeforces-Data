#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef pair <int, int> ii;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

ll F[N], n;
bool dm, dw;
string s;

int main(){
    cin >> s;
    n = s.size();
    ll ans = 1;

    F[0] = 1;
    F[1] = 1;
    F[2] = 2;
    FOR(i, 3, n)
        F[i] = (F[i - 1] + F[i - 2]) % MOD;

    int nu = 0, nn = 0;
    for(char ch : s){
        if (ch == 'u'){
            nu++;
            ans = ans * F[nn] % MOD;
            nn = 0;
        } else if (ch == 'n'){
            nn++;
            ans = ans * F[nu] % MOD;
            nu = 0;
        } else{
            if (ch == 'w')
                dw = 1;
            if (ch == 'm')
                dm = 1;

            ans = ans * F[nn] % MOD;
            ans = ans * F[nu] % MOD;
            nn = nu = 0;
        }
    }
    ans = ans * F[nn] % MOD;
    ans = ans * F[nu] % MOD;
    nn = nu = 0;
    if (dm || dw){
        cout << 0;
    } else {
        cout << ans;
    }
}

