#include <bits/stdc++.h>
using namespace std;
/// Typedef
typedef long long           ll;
typedef vector<int>         vi;
typedef pair<int,int>       pii;

#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define SQR(x)              ((x)*(x))
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define ROF(i, x, y)        for(int i=int(x); i>=int(y); i--)
#define all(c)              c.begin(), c.end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)

#ifdef VAMP
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

/// Constants
#define MAX                 200005
#define MOD                 1000000007
#define eps                 1e-9
#define INF              	0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932
#define VT                  int

int main(){
    #ifdef VAMP
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n; si(n);
    int ar[n];
    FOR(i, 0, n){
    	si(ar[i]);
    }
    debug(n);
    ll sum[2] = {0};
    sort(ar, ar+n, greater<int>());
    int l = 0, r = n-1;
    while(l<=r){
    	if(l == r) {
    		ll mx = SQR(sum[0] + ar[l]) + SQR(sum[1]);
    		mx = max(mx, SQR(sum[1] + ar[l]) + SQR(sum[0]));
    		cout<<mx<<endl;
    		exit(0);
    	}
    	sum[0] += ar[l++];
    	sum[1] += ar[r--];
    }
    printf("%lld\n", SQR(sum[0]) + SQR(sum[1]));

    #ifdef VAMP
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
    return 0;
}