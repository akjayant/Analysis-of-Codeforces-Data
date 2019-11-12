#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int a[305][305];
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n, c = 1;	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i&1)
				a[i][j] = c++;
			else
				a[i][n-j+1] = c++;
		}
	}	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout << a[j][i] << " ";
		cout << endl;
	}
	return 0;
}