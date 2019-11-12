#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int, int> mii;

#define fastIO \
ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair 

ll power(ll base, ll power) {
	ll result = 1;
	while(power){
    	if(power&1)	result = (result*base)%MOD;
    	base = (base*base)%MOD;
    	power >>= 1;
	}
	return result;
}

int main(){
	ll n, m;
	cin >> n >> m;
	ll ans = power(2,m)-1;
	ans = power(ans,n);
	cout << ans << endl;
	return 0;
}