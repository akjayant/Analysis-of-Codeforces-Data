#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define whole(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = int(1e5) + 2;
const int LG = 20;
const ll mod = (int)1e9 + 7;
const int INF = (int)1e9 + 7;
const ll linf = 1e13;
const ld pi = acos(-1);
const int base = 10;
const ld EPS = 1e-9;

int tt, a[1005];
int main (){
    scanf ("%d", &tt);
    while (tt--){
        int n;
        scanf ("%d", &n);
        memset (a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i) scanf ("%d", a + i);
        sort (a + 1, a + n + 1);
        reverse (a + 1, a + n + 1);
        int mn = INF, ans = -1;
        for (int i = 1; i <= n; ++i){
            mn = min(mn, a[i]);
            if (mn < i) break;
            ans = i;
        }
        printf ("%d\n", ans);
    }
    return 0;
}
