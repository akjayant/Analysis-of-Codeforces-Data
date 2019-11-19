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

ll n, a[N], Sum[2];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}	
	sort(a, a + n);
	for (int i = 0; i < n / 2; i++) Sum[0] += a[i];
	for (int i = n / 2; i < n; i++) Sum[1] += a[i];
	cout << Sum[0] * Sum[0] + Sum[1] * Sum[1];









	return 0;
}

