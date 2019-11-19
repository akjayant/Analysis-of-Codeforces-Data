#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
typedef pair <int, pii> piii;
#define fr first
#define sc second
#define pb push_back
#define ppb pop_back()
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define mpr make_pair
int t, n, p;
ll cnt[2], cnt2[2];
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n; ++ i){
			cin >> p;
			++cnt[p & 1];
		}
		cin >> n;
		for(int i = 1;i <= n; ++ i){
			cin >> p;
			++cnt2[p & 1];
		}
		cout << cnt[0] * cnt2[0] + cnt[1] * cnt2[1] << endl;
		cnt[0] = cnt2[0] = cnt[1] = cnt2[1] = 0;
	}
	return 0;
}