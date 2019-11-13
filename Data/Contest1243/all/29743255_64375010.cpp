#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int cnt[maxn];

int main(void) {
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		for (int i = maxn - 1; i > 0; i--) {
			cnt[i - 1] += cnt[i];
		}
		for (int i = maxn - 1; i >= 0; i--) {
			if (cnt[i] >= i) {
				cout << i << endl;
				break;
			}
		}

	}

	return 0;
}