#ifndef DEBUG
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define Debug(x) cout << "# " << #x _ (x) << endl;
#else
#define Debug(x)
#endif
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fr(i, s, e) for(auto i = (s); i < (e); ++i)
#define endl '\n'
#define _ << ' ' <<
#define Pb push_back
#define Eb emplace_back
#define All(x) x.begin(),x.end()
#define Sz(x) int(x.size())
#define Ft first
#define Sd second

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

inline ll getint() {
	ll x=0,s=1; char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),s=-1;
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*s;
}

const ll MOD7 = 1e9+7;
const ll MAX = 1e6+5;
const ll INF = 1023456789;
const ll IINF = 1234567890123456789LL;

inline ll fpow(ll a, ll b, ll m = MOD7) {
	if (b == 0) return 1%m;
	if (b == 1) return a%m;
	ll r = fpow((a*a)%m, b/2, m);
	return (r*(b&1?a:1) )%m;
}

int main() {
	FAST
	srand(time(NULL)*time(NULL)^hash<ll>{}(INF*time(NULL)%MOD7));

    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x, y, z;
    y = -1;
    Fr(i, 0, w) if ((i*d)%w == p%w) {
        y = i;
        x = (p - y*d)/w;
        z = n-x-y;
        //cerr << x _ y _ z << endl;
        if (min({ x, y, z }) < 0 || x*w+y*d != p)
            continue;
        break;
    }
    if (min({ x, y, z }) < 0) cout << -1 << endl;
    else cout << x _ y _ z << endl;


	return 0;
}

