#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define MOD 1000000007
#define CAP 10000000
#define inf 1000000000000000000LL
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(v)    v.begin(),v.end()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y>0){if(y&1)res = (res*x)%md;x = (x*x)%md;y = y>>1;}return res%md;}
#define dbg(x) cout <<#x<<":"<<x<<endl;
ll max1(ll a, ll b, ll c=-inf, ll d=-inf) {ll mx1=(a>b)?a:b, mx2=(c>d)?c:d; return ((mx1>mx2)?mx1:mx2);}
#define int ll

signed main() {
    fast;
    
    int t;
    cin>>t;

    while(t--) {
    	int a,b,c;
    	cin>>a>>b>>c;

    	int ans = 0;

    	int lm = min(c/2,b);

    	for(int i=0;i<=lm;i++) {
    		int aa = a;
    		int bb = b - i;
    		int cc = c - 2*i;
    		ans = max(ans, 3*i + 3*min(aa,bb/2));
    	}
    	cout<<ans<<endl;
    }

}