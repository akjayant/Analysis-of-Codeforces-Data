#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, j, k, m, n, c=0, x, y, z;
	cin>>n;

	for (i=0; i<n; i++) {
		cin>>x>>y>>z;
		c=min(z/2, y);
		y-=c;
		cout<<c*3+min(x, y/2)*3<<'\n';
	}
	
	return 0;
}