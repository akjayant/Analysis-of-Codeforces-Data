#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second
#define pb push_back
#define FASTER { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define ll long long

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;

int64_t const base = 1e9 + 7;

int64_t F[100005];

ll Pow(ll a, ll b)
{
    if (b == 0) return 1 % base;
    ll tmp = Pow(a, b/2);
    tmp = (tmp * tmp) % base;
    if (b % 2 == 0) return tmp;
        else return tmp * a % base;
}


ll C(int n, int k)
{
    if (k > n) return 0;
    ll x = F[n];
    ll y = F[k] * F[n-k] % base;
    y = Pow(y, base - 2);
    return x * y % base;
}

int main(){
    FASTER
//    freopen("x.INP", "r", stdin);
//    freopen("x.OUT", "w", stdout);
    string s;
    cin >> s;
    s.pb('.');
    int64_t ans = 1;
    F[0] = 1;
    FOR(i, 1, 100000) F[i] = (F[i - 1] * i)%base;;
    int cur = 1, flag = 0;
    REP(i, s.size() - 1){
        if (s[i] == 'm' || s[i] == 'w') flag = 1;
        if (s[i] == s[i + 1] && (s[i] == 'n' || s[i] == 'u')) cur++;
        else{
            int64_t res = 1;
            for(int j = 2; j <= cur; j += 2) res = (res + C(cur - j + j / 2, cur - j)) % base;
            ans = (ans * res) % base;
            cur = 1;
        }
    }
    if (flag) cout << 0;
    else
    cout << ans;
}
