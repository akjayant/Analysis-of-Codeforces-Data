#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> dp(101010, 0);
    dp[0] = 1;
    dp[1] = 1;
    REP(i, 100001){
    	dp[i+2] = dp[i+1] + dp[i];
    	dp[i+2] %= mod;
    }

    string s;
    cin >> s;
    ll n = s.size();
    ll res = 1;
    REP(i, n){
    	int j = i;
    	while(j<n && s[i]==s[j]) j++;
    	ll len = j-i;
    	if(s[i]=='m'||s[i]=='w'){
    		cout << 0 << endl;
    		return 0;
    	}
    	if(s[i]=='n'||s[i]=='u'){
    		res *= dp[len];
    		res %= mod;
    	}
    	i = j-1;
    }
    cout << res << endl;
    return 0;
}