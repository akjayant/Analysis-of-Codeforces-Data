#include <bits/stdc++.h>
#include <unistd.h>
#define mp make_pair
#define pb push_back
#define cl clear
#define in insert
#define er erase
#define S second
#define F first
#define endl "\n" 
#define all(v) (v).begin(), (v).end()
#define getbit(x, i) ((x >> i)&1)
#define sz(v) (v).size()
#define fr(i, a, b, d) for(ll i = a; i < b; i+= d)
#define frr(i, a, b, d) for(ll i = a; i >= b; i -= d)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define pll pair < ll, ll >
#define pii pair < int, int >
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
using namespace std;
const int N = 400005;
const ll M = 1e9 + 7;	
int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		int ans = n;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				ans = max(ans, max(n+1, max((i+1)*2, (n-i)*2)));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}