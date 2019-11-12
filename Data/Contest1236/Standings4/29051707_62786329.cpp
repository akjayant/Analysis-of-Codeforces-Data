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
int t, a, b, c;
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		int mx = min(a, b / 2), i = 0;
		while(a && b >= 2){
			mx = max(mx, i + min(b, c / 2));
			++i;
			--a;
			b -= 2;
		}
		mx = max(mx, i + min(b, c / 2));
		cout << max(i, mx) * 3 << endl;
	}
	return 0;
}