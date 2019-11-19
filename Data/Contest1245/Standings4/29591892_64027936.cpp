//#pragma GCC optimize("O3")
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template<class T1,class T2>
ostream& operator << (ostream& out,pair<T1,T2> p)
{
    out<<'('<<p.first<<','<<p.second<<')';
    return out;
}

template<class T1,class T2>
istream& operator >> (istream& in,pair<T1,T2> &p)
{
    in>>p.first>>p.second;
    return in;
}

template<class T>
istream& operator >> (istream& in,vector<T> &v)
{
    for(auto &x:v)
        in>>x;
    return in;
}

template<class T>
ostream& operator << (ostream& out,vector<vector<T>> &v)
{
    for(auto &x:v)
        out<<x<<'\n';
    return out;
}

template<class T>
ostream& operator << (ostream& out,vector<T> &v)
{
    for(auto x:v)
        out<<x<<' ';
    return out;
}

long long gcd(long long a,long long b)
{
    if(b>a) swap(a,b);
    return (b?gcd(b,a%b):a);
}

#define ll         long long
#define ull        unsigned long long
#define pii        pair<int,int>
#define pll        pair<long long,long long>
#define tiii       pair< pair<int,int>,int >
#define vb         vector<bool>
#define vi         vector<int>
#define vl         vector<long long>
#define vvi        vector<vector<int>>
#define vvl        vector<vector<long long>>
#define First      first.first
#define Second     first.second
#define Third      second
#define pb         push_back
#define mp         make_pair
#define rep(i,a,b) for(register int i=a;i<b;i++)
#define all(x)     x.begin(),x.end()
#define lbnd       lower_bound
#define ubnd       upper_bound
#define acc        accumulate
#define F          first
#define S          second
#define throwex    throw runtime_error("Found the error.");

#define h          1000000007

const long double pi=2*asin(1);

int n;
vl x,y,c,k;
vi par, z, in;
ll ans;

int root(int x)
{
    while(par[x]!=x)
        x=par[x];
    return x;
}

void unin(int a,int b)
{
    // int a=root(x), b=root(y);
    if(z[b]>z[a])
        swap(a,b);
    par[b] = a;
    z[a] += z[b];
    if(c[in[b]]<c[in[a]])
        in[a] = in[b];
}

signed main()
{
    ios::sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    cerr.setstate(ios::failbit);
    #endif

    cin>>n;
    par.resize(n);
    z.resize(n,1);
    rep(i,0,n)
        par[i] = i;
    in.resize(n);
    rep(i,0,n)
        in[i] = i;
    x.resize(n);
    y.resize(n);
    c.resize(n);
    k.resize(n);
    rep(i,0,n)
        cin>>x[i]>>y[i];
    cin>>c>>k;

    ans = acc(all(c), 0LL);
    priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<pair<ll,pii>>> pq;
    rep(i,0,n)
    {
        rep(j,i+1,n)
            pq.push(mp((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),mp(i,j)));
    }

    vector<pii> conn;

    while(!pq.empty())
    {
        int a=pq.top().S.F, b=pq.top().S.S;
        int ra=root(a), rb=root(b);
        if(ra!=rb && pq.top().F<=max(c[in[ra]], c[in[rb]]))
        {
            ans-=max(c[in[ra]], c[in[rb]]);
            ans+=pq.top().F;
            unin(ra,rb);
            conn.push_back(pq.top().S);
        }
        pq.pop();
    }
    cout<<ans<<'\n';
    int cnt=0;
    vi v;
    rep(i,0,n)
        if(par[i]==i)
            cnt++, v.push_back(in[i]+1);
    cout<<cnt<<'\n'<<v<<'\n';
    cout<<conn.size()<<'\n';
    for(auto x:conn)
        cout<<x.F+1<<' '<<x.S+1<<'\n';
}
