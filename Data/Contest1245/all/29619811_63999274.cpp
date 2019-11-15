#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It map<ll, ll>::iterator
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

const ll N = 2e5+5;
ll t, a, b;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--){
		cin>>a>>b;
		if (__gcd(a, b) == 1){
			cout<<"Finite"<<'\n';
		}
		else{
			cout<<"Infinite"<<'\n';
		}
	}
	
	return 0;
}