// TEMPLATE START

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

const int MOD = 1000000007;
const int INF = 2147483647;
const ll LINF = 1e18;
const ld PI = 4*atan((ld)1);

#define rep(i,a,b) for (int i=(a); i<(b); ++i)
#define repd(i,a,b) for (int i=((int)(a)); i>=(b); --i)
#define trav(a,x)  for (auto& a : x)
#define all(u) begin(u), end(u)
#define sz(x) (int)x.size()
#define xsort(v, m) rep(i, 0, v.size()) m[i] = i; sort(all(m), [=](int i, int j) {return v[i] < v[j];}); sort(v);

#define pb push_back
#define X first
#define Y second

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PREC(n) cout<<fixed<<setprecision(n);

#define db(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#define dbv(v) cerr << __LINE__ << ": " << #v << "\n" << v.size() << "\n" << v << "\n";


template <class T, class S> ostream& operator << (ostream& os, const pair<T, S>& p) {
        os << p.X << " " << p.Y;
    return os;
}

template <class T, class S> istream& operator >> (istream& is,  pair<T, S>& p) {
        is >> p.X >> p.Y;
    return is;
}

template <class T> ostream& operator << (ostream& os, const vector<T>& v) {
    rep(i, 0, v.size())
        os << v[i] << " \n" [i == v.size() - 1];
    return os;
}

template <class T> istream& operator >> (istream& is,  vector<T>& v) {
    rep(i, 0, v.size())
        is >> v[i];
    return is;
}


// TEMPLATE END


// SOLUTION START

ll qpow(ll base, ll exp) {
    ll r = 1;
    while (exp > 0) {
        if (exp % 2 == 0) {
            exp = exp / 2;
            base = (base * base) % MOD;
        }
        else {
            exp--;
            r = (r * base) % MOD;
        }
    }
    return r;
}

int main() {
    FAST_IO
	ll n, m;
    cin >> n >> m;
    cout << qpow(qpow(2, m) - 1, n) << "\n";
    return 0;
}

// SOLUTION END

