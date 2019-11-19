#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int a, b, c, d, k;
		cin >> a >> b >> c >>d >> k;
		int x = (a + c - 1) / c;
		int y = (b + d - 1) / d;
		if(x + y <= k){
			cout << x << " " << y << '\n';
		}
		else cout << -1 << '\n';
	}
}