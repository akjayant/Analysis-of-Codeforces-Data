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
	int n;
	cin >> n;
	vector<vector<int>> ans(n);
	int it = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				ans[j].push_back(it++);
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				ans[j].push_back(it++);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}