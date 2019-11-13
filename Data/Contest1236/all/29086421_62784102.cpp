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
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int k1 = min(b, c / 2);
		cout << (k1 + min(a, (b - k1) / 2)) * 3 << endl;
	}
	return  0;
}