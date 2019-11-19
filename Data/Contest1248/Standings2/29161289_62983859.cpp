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
const int N = 1e5 + 1;
int n, a[N];
ll sum, sum2;
int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n; ++ i){
		cin >> a[i];
		sum2 += a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n / 2; ++ i){
		sum += a[i];
	}
	sum2 -= sum;
	cout << sum2 * sum2 + sum * sum;
	return 0;
}