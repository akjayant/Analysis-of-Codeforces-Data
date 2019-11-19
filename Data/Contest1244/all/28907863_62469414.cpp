#include <vector>
#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t-- > 0) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mx = n;
		for(int i = 0; i < n; ++i) {
			if(s[i] == '1'){
				mx = max(n + 1, mx);
				mx = max((i + 1) * 2, mx);
				mx = max((n - i) * 2, mx);
			}
		}
		cout << mx << "\n";
	}
}