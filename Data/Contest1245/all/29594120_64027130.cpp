#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second

using namespace std;


#define sim template < class c

#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mod = 1e9  + 7;

ll dp[35][2][2][2][2];
bool L[40],R[40];
ll solve(int i,bool a,bool b,bool c,bool d)
{
    if(i < 0)return 1;
    ll &ret = dp[i][a][b][c][d];
    if(ret + 1)return ret;
    ret = 0;
    // 0 0
    if(!L[i] || (b && d))
    {
        ret = solve(i - 1,a || R[i],b , c || R[i] , d);
    }
    // 1 0
    if((R[i] || a) && (!L[i] || d) )
    {
        ret += solve(i - 1,a ,b || !L[i],c || R[i], d);
    }
    // 0 1
    if((!L[i] || b) && (R[i] || c))
    {
        ret += solve(i - 1,a || R[i],b ,c, d || !L[i]);
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);

    int q; cin >> q;
    for(;q;q--)
    {
        ll l , r;
        cin >> l >> r;
        int cnt = 0;
        memset(R,0,sizeof R);
        memset(L,0,sizeof L);

        while(l > 0){
            L[cnt] = l%2;
            cnt++;
            l/=2;
        }
        cnt = 0;
        while(r > 0){
            R[cnt] = r%2;
            cnt++;
            r/=2;
        }

        memset(dp,-1,sizeof dp);
        cout << solve(34,0,0,0,0) << '\n';
    }

    return 0;
}
