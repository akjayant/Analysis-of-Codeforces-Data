#include<bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define ll long long
using namespace std;
 
const int INF = 1e9;
const long long LINF = 1e18;
 
void test(){
 
}
 
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll a,b; cin >> a >> b;
		if(__gcd(a,b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
}