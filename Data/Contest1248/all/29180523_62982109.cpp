#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It set<ll>::iterator
    
using namespace std;

const ll N = 1e5+5, mod = 1e9+7;
ll n, a[N];

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    ll sum = 0;
    for (ll i = 1; i <= n; i++){
    	cin>>a[i]; sum += a[i];
	}
	sort(a+1, a+n+1);
	ll tmp = 0;
	for (ll i = 1; i <= n/2; i++){
		tmp += a[i];
	}
	cout<<tmp*tmp+(sum-tmp)*(sum-tmp)<<endl;
    
    return 0;
}