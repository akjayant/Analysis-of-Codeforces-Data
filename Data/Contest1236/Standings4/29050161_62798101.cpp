#include <bits/stdc++.h>
#define MOD (ll)(1e9 + 7)
#define MAX (ll)(1e6 + 4)
#define INF (ll)(1e9 + 1)
using namespace std;
using ll =  long long;
using ld = long double;

vector<int> ar[300];
int main () {
	int n;
	cin >> n;
	int cc = 1;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			for (int j = 0; j < n; j++) {
				ar[j].push_back (cc++);
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				ar[n - 1 - j].push_back (cc++);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for(int x : ar[i]) {
			cout << x << " ";
		}
		cout << "\n";		
	}
}
