#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ll k, a[n];
	cin >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	for (int i = 0, j = n - 1, f = 1; i != j; i++, j--, f++){
		ll t = (a[i + 1] - a[i]) * f;
		if (t <= k)
			k -= t;
		else{
			cout << a[j] - a[i] - k / f;
			return 0;
		}
		if (i + 1 == j)
			break;
		t = (a[j] - a[j - 1]) * f;
		if (t <= k)
			k -= t;
		else{
			cout << a[j] - a[i + 1] - k / f;
			return 0;
		}
	}
	cout << 0;
	return 0;
} 
