#include <bits/stdc++.h>

using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;


int main(){
	fast_io();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int arr[n];
		for(int i = 0; i < n; ++i) cin >> arr[i];
		int odd = 0, even = 0;
		int m ;
		cin >> m;
		for(int i = 0; i < m; ++i) {
			int num; cin >> num;
			if(num%2) {
				odd += 1;
			} else {
				even += 1;
			}
		}
		long long cnt = 0;
		for(int i = 0 ; i < n; ++i) {
			if(arr[i]%2) {
				cnt += odd;
			} else {
				cnt += even;
			}
		}
		cout << cnt << "\n";
	}
}