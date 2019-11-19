#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)
#define forba(i, b, a) for (int i = (b); i >= (a); i--)
#define mset(a, n) memset(a, n, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define endl '\n'
#ifdef hat
#define fast
#define de(x) cout  << #x << '=' << x << ' '
#define dee(x) cout  << #x << '=' << x << endl
#else
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define de(x) ((void) 0)
#define dee(x) ((void) 0)
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main()
{
    fast;
    int T;
    cin >> T;
    while(T--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a / c + (a % c != 0);
        int y = b / d + (b % d != 0);
        if(x + y > k) cout << -1 << endl;
        else cout << x << ' ' << y << endl;
    }
}