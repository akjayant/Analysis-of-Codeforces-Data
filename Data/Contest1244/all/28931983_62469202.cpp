#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
char c;
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = N;
		for (int i = 1; i <= N; i++) {
			cin >> c;
			if (c == '1') {
				ans = max(ans, 2 * i);
				ans = max(ans, 2 * (N - i + 1));
			}
		}
		cout << ans<<'\n';
	}
}