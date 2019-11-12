#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map> 
#include<set> 
#include<cmath> 
#include<queue> 


using namespace std;

#define int long long

signed main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int j = 0; j <= b; j++) {
			int cnt = min(j / 2, a);
			int bb = b - cnt * 2;
			cnt += min(bb, c / 2);
			ans = max(ans, cnt);
		}
		cout << ans * 3 << "\n";
	}
}