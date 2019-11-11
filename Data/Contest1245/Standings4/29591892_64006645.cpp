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

signed main()
{
    ios::sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    cerr.setstate(ios::failbit);
    #endif

    string s;
    cin>>s;
    if(count(all(s), 'm') || count(all(s), 'w'))
        return cout<<0,0;
    int x=0;
    set<char> c({'n','u'});
    if(c.count(s[0]))
        x++;
    vl dp(s.size());
    dp[0] = 1;
    dp[1] = 2;
    rep(i,2,s.size())
        dp[i] = (dp[i-2] + dp[i-1])%h;
    // cerr<<dp<<'\n';
    ll ans=1;
    rep(i,1,s.size())
    {
        if(x && s[i]!=s[i-1])
        {
            ans*=dp[x-1];
            ans%=h;
            // cerr<<dp[x-1]<<' '<<ans<<'x';
        }
        if(x && s[i]==s[i-1])
            x++;
        else if(!c.count(s[i]))
            x=0;
        else if(c.count(s[i]))
            x=1;
    }
    if(x)
        ans*=dp[x-1], ans%=h;
    cout<<ans;
}
