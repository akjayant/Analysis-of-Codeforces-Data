#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;cin >> n;
	ll m = n;
	int cnt = 0;
	ll ans = 0;
	for(ll i = 2; i * i <= n; i++){
		if(m % i == 0){
			cnt++;
			ans = i;
		}
		while(m % i == 0){
			m /= i;
		}
	}
	if(m != 1 && n != m) cnt++;
	if(cnt == 0) cout << n << endl;
	else if(cnt == 1) cout << ans << endl;
	else cout << 1 << endl;
}