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
int dp[102020],n;
string s;
int solve(int i){
    if(i == n)return 1;
    if(dp[i] + 1)return dp[i];
    dp[i] = solve(i + 1);
    if(i + 1 < n && s[i] == 'n' && s[i + 1] == 'n'){
        dp[i] = (dp[i] + solve(i + 2)) % mod;
    }
    if(i + 1 < n && s[i] == 'u' && s[i + 1] == 'u'){
        dp[i] = (dp[i] + solve(i + 2)) % mod;
    }
    return dp[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);

    cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] == 'w' || s[i] == 'm')return cout << 0 << '\n' ,0;
    }
    memset(dp,-1,sizeof dp);
    cout << solve(0) << '\n';
    return 0;
}
