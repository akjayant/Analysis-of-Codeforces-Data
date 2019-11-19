#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
const long double PI = 3.141592653589793238462643383;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
long long int Ceil(int a, int b){
    if(a%b==0) return a/b;
    else return (a/b)+1;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    ll s=0;
    for(int i=0;i<n;i++)
    	s=s+a[i];
    ll ans=s*s;
    ll e=0;
    for(int i=0;i<n/2;i++){
    	e=e+a[i];
    }
    ans=ans+2*e*(e-s);
	sort(a,a+n,greater<ll>());e=0;
	for(int i=0;i<n/2;i++){
    	e=e+a[i];
    }
    ans=max(ans,s*s+2*e*(e-s));
	cout<<ans;
    return 0;
}