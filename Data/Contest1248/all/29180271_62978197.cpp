//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int Main(){
	int n, m;
	cin >> n;
	ll cntn0 = 0, cntn1 = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x % 2 ==0) cntn0++;
		else cntn1 ++;
	}
	cin >> m;
	ll cntm0 = 0, cntm1 = 0;
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		if (x % 2 == 0) cntm0 ++;
		else cntm1 ++;
	}
	cout << cntn0 * cntm0 + cntm1 * cntn1 << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) Main();













	return 0;
}

