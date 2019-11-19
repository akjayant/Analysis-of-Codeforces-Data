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

ll n;
int main (){
    scanf ("%lld", &n);
    if (n == 1) return !printf ("1\n");
    ll div = -1;
    bool another = 0;
    for (ll i = 2; i * i <= n; ++i){
        if (n % i == 0){
            if (div != -1){
                another = 1;
                break;
            }
            div = i;
            while (n % div == 0) n /= div;
        }
    }
    if (n != 1){
        if (div != -1) another = 1;
        div = n;
    }
    if (another) printf ("1\n");
    else printf ("%lld\n", div);
    return 0;
}
