#include <bits/stdc++.h>

using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;


int main(){
	fast_io();
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i) cin >> arr[i];
	long long ans = 0;
	sort(arr, arr + n, greater<int>());
	long long x = 0, y = 0;
	for(int i = 0; i < (n + 1)/2; ++i) {
		x += arr[i];
	}
	for(int j = (n+1)/2; j < n; ++j) {
		y += arr[j];
	}
	ans = x*x + y*y ;
	cout << ans << "\n";

}