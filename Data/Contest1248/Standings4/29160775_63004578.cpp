#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i; string _s2="";
    for(_i=0;_i<sz(_s);++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==sz(_s)){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, sz(_s)-_i-1), args...);
} 


template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}

template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(int i = 0; i < sz(v); ++i) {if(i > 0) cout << "_"; cout << v[i];} cout << endl;
    return os;
} 

//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

mt19937 ran(time(0));
const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;
const int int_inf = INT_MAX / 10;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

ll mod = (ll)1e9 + 7;
const ll MAX = 1e5 + 10;
ll fact[MAX], mfact[MAX];

ll elevate(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

//a^(mod - 1) = 1, Euler
ll inv(ll a){
    return elevate(a, mod - 2);
}

void rellenar() {
    int i = 0;
    fact[0] = 1;
    mfact[0] = 1;
    for(i = 1; i < MAX; i++) {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
        mfact[i] = inv(fact[i]);
    }
}

ll comb(ll a, ll b) {
    if(b > a) return -1;
    return ((fact[a] * mfact[b])%mod) * mfact[a-b] %mod;
}

int main(){
    ios::sync_with_stdio(false);
    ll ans = 0, n, m, l, r, cont;
    rellenar();

    cin >> n >> m;
    
    l = n; r = 0;
    while(true) {
        cont = comb(l, r);
        if(cont == -1) break;
        ans += cont;
        ans %= mod;
        l--; r++;
    }
    
    l = m; r = 0;
    while(true) {
        cont = comb(l, r);
        if(cont == -1) break;
        ans += cont;
        ans %= mod;
        l--; r++;
    }
    
    ans = (ans -1 + mod) %mod;
    ans *= 2;
    ans %= mod;
    cout << ans << "\n";
    
    return 0;
}



