#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n][n];
	int k = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i & 1) {
				a[n - j - 1][i] = k;
			} else {
				a[j][i] = k;
			}
			++k;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return  0;
}