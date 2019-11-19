#include <bits/stdc++.h>
#define MAX (ll)(2e5+5)
#define MOD (ll)(1e9 + 7)
#define INF (ll)(1e17 + 5)
#define PI (double)(3.14159265)

using namespace std;
using ll = long long;

int main () {
	int n;
	cin >> n;
	int ar[n];
	ll su = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		su += ar[i];
	}
	sort (ar, ar + n, greater<int> ());
	ll ss = 0;	
	n++;
	for (int i = 0; i < n / 2; i++) {
		ss += ar[i];
	}
	cout << (ss * ss) + (su - ss) * (su - ss) << "\n";
}
