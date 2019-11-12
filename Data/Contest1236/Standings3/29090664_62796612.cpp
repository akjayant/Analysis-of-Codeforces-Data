#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define sz(a) ((int)a.size())
#define mem(a, b) memset(a, b, sizeof a)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid (l + r >> 1)
const int maxn = 3e2 + 5;
const int maxm = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> ans[maxn];

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; ++i){

		for(int j = 1; j <= n; ++j){

			if(i & 1){

				ans[j].pb((i - 1) * n + j);
			}
			else{

				ans[n - j + 1].pb((i - 1) * n + j);
			}
		}
	}
	for(int i = 1; i <= n; ++i){

		for(int j = 0; j < n; ++j) cout << ans[i][j] << " ";
		cout << endl;
	}
    return 0;
}
