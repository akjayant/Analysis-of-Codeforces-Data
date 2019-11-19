#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef  long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll a,b,c,d,k;
int main() {
    ios :: sync_with_stdio(false); cin.tie(0);
   ll t;cin>>t;
    while(t--) {
    	cin>>a>>b>>c>>d>>k;
    	ll m1 = (a+c-1)/c;
    	ll m2 = (b+d-1)/d;
    	if(m1 + m2 <= k) cout<<m1<<" "<<m2<<'\n';
    	else cout<<-1<<'\n';
    }
}
