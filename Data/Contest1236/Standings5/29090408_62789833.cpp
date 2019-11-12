#define task "test"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define fs first
#define sc second
#define FOR(x,a,b) for (int x = a; x<=b; x++)
#define FOD(x,a,b) for (int x = b; x>=a; x--)
#define pb push_back

const int INF = 1E9;
const ll INFll = 1E16;
const int nmax = 2E5 + 5;
int t = 1;
const int MOD = 1E9 + 7;
ll n,m;

ll POW(ll n, ll k)
{
    if (k == 1) return n;
    ll tmp = POW(n,k/2);
    tmp = tmp * tmp % MOD;
    if (k % 2 == 0) return tmp;
    return tmp * n % MOD;
}

void INPUT()
{
    cin >> n >> m;
}




void INIT()
{

}


void SOLVE()
{
    ll tmp = POW(2,m) - 1;
    ll res = POW(tmp, n);
    cout << res << endl;

}

int main()
{
    if (fopen(task ".inp","r")){
        freopen(task ".inp","r",stdin);
        freopen(task ".out","w",stdout);
    }
    INPUT();
    INIT();
    while (t--) SOLVE();
}
