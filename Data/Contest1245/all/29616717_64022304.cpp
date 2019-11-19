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
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

int IT_MAX = 1 << 17;

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;


mt19937 mrand(random_device{}());

int rnd(int x) { return mrand() % x; }


template<class T>
void splitstr(const string &s, vector<T> &out) {
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T>
inline T pow_mod(T p, T e, T M) {
    T ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T) ret;
}

template<class T>
inline T modinverse(T a, T M) { return pow_mod(a, M - 2, M); }

template<class T>
inline T lcm(T a, T b) {
    a = abs(a);
    b = abs(b);
    return (a / gcd(a, b)) * b;
}

template<class T, class X>
inline bool getbit(T a, X i) {
    T t = 1;
    return ((a & (t << i)) > 0);
}

template<class T, class X>
inline T setbit(T a, X i) {
    T t = 1;
    return (a | (t << i));
}

template<class T, class X>
inline T resetbit(T a, X i) {
    T t = 1;
    return (a & (~(t << i)));
}


//#define endl '\n';

/*** TEMPLATE ENDS ***/






ll pow_mod(ll a, ll p, ll mod) { //a^p % mod
    ll res = 1;
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

/*
 *
 *
 *
 
 */



int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

//char C[100008];

//ll P[100008];
const ll mod = 1e9 + 7;


const int limit  =2008;
int X[limit];
int Y[limit];
int C[limit];
int K[limit];
int visited[limit];
ll  maxcost[limit];

void solve() {
//int n, m,h;
    //       scanf("%d %d %d", &n, &m,&h);
    int t, m, k;
    int a, b, c, n;

    t = 1;

    //  scanf("%d", &n);
    //  scanf("%d",&t);

    while (t--) {
        //   scanf("%d",&n);


        //  scanf("%d %d %d", &a, &b,&c);
    //    scanf("%s", C + 1);
     //   int n = strlen(C + 1);

          scanf("%d",&n);
          for(int i = 1; i<=n;++i){
              scanf("%d",&X[i]);
              scanf("%d",&Y[i]);
          }

        for(int i = 1; i<=n;++i){
            scanf("%d",&C[i]);

        }
        for(int i = 1; i<=n;++i){
            scanf("%d",&K[i]);
        }
        maxcost[0]=0;

        vector<int> Pstation(0);
        vector<pair<int,int>> Wires(0);


        priority_queue<pair<ll,pair<int,int>>,   vector<pair<ll,pair<int,int>>>,greater<>> pq;

        visited[0]=1;
        for(int i = 1; i<=n;++i) {
            pq.push({C[i], {i, 0}});
            maxcost[i]=C[i];
        }

     //   int cntP=0;
      //  int cntW=0;
        int n1 = n+1;
        int cntvisited=1;
        ll totcost = 0;
        while(cntvisited<n1){
            auto a = pq.top();
            pq.pop();
            if(visited[a.second.first])
                continue;
            totcost+=a.first;
            int i = a.second.first;
            int j=a.second.second;
            visited[i]=1;
            cntvisited++;
            if(j==0){
               Pstation.push_back(i);
            } else
                Wires.push_back({j,i});


            int xi=X[i];
            int yi=Y[i];
            int ki = K[i];
            for(int v = 1; v<=n;++v)
                if(!visited[v]){
                    ll costiv= (ll)(abs(X[v]-xi)+abs(Y[v]-yi))* (ki+K[v]);
                    if(costiv<maxcost[v]){
                        maxcost[v]=costiv;
                        pq.push({costiv,{v,i}});
                    }

                }
        }


        printf("%lld\n",totcost);
        printf("%d\n",Pstation.size());
        for(int i = 0; i<Pstation.size();++i){
            if(i>=1)
                printf(" %d",Pstation[i]);
            else
                printf("%d",Pstation[i]);
        }
        printf("\n");

        printf("%d\n",Wires.size());

        for(int i = 0; i<Wires.size();++i){
            printf("%d %d\n",Wires[i].first,Wires[i].second);
        }


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