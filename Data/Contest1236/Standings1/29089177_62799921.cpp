// IN THE NAME OF ALLAH.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back

const int N = 310;
int a[N][N];
vector<int> ans[N];


int32_t main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int t = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = t++;

	for(int i = 0; i < n - n / 2; i++){
		for(int j = 0; j < n; j++){
			ans[(i - j + n) % n].pb(a[i][j]);
		}
	}
	for(int i = 0; i < n / 2; i++)
		for(int j = 0; j < n; j++)
			ans[(i - j + n) % n].pb(a[n - i - 1][n - j - 1]);
	for(int i = 0; i < n; i++){
		for(auto x : ans[i])
			cout << x << ' ';
		cout << '\n';
	}
	return 0;
}