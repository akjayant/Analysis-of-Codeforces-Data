#include <bits/stdc++.h>
#define Speed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define st              first
#define nd              second
#define pb              push_back
#define pf              push_front
#define all(a)          (a).begin(), (a).end()
#define lwb             lower_bound
#define upb             upper_bound
#define vvll            vector<vector<ll> >
#define Mset(s, n)      memset(s, n, sizeof(s))
#define Sz(a)           int((a).size())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))
#define Unique(a)       sort(all(a)); (a).resize(unique(all(a)) - (a).begin())

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const int oo = 2e9;
const ld PI = acos((ld) -1);
int Getbit(ll x, int k){return (x >> (k - 1)) & 1;}
ll Lcm(ll a, ll b) {return a / __gcd(a, b) * b;}
bool isPrime(ll n){for(ll i = 2; i * i <= n; i++){if(n % i == 0) return 0;} return (n > 1) ? 1 : 0;}
ll Powmod(ll n, ll k, ll p = MOD) {ll r = 1; for(; k; k /= 2, n = n * n % p){if(k & 1) r = r * n % p;} return r;}

const int N = 1e5 + 5;

ll n, m, k, query, ans;
ll a[N];


void Solve(){
    string s, t;
    cin >> n;
    cin >> s >> t;
    vector<pii> res;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            bool ok = false;
            for(int j = i + 1; j < n; j++){
                if(t[j] == t[i] && t[j] != s[j]){
                    res.pb({i, j});
                    swap(t[j], s[i]);
                    ok = true;
                    break;
                }
            }
            if(ok) continue;
            for(int j = i + 1; j < n; j++){
                if(s[j] == t[i] && t[j] != s[j]){
                    swap(t[j], s[j]);
                    swap(t[j], s[i]);
                    res.pb({j, j});
                    res.pb({i, j});
                    ok = true;
                    break;
                }
            }
            if(!ok){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    cout << Sz(res) << "\n";
    for(auto p: res){
        cout << p.st + 1 << " " << p.nd + 1 << "\n";
    }
}

int main(){
    Speed;
    int query = 1; //
    cin >> query;
    while(query--){
        Solve();
    }
}












