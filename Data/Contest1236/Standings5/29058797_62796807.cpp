#include<bits/stdc++.h>
using namespace std;
int n, cnt, a[305][305];
int main() {
	//freopen(".inp", "r", stdin);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		if(i % 2) for(int j = 1; j <= n; j ++) a[j][i] = ++cnt;
		else for(int j = n; j >= 1; j --) a[j][i] = ++cnt;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) cout << a[i][j] << ' ';
		cout << '\n'; 
	}
}