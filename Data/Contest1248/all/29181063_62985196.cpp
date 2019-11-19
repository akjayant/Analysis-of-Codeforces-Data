#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define m_p make_pair
#define p_i pair<int, int> 
#define maxn 12
#define maxm 505
#define _for(i, a) for(LL i = 0; i < (a); i++)
#define _rep(i, a, b) for(LL i = (a); i <= (b); i++)
#define outval(a) cout<<#a<<": "<<a<<"\n"
using namespace std;
typedef long long LL;
const LL MAXN = 110;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
typedef vector< double > vec;
typedef vector< vec > mat;

const double eps = 1e-8;



void init() {

}



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);

	int T;
	cin >> T;
	while (T--) {
		int n[2], p;
		LL jishu[2] = { 0 }, oushu[2] = { 0 };
		_for(i, 2) {
			cin >> n[i];
			_for(j, n[i]) {
				cin >> p;
				if (p % 2) jishu[i]++;
				else oushu[i]++;
			}
		}
		cout << jishu[0] * jishu[1] + oushu[0] * oushu[1] << "\n";
	}
	return 0;
}

/*

*/
