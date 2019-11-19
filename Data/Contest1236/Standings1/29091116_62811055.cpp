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

const int limit  =100008;
vector<int> X[limit];
vector<int> Y[limit];


void solve() {
//int n, m,h;
    //       scanf("%d %d %d", &n, &m,&h);
    int n,m,k;
  //  scanf("%d", &n);
    scanf("%d %d %d", &n, &m,&k);

    for(int i = 0; i<k;++i){
        int x,y;
        scanf("%d %d", &x, &y);
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for(int i = 1; i<=n;++i) {
        X[i].push_back(0);
        X[i].push_back(m+1);
        sort(X[i].begin(),X[i].end());
    }
    for(int j = 1; j<=m;++j) {
        Y[j].push_back(0);
        Y[j].push_back(n+1);
        sort(Y[j].begin(),Y[j].end());
    }
    int x=1;
    int y = 0;
    int op = 0; // --> right

    long long cnt = 0;
    int x1 = 1,x2=n;
    int y1=1, y2=m;
    while(1){
        if(op==0){
            int v = upper_bound(X[x].begin(),X[x].end(),y)-X[x].begin();
            v = X[x][v];
            v--;
            v=min(v,y2);
            if(v<=y)
                break;

            cnt+=v-y;
            y=v;
            x1++;
            y2=v;

            if(x1>x2)
                break;


            op++;
        }
        else if(op==1){
            int v = upper_bound(Y[y].begin(),Y[y].end(),x)-Y[y].begin();
            v = Y[y][v];
            v--;
            v = min(v,x2);
            if(v<=x)
                break;
            cnt+=v-x;
            x=v;
            y2--;
            x2=v;
            if(y2<y1)
                break;


            op++;
        }
        else if (op==2){
            int v = lower_bound(X[x].begin(),X[x].end(),y)-X[x].begin();
            v = X[x][v-1];
            v++;
            v=max(v,y1);
            if(v>=y)
                break;

            cnt+=y-v;
            y=v;
            x2--;
            y1=v;

            if(x1>x2)
                break;

            op++;
        }
        else {


            int v = lower_bound(Y[y].begin(),Y[y].end(),x)-Y[y].begin();
            v = Y[y][v-1];
            v++;
            v = max(v,x1);
            if(v>=x)
                break;
            cnt+=x-v;
            x=v;
            y1++;
            x1=v;
            if(y2<y1)
                break;

            op=0;
        }

    }

    ll emp = (ll)n*m-k;
    if(emp==cnt){
        printf("Yes\n");
    }
else{
        printf("No\n");
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