#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 5*100000+1;
const int MOD = 1000000007;
const ll MAX = 10000000000;
const int oo = 1e9;
ll n , m;

ll adl(ll a , ll b){
	return (a+b)%MOD;
}
ll mul(ll a , ll b){
	return (a*b)%MOD;
}
ll fast(ll a , ll b){
	if(!b)return 1ll;
	ll res = fast(a,b/2);
	res = mul(res,res);
	if(b&1)return mul(res,a);
	return res;
}

int main(){
	cin >> n >> m;
	ll one = (fast(2,m)-1+MOD)%MOD;;
	ll ans = fast(one,n);
	cout << ans << endl;
	return 0;
}