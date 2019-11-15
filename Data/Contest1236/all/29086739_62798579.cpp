#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const long long MOD=1000000007;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, j, k, m, n, c=1, x, y, z;
	cin>>n;
	//vector<vector<int>> v(n, vector<int>(n));
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			cout<<1+j*n+((j%2==0)?i:n-1-i)<<' ';
			//cout<<v[i][j];
			//c++;
		}
		cout<<'\n';
	}

	
	return 0;
}