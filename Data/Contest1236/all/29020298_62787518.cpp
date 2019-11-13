//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;

ll n, a[N], m;

ll POW(ll x, ll t){
	if (t == 0) return 1;
	if (t % 2 == 0) return POW(x * x % MOD, t / 2);
	return x * POW(x, t - 1) % MOD;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;	
	cout << POW(POW(2, m) - 1, n);












	return 0;
}

