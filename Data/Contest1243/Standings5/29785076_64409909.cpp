#include <bits/stdc++.h>
using namespace std;
char s[60], t[60], tmp;
int resi[110], resj[110], cnt[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k, n, flag, ptr, p1;
	cin >> k;
	while (k--) {
		cin >> n >> s >> t;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++; cnt[t[i] - 'a']++;
		}
		flag = 1;
		for (int i = 0; i < 26 && flag; i++)
			if (cnt[i] % 2) flag = 0;
		if (!flag)
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			ptr = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] != t[i]) {
					p1 = 0;
					for (int j = i + 1; j < n; j++)
						if (s[j] == s[i]) {
							p1 = j; break;
						}
					if (p1) {
						resi[ptr] = p1; resj[ptr++] = i;
						tmp = s[p1]; s[p1] = t[i]; t[i] = tmp;
					}
					else {
						p1 = 0;
						for (int j = i + 1; j < n; j++)
							if (t[j] == s[i]) {
								p1 = j; break;
							}
						resi[ptr] = p1; resj[ptr++] = p1;
						tmp = s[p1]; s[p1] = t[p1]; t[p1] = tmp;
						resi[ptr] = p1; resj[ptr++] = i;
						tmp = s[p1]; s[p1] = t[i]; t[i] = tmp;
					}
				}
			}
			cout << ptr << endl;
			for (int i = 0; i < ptr; i++)
				cout << resi[i] + 1 << " " << resj[i] + 1 << endl;
		}
	}
	return 0;
}