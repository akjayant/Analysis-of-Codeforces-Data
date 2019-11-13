/*************

      /\
     / \
    /AC\
   /   \

*************/


//#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>

/*** TEMPLATE START ***/
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif
using namespace std;

typedef vector<string> vs;
typedef complex<double> pnt;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define SZ(x) ((ll) (x).size())

#define pb push_back
#define mp make_pair
#define eb emplace_back

#define fi first
#define se second


typedef tuple<int, int, int> t3;

typedef double db;
typedef long double ldb;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;





mt19937 mrand(random_device{}());

int rnd(int x) { return mrand() % x;}


template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> inline T pow_mod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T modinverse(T a,T M){return pow_mod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}


//#define endl '\n';

/*** TEMPLATE ENDS ***/






/*
 *
 *
 *

 */




const ll mod = 1e9+7;
ll pow_mod( ll a, ll p, ll mod) { //a^p % mod
    if(p>=mod-1)
        p%=mod-1;
    ll res = 1;
    if(a>=mod)
        a %= mod;
    while (p > 0) {
        if (p & 1) {
            //res = mul_mod(res, a, mod);
            res = res * a % mod;
        }
        p >>= 1;
        //a = mul_mod(a,a,mod);
        a = a * a % mod;
    }
    return res;
}


int dp[300][308];


void solve() {
//int n, m,h;
    //       scanf("%d %d %d", &n, &m,&h);
    int n;
    scanf("%d", &n);

    int lo = 1;
    int hi = n*n;

    for(int j=0; j<n;j++){
        for(int i = 0; i<n;++i){
            dp[i][j] = lo++;

        }
        j++;
        for(int i = n-1; i>=0;--i){
            dp[i][j] = lo++;

        }
    }


    for(int i = 0; i<n;++i){
        for(int j = 0; j<n;++j)
            printf("%d ",dp[i][j]);
        printf("\n");
    }




}


int main() {
// ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    clock_t beg = clock();

    solve();


    //   clock_t end = clock();
//fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}