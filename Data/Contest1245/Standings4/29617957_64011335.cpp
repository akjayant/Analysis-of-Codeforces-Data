#include <iostream>
#include <string>

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 7;

long long arr[N] = { 0, 1, 2, 3};

int main() {
	for (int i = 3; i < N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}
	string str;
	cin >> str;
	long long ans = 1;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'm' || str[i] == 'w') {
			ans = 0;
			break;
		}
		if (str[i] == 'u') {
			int cnt = 0;
			while (i < len && str[i] == 'u') {
				i++;
				cnt++;
			}
			if (i < len) {
				i--;
			}
			ans *= arr[cnt];
			ans %= mod;
		}
		else if (str[i] == 'n') {
			int cnt = 0;
			while (i < len && str[i] == 'n') {
				i++;
				cnt++;
			}
			if (i < len) {
				i--;
			}
			ans *= arr[cnt];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
