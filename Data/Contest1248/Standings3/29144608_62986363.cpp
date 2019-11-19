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
 	ll n;
 	cin>>n;
 	vi a(n,0);
 	vi b(n,0);
 	ll sum = 0;
 	rep(i,n){
 		cin>>a[i];
 		sum+=a[i];
 	}
 	sort(a.begin(),a.end());
 	ll ans = 0;
 	rep(i,n/2){
 		ans+= a[i];
 	}
 	cout<<ans*ans+(sum-ans)*(sum-ans);
}