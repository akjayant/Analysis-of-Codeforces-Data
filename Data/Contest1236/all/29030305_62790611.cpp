#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<ll>
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;
ll OO = (ll) 1e18 ;
int Mod = 1e9 + 7;
ll const N = 2e5 + 10;

ll add(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a+=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll mul(ll a,ll b){
    a%=Mod;
    b%=Mod;
    a*=b;
    a%=Mod;
    a+=Mod;
    a%=Mod;
    return a;
}
ll fpow(ll a,ll p){
    if(p==0)return 1;
    if(p&1)return mul(a,fpow(a,p-1));
    return fpow(mul(a,a),p>>1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(cin.failbit);
#ifdef LOCAL
    freopen("in.in", "r", stdin);
#endif
    ll n,m;
    cin >> n >> m;
    cout << fpow(add(fpow(2,m),-1),n);
}
