#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define SZ(x) ((int)(x.size()))
#define FOI(i, a, n) for(int i = int(a); i <= int(n); i++)
#define FOD(i, a, n) for(int i = int(a); i >= int(n); i--)
#define IN(x, y) ((y).find(x) != (y).end())
#define ALL(t) t.begin(),t.end()
#define MSET(tabl,i) memset(tabl, i, sizeof(tabl))
#define PSET(x,y) fixed<<setprecision(y)<<lf(x)
#define DBG(c) cout << #c << " = " << c << endl;
#define Rtime1 ((double)clock()/(double)CLOCKS_PER_SEC)
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef long double lf;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef vector < int > vi;
typedef vector<vi> vvi;
typedef complex<double> base;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

const int N = 2e5 + 5;
const int lgN = 1e6+5;
const int te = 3e8+1;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1299709;
const ll MOD3 = 1e9 + 9;
const lf pi = 3.141592653589793238462643383;
const ll IMAX = 4e18 + 5; 
const double PI = 3.141592653589793;


template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>; 
template<class T>
using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll x,y;
template<class T> T gcd(T a,T b){ if(a==0) {x=0,y=1; return b;}T gc=gcd(b%a,a);T temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll po(ll a, ll x,ll m){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 

deque<int> tc[N], tr[N];



int main() {
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    FOI(i,1,k) {
        int u,v;
        cin>>u>>v;
        tr[u].pb(v);
        tc[v].pb(u);
    }
    FOI(i,1,n)
    sort(tr[i].begin(), tr[i].end());
    FOI(i,1,m)
    sort(tc[i].begin(), tc[i].end());
    int nu = 1;
    int nd = n;
    int nl = 1;
    int nr = m;
    int md = 0;
    FOI(i,1,n+m) {
        if(md == 0) {
            if(tr[nu].size()>0) {
                FOI(j, tr[nu].front(), nr) {
                    if(tc[j].size() != (nd+1-nu)) {
                        cout<<"No";
                        return 0;
                    }
                }
                int st = tr[nu].front();
                FOI(j, tr[nu].front(), nr) {
                    for(auto u: tc[j]) {
                        tr[u].pop_back();
                    }
                }
                nr = st-1;
            } 
            nu++;
        } else if (md==1) {
            if(tc[nr].size()>0) {
                FOI(j, tc[nr].front(), nd ) {
                    if(tr[j].size() != (nr+1-nl)) {
                        cout<<"No";
                        return 0;
                    }
                }
                                int st = tc[nr].front();

                FOI(j, tc[nr].front(), nd ) {
                    for(auto u:tr[j]) {
                        tc[u].pop_back();
                    }
                }
                nd = st - 1;
            }
            nr--;
        } else if (md==2) {
            if(tr[nd].size()>0) {
                FOD(j, tr[nd].back(), nl ) {
                    if(tc[j].size() != (nd+1-nu)) {
                        cout<<"No";
                        return 0;
                    }
                }
                                int st = tr[nd].back();

                FOD(j, tr[nd].back(), nl ) {
                    for(auto u:tc[j]) {
                        tr[u].pop_front();
                    }
                }
                nl = st + 1;
            }
            nd--;
        } else {
            if(tc[nl].size()>0) {
                FOD(j, tc[nl].back(), nu ) {
                    if(tr[j].size() != (nr+1-nl)) {
                        cout<<"No";
                        return 0;
                    }
                }
                int st = tc[nl].back();
                FOD(j, tc[nl].back(), nu ) {
                    for(auto u:tr[j]) {
                        tc[u].pop_front();
                    }
                }
                nu = st + 1;
            }
            nl++;
        }
        if(nu > nd) break;
        if(nl > nr) break;
        md = (md + 1)%4;
    }
    cout<<"Yes";
}