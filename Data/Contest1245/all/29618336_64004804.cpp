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
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(3);
        for(int j = 0; j < 3; j++) cin >> v[j];
        string s;
        cin >> s;
        string ans = s;
        for(auto& i : ans) i = '$';
        int win = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'R'){
                if(v[1]) v[1] --, win ++, ans[j] = 'P';
            }
            if(s[j] == 'P'){
                if(v[2]) v[2] --, win ++, ans[j] = 'S';
            }
            if(s[j] == 'S'){
                if(v[0]) v[0] --, win ++, ans[j] = 'R';
            }
        }
        vector<char> x = {'R', 'P', 'S'};
        for(auto &i : ans)
            if(i == '$'){
                int fg = 0;
                for(int j = 0; j < 3 && !fg; j++)
                    if(v[j]) v[j] --, i = x[j], fg = 1;
            }
        // cout << ans << endl;
        int had_to = ceil((double)n/(double)2);
        if(win >= had_to) cout << "YES\n" << ans << '\n';
        else cout << "NO\n";
    }
    return 0;
}
