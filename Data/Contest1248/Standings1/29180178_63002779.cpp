# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int xn = 1e5+10;
int a[xn];
 
int main(){
	for (int i=0;i<200;++i)
	;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	ll x = 0, y = 0;
	for (int i=0; i<n/2; i++) x += a[i];
	for (int i=0; i<n; i++) y += a[i];
	y -= x;
	cout << x*x+y*y;
}


