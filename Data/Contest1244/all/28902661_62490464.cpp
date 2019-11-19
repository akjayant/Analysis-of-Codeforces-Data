#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
template<typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    typename vector<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "}";
}
template<typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
    os << "[";
    typename set<T>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}
template<typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
    os << "[";
    typename map<F, S>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << ", ";
        os << it->first << " = " << it->second;
    }
    return os << "]";
}
#define debug(x) cerr << #x << " = " << x << endl;
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef map<int, int> mii;
typedef vector< pair<int, int> > vpii;

#define endl "\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c),x) != (c).end())
#define F first
#define S second


const ld PI=acos(-1.0);
const ll mod = 1000000007;
const ll inf = (ll) 1e15;

ll power(ll a, ll b, ll m = mod) {if (b == 0) return 1; if (b == 1) return (a % m); ll x = power(a, b / 2, m); x = (x * x) % m; if (b % 2) x = (x * (a%m)) % m;return x;}
ll max(ll a, ll b) { return (a > b ? a : b); }
ll min(ll a, ll b) { return (a < b ? a : b); }

//there will be paths only in graph..choose the permutations

const int N=1e5+5;
const int M=1e5+5;

int n;
ll c[4][N];
vector<int> g[N];
int deg[N];
ll ans=inf,cost=0;
int ptr=0;
int per[3]={1,2,3};
int arrans[3]={1,2,3};
bool print=false;
int col[N];

void dfs(int i,int p)
{
    ptr%=3;
    if(!print)
    {
        cost+=c[per[ptr++]][i];
    }
    else
    {
        col[i]=arrans[ptr++];
    }
    for(auto it : g[i])
    {
        if(it!=p)
        {
            dfs(it,i);
        }
    }
}

void solve() {

    cin >> n;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >>  v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    int maxi=*max_element(deg+1,deg+n+1);
    if(maxi>=3)
    {
        cout << -1 << endl;
        return;
    }
    int start=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
            start=i;
    }
    assert(start!=0);
    dfs(start,-1);
    ans=min(ans,cost);
    while(next_permutation(per,per+3))
    {
        cost=0;
        ptr=0;
        dfs(start,-1);
        if(cost<ans)
        {
            ans=cost;
            for(int i=0;i<3;i++)
            {
                arrans[i]=per[i];
            }
        }
    }
//    cerr << arrans[0] <<" "<< arrans[1] <<" "<< arrans[2] << endl;
    cout << ans << endl;
    print=true;
    ptr=0;
    dfs(start,-1);
    for(int i=1;i<=n;i++)
    {
        cout << col[i] <<" ";
    }

}

int main() {
    IOS;
    int t = 1, num = 1;   ///// change this t for number of testcase globally
    while (t--) {
        solve();
    }
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/