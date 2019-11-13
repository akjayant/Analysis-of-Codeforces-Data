#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 1e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)1e18;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

// credits : codeforces :https://codeforces.com/blog/entry/54396
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    int fg = 0;
    vector<char> x;
    vector<int> cnt;
    for(int j = 0; j < n; j++){
        char cur = s[j];
        int c  = 0;
        while(j < n && cur == s[j]) c ++, j++;
        j--;
        x.pb(cur);
        cnt.pb(c);
        if(cur == 'm' || cur == 'w') fg = 1;
    }
    if(fg) {
        cout << 0;
        return 0;
    }
    vector<ll> f(N);
    f[1] = 1;
    f[2] = 2;
    for(int j = 3; j < N; j++) f[j] = (f[j-1] + f[j-2]) % mod;
    ll ans = 1;
    for(int j = 0; j < (int)x.size(); j++){
        char i = x[j];
        if(i == 'u' || i == 'n'){
            ans = (ans * f[cnt[j]]) % mod;
        }
    }
    cout << ans;
    return 0;
}
