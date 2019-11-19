#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n, a[100005];
long long ans, x, y;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n/2; i++) x += a[i];
	for(int i = n/2+1; i <= n; i++) y += a[i];
	cout << (x*x + y*y) << endl;
	return 0;
}