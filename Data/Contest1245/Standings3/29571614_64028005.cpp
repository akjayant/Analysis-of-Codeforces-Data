#include <bits/stdc++.h>


#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod) x-=mod;if(x<0) x+=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))
#define Set(N,cur) N=(N|(1LL<<cur))
#define Reset(N,cur) N=(N&(~(1LL<<cur)))
#define Check(N,cur) (!((N&(1LL<<cur))==0))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dump(x) cerr<<"~ "<<#x<<" = "<<x<<endl
//Imran addition
#define rep(i,n) for(int i = 1; i <= n; i++)
#define mem CLR
#define pf printf
#define sc scanf
#define endl "\n"
#define gi(k) scanf("%d",&k)
#define gl(k) scanf("%lld",&k)
#define NMAX 2147483647
#define LMAX 9223372036854775807LL

using namespace std;


#define LL long long
#define LLU long long unsigned int
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<int> vi;
typedef vector<vlong> vl;
typedef vector<pll> vll;

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}


const vlong inf = 2147383647;
const vlong mod = 1000000007;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

///_______________Template Ends Here_______________///
#define N 2005

vlong cost[N],fit[N];
pll ar[N];
pair<vlong, pii> edge[4000006];
int pos,par[N],cnt;

vector<pii> v;

int find(int x) {
    if(x == par[x]) return x;
    return (par[x] = find(par[x]));
}

int main () {

    #ifdef LOCAL
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
    #endif
    
    fast_cin;

    vlong ans,mx,d,n;

    cin >> n;

    FOR(i,1,n) {
        cin >> ar[i].ff >> ar[i].ss;
    }

    FOR(i,1,n) {
        cin >> cost[i];
    }

    FOR(i,1,n) {
        cin >> fit[i];
    }

    ans = 0;
    cnt = 0;

    FOR(i,1,n) {
        par[i] = i;
        ans += cost[i];
        cnt++;
    }

    FOR(i,1,n) {
        FOR(j,i+1,n) {
            
            d = ABS(ar[i].ff - ar[j].ff) + ABS(ar[i].ss - ar[j].ss);
            d = d * (fit[i] + fit[j]);

            edge[++pos] = MP(d,MP(i,j));
        }
    }

    sort(edge+1, edge+pos+1);

    int x,y,a,b;

    FOR(i,1,pos) {

        x = edge[i].ss.ff; y = edge[i].ss.ss;

        a = find(x);
        b = find(y);

        if(a == b) {
            continue;
        }

        mx = max(cost[a], cost[b]);

        if(edge[i].ff < mx) {
            
            ans -= mx;
            ans += edge[i].ff;

            v.pb(MP(x,y));
            cnt--;
            
            if(cost[b] < cost[a]) par[a] = b;
            else par[b] = a;
        }
    }

    cout << ans << endl;
    cout << cnt << endl;

    FOR(i,1,n) {
        if(par[i] == i) {
            cout << i << " ";
        }
    }

    cout << endl;

    cout << SZ(v) << endl;

    FOR(i,0,SZ(v)-1) {
        cout << v[i].ff << " " << v[i].ss << endl;
    }


    return 0;
}

