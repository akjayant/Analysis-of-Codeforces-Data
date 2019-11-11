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

int dig[303],ar[303],taken[1003];
char got[303];
string s;

int main () {

    #ifdef LOCAL
    freopen ( "00_input.txt", "r", stdin ); //freopen ( "00_output.txt", "w", stdout );
    #endif
    
    fast_cin;

    dig['R'] = 0;
    dig['S'] = 1;
    dig['P'] = 2;

    got[0] = 'R';
    got[1] = 'S';
    got[2] = 'P';
    
    

    int t; cin >> t;

    int win,threshold,a,b,c,n,flag,x,y,z;

    while(t--) {

        cin >> n;
        cin >> a >> b >> c;
        cin >> s;

        ar[0] = a; //rock
        ar[1] = c;  //scissor
        ar[2] = b; //paper

        mem(taken,-1);

        flag = 0;
        win = 0;

        FOR(i,0,n-1) {

            x = dig[ s[i] ];
            y = (x+1) % 3;
            z = (y+1) % 3;

            if(ar[z]) {
                ar[z]--;
                taken[i] = z;
                win++;
            }
        }

        FOR(i,0,n-1) {

            if(taken[i] != -1) continue;

            x = dig[ s[i] ];
            y = (x+1) % 3;
            z = (y+1) % 3;

            if(ar[x]) {
                ar[x]--;
                taken[i] = x;
            }

            else if(ar[y]) {
                ar[y]--;
                taken[i] = y;
            }
        }

        threshold = (n+1) / 2;

        if(win >= threshold) {
            flag = 0;
        }

        else {
            flag = 1;
        }

        if(flag) {
            cout << "NO" << endl;
        }

        else {
            cout << "YES" << endl;
            
            FOR(i,0,n-1) {
                cout << got[ taken[i] ];
            }

            cout << endl;
        }
    }





    return 0;
}

