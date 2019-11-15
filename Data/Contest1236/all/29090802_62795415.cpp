#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll ((ll) 1e18 + 10)

#define endl '\n'
#define fi first
#define se second
#define pb emplace_back
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); i--)

const int N = 330;
bool flag;
int n, k, a[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	rep(i, 0, n) {
		if (flag) rep(j, 0, n) a[i][j] = ++k;
		else repd(j, n, 0) a[i][j] = ++k;
		flag = !flag;
	}
	rep(j, 0, n) {
		rep(i, 0, n) cout << a[i][j] << " ";
		cout << endl;
	}
}
