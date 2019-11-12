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
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){

		int a, b, c, ret = 0; cin >> a >> b >> c;
		for(int x = 0; x <= 100; ++x){

			for(int y = 0; y <= 100; ++y){

				if(x <= a && 2 * x + y <= b && 2 * y <= c) ret = max(ret, 3 * x + 3 * y);
			}
		}
		cout << ret << endl;
	}
    return 0;
}
