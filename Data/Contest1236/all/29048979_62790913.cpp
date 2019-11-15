#include <bits/stdc++.h>
using namespace std;

#define INF             1e9
#define INFL            1e19
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cout << endl;
#define HOISE           cerr << "hoise" << endl
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << endl
#define READ            freopen("alu.txt", "r", stdin)
#define WRITE           freopen("vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define mid ((L+R)/2)
#define lchld (2*now)
#define rchld (2*now+1)

const int MAX = 1e5 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e5 + 2;
const int MOD = 1e9 + 7;

ll modexp(ll b, ll p)
{
    if(p == 0) return 1LL;

    ll ret = modexp(b, p/2);
    ret = (ret*ret)%MOD;
    if(p%2LL == 1LL) ret = (ret*b) % MOD;
    return ret;
}

int main()
{
//    READ;
    FASTIO;

    ll n, m;
    cin >> n >> m;
    ll x = ((modexp(2, m) - 1) + MOD) % MOD;
    cout << modexp(x, n);

    return 0;
}

