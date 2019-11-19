#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;
typedef unsigned long long ull;

template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

string s = "";
string O = "";

ll memo[30][3][3][3][3];
ll dp(ll at, ll lower1, ll lower2, ll larger1, ll larger2) {
    if(at >= size(s)) return 1;
    if(memo[at][lower1][lower2][larger1][larger2] != -1) {
        return memo[at][lower1][lower2][larger1][larger2];
    }
    ll sm = 0;
    rep(i,0,2) {
        rep(j,0,2) {
            if(i == 1 && j == 1) continue;
            if(lower1 && lower2 && larger1 && larger2) {
                sm += dp(at+1,lower1,lower2,larger1,larger2);
            } else if(lower1 && lower2 && larger1 && !larger2) {
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,lower1,lower2,larger1,j > O[at]-'0');
            } else if(lower1 && lower2 && !larger1 && larger2) {
                if(O[at]-'0' > i) continue;
                sm += dp(at+1,lower1,lower2,i > O[at]-'0',larger2);
            } else if(lower1 && lower2 && !larger1 && !larger2) {
                if(O[at]-'0' > i) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,lower1,lower2, i > O[at]-'0',j > O[at]-'0');
            }

            if(!lower1 && lower2 && larger1 && larger2) {
                if(s[at]-'0'< i) continue;
                sm += dp(at+1,i < s[at]-'0',lower2,larger1,larger2);
            } else if(!lower1 && lower2 && larger1 && !larger2) {
                if(s[at]-'0'< i) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,i < s[at]-'0',lower2,larger1,j > O[at]-'0');
            } else if(!lower1 && lower2 && !larger1 && larger2) {
                if(s[at]-'0'< i) continue;
                if(O[at]-'0' > i) continue;
                sm += dp(at+1,i < s[at]-'0',lower2,i > O[at]-'0',larger2);
            } else if(!lower1 && lower2 && !larger1 && !larger2) {
                if(s[at]-'0'< i) continue;
                if(O[at]-'0' > i) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,i < s[at]-'0',lower2, i > O[at]-'0',j > O[at]-'0');
            }
            if(lower1 && !lower2 && larger1 && larger2) {
                if(s[at]-'0'< j) continue;
                sm += dp(at+1,lower1, j < s[at]-'0',larger1,larger2);
            } else if(lower1 && !lower2 && larger1 && !larger2) {
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,lower1,j < s[at]-'0',larger1,j > O[at]-'0');
            } else if(lower1 && !lower2 && !larger1 && larger2) {
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > i) continue;
                sm += dp(at+1,lower1,j < s[at]-'0',i > O[at]-'0',larger2);
            } else if(lower1 && !lower2 && !larger1 && !larger2) {
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > i) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,lower1,j < s[at]-'0', i > O[at]-'0',j > O[at]-'0');
            }

            if(!lower1 && !lower2 && larger1 && larger2) {
                if(s[at]-'0'< i) continue;
                if(s[at]-'0'< j) continue;
                sm += dp(at+1,i < s[at]-'0', j < s[at]-'0',larger1,larger2);
            } else if(!lower1 && !lower2 && larger1 && !larger2) {
                if(s[at]-'0'< i) continue;
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,i < s[at]-'0',j < s[at]-'0',larger1,j > O[at]-'0');
            } else if(!lower1 && !lower2 && !larger1 && larger2) {
                if(s[at]-'0'< i) continue;
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > i) continue;
                sm += dp(at+1,i < s[at]-'0',j < s[at]-'0',i > O[at]-'0',larger2);
            } else if(!lower1 && !lower2 && !larger1 && !larger2) {
                if(s[at]-'0'< i) continue;
                if(s[at]-'0'< j) continue;
                if(O[at]-'0' > i) continue;
                if(O[at]-'0' > j) continue;
                sm += dp(at+1,i < s[at]-'0',j < s[at]-'0', i > O[at]-'0',j > O[at]-'0');
            }

        }
    }
        return memo[at][lower1][lower2][larger1][larger2] = sm;
    /*
    if(larger1 && larger2) {
        if(lower1 && lower2) {
            return dp(at+1,lower1,lower2,1,1)*3;
        } else if(lower1 && !lower2) {
            if(s[at] == '0') {
                return dp(at+1,1,0,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,1,1,1)+dp(at+1,1,0,1,1);
            }
        } else if(!lower1 && lower2) {
            if(s[at] == '0') {
                return dp(at+1,0,1,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,1,1,1)+dp(at+1,0,1,1,1);
            }
        } else if(!lower1 && !lower2) {
            if(s[at] == '0') {
                return dp(at+1,0,0,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,0,1,1)+dp(at+1,0,1,1,1)+dp(at+1,1,1,1,1);
            }
        }
    } else if(!larger1 && !larger2) {
            return dp(at+1,lower1,lower2,1,1)*3;
        } else if(lower1 && !lower2) {
            if(s[at] == '0') {
                return dp(at+1,1,0,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,1,1,1)+dp(at+1,1,0,1,1);
            }
        } else if(!lower1 && lower2) {
            if(s[at] == '0') {
                return dp(at+1,0,1,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,1,1,1)+dp(at+1,0,1,1,1);
            }
        } else if(!lower1 && !lower2) {
            if(s[at] == '0') {
                return dp(at+1,0,0,1,1);
            } else if(s[at] == '1') {
                return dp(at+1,1,0,1,1)+dp(at+1,0,1,1,1)+dp(at+1,1,1,1,1);
            }
        }
    
    }*/
    return 0;
}

ll sol(ll l, ll r) {
    memset(memo,-1,sizeof(memo));
    s = "";
    O = "";
    rep(i,0,40) {
        if((1ll << i) & (r)) s += "1";
        else s += "0";
    }
    rep(i,0,40) {
        if((1ll << i) & (l)) O += "1";
        else O += "0";
    }
    while(s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    while(O.back() == '0') O.pop_back();
    reverse(O.begin(), O.end());
    while(size(O) != size(s)) O = "0"+O;
    return dp(0,0,0,0,0);
}

void sv() {
    ll l,r;
    cin >> l >> r;
    ll val = sol(l,r);
    cout << val << endl;
}

int main() {
    cin.sync_with_stdio(false);
    ll t;
    cin >> t;
    rep(i,0,t) sv();
    return 0;
}


