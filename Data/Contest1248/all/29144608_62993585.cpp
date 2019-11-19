#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long  i = 0; i < (n); ++i)
#define repA(i, a, n) for(long long i = a; i <= (n); ++i)
#define repD(i, a, n) for(long long i = a; i >= (n); --i)
#define travMap(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define INF 1e9
#define mod 1000000007
#define ok(i,s) i<s.size()
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<long long int> vi;
typedef vector<vector<long long int> > vii;
typedef vector<pii > vp;
 
ll Gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return Gcd(b%a,a); 
} 
 
 
ll maxx(ll a,ll b){
    if(a>b)
        return a;
    return b;
}
ll minn(ll a,ll b){
    return a+b-maxx(a,b);
}
 
 
ll Ceil(ll a,ll b){
    if(a%b==0)
        return a/b;
    return a/b +(a*b<0?0:1);
 
}
 
ll Floor(ll a, ll b){
    return a/b-(a*b<0?1:0);
}
 
ll abso(ll a){
	if(a>0)
		return a;
	return -a;
}
 

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
 	ll n,m;
 	cin>>n>>m;
 	ll num = maxx(n,m);
 	vi a_s(num,0),a_d(num,0);
 	rep(i,num){
 		if(i==0){
 			a_s[0] = 2;
 			a_d[0] = 0;
 			continue;
 		}
 		if(i== 1){
 			a_s[1] = 2;
 			a_d[1] = 2;
 			continue;
 		}
 		a_s[i] = (a_d[i-1]+a_s[i-1])%mod;
 		a_d[i] = a_s[i-1];
 	}
 	ll ans = ((a_s[n-1]+a_d[n-1])%mod+ (a_s[m-1]+a_d[m-1]-2)%mod)%mod;
 	cout<<(ans);
}