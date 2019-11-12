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
    
    int n;
    cin>>n;

    int ans[n+1][n+1];

    for(int i=0;i<n;i++) {
    	for(int j=0;j<n;j++) {
    		ans[i][j] = (i*n+j) + 1;
    	}
    	if(i%2) {
    		for(int j=0;j<n/2;j++) {
    			swap(ans[i][j], ans[i][n-1-j]);
    		}
    	}
    }

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<ans[j][i]<<" \n"[j==n-1];
}