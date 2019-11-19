#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;

#define fi first
#define se second
#define INF 1e9 + 5
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

vvvd memo;
vvi G;

void advance(int& i, int& j, int k) {
	if(i%2) {
		j += k;
		if(j >= 10) {
			i--;
			j = 19 - j;
		}
	}
	else {
		j -= k;
		if(j < 0) {
			i--;
			j = - j - 1;
		}
	}
	//if(j < 0 or i < 0) cerr << "SEGFAULT\n";
}

double dp(int i, int j, int ld) {
//	cerr << "dp: " << i << " " << j << endl;
	double& ans = memo[i][j][ld];
	if(fabs(ans + 1) > 1e-9) return ans;
	if(i == 0) {
		if(j == 0) return 0;
		if(j <= 6) {
//			cerr << "dp2: " << i << " " << j << endl;
			ans = 6.0 - j;
			for (int k = 1; k <= j; ++k) {
				ans += dp(i, j-k, 0) + 1.0;
			}
			ans /= double(j);
			return ans;
		}
	}
//	cerr << "dp3: " << i << " " << j << endl;
	ans = 0.0;
	for (int p = 1; p <= 6; ++p) {
		int k = i, l = j;
		advance(k, l, p);
		ans += dp(k, l, 0);
	}
	ans /= 6.0;
	ans++;
//	cerr << "dp4: " << i << " " << j << endl;
	if(G[i][j] and not ld) ans = min(ans, dp(i-G[i][j], j, 1));
	return ans;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	G = vvi(10, vi(10));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> G[i][j];
		}
	}
	memo = vvvd(10, vvd(10, vd(2, -1.0)));
	cout << dp(9, 0, 0) << endl;
}


