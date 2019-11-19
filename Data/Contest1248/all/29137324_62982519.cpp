#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int main()
{
	int n;
	cin >> n;
	ll a[n];
	ll x = 0, y = 0;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i=0; i<n/2; i++) x += a[i];
	for(int i=n/2; i<n; i++) y += a[i];
	cout << x*x + y*y << endl;
}