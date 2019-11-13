#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <deque>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define nl '\n'
 
#define y1 aza_ibagaliev
 
#define f first
#define s second
	
#define ed end()
#define bg begin()
#define rbg rbegin()
 
#define rv reverse
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ppf pop_front
 
#define sz size()
#define all(x) x.bg, x.ed
 
#define pll pair < ll, ll >
#define pii pair < int, int >
 
#define sqr(x) ((x) * 1ll * (x))
#define sqrd(x) ((x) * 1.0 * (x))
 
#define speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define rnl cout << "----------------------------------------" << nl
 
#define bit __builtin_popcount
 
inline ll bip(ll x, ll n, ll mod){ll res=1;while(n){if(n & 1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}
  
const int ppr = 257;
const ll INF = 2e18;
const int inf = 998244353;
const int mod = 1e9 + 7;
const int N = 2e6 + 123;
const ld pi = 3.1741592653589793238462643;
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int t, a, b, c;
 
main() {             	
//  freopen(".in", "r", stdin);                          
//  freopen(".out", "w", stdout);
 
//	srand(time(NUll));
 
	speed;
 
    cin >> t;

    while(t--) {
    	cin >> a >> b >> c;
    	int ans = 0;
    	for(int i = 0; i <= a; i++) {
    		int x = i, y = b, z = c, cur = 0;
    		if(x * 2 > y) break;
    		y -= x * 2;
    		cur += x * 3;
    		x = min(y, z / 2);
    		cur += x * 3;
    		ans = max(ans, cur);
    	}
    	cout << ans << nl;
    }

    return 0;                                        
}     