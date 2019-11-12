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

const int N = 300 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;

int n;

vi a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int pnt = 1;
	bool f = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			for (int j = 0; j < n; j++){
				a[j].pb(i * n + j + 1);
			}
		}else{
			for (int j = 0; j < n; j++){
				a[j].pb(i * n + (n - 1 - j) + 1);
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (auto u:a[i]) cout << u << ' ';
		cout << '\n';
	}












	return 0;
}

