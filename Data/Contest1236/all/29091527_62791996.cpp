#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int) (v).size()
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define pb push_back
#define mp make_pair

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int inf = 0x3f3f3f3f;
constexpr ll MOD = 1000000007LL;
constexpr double tol = 1e-8;

void buff() { ios::sync_with_stdio( false ); cin.tie(nullptr); }


int main() 
{
    buff();
    int n;
    cin >> n;
    vector< vi > groups(n);

    for(int i = 0; i < n * n; ++i)
    {
        int pos = (i % n);
        if( (i/n) % 2 == 0 ) {
            groups[pos].push_back(i + 1);  
        }
        else
        {
            groups[n - 1 - pos].push_back(i + 1);
        }
    }
    for( const auto& x : groups ) {
        for(int v : x ) cout << v << " ";
        cout << endl;
    }
    return 0;
}

