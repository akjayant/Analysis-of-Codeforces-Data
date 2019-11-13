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

int main(){
	int n;
	cin >> n;
	ll a,b,c;
	while(n--){
		cin >> a >> b >> c;	
		ll x = min(c/2, b);
		b -= x;
		ll ans = 3*x + 3*min(b/2, a);
		cout << ans << endl;
	}
	return 0;
}