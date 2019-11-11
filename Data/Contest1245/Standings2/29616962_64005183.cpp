#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int T, n, a, b, c, len, cnt;
string str, ans;
map<char, int> mp;

void Put(int &x, char ch) {
	if(x != 0) {
		--x;
		++cnt;
		ans.push_back(ch);
	} else {
		ans.push_back('*');
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> T;
	while(T--) {
		cnt = 0;
		ans.clear();
		cin >> n >> a >> b >> c;
		cin >> str;
		len = str.length();
		for(int i = 0; i < len; ++i) {
			if(str[i] == 'P') {
				Put(c, 'S');
			} else if(str[i] == 'S') {
				Put(a, 'R');
			} else {
				Put(b, 'P');
			}
		}
		if(cnt < (n + 1) / 2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i < len; ++i) {
			if(ans[i] == '*') {
				if(a != 0) {
					--a;
					ans[i] = 'R';
				} else if(b != 0) {
					--b;
					ans[i] = 'P';
				} else {
					--c;
					ans[i] = 'S';
				}
			}
		}
		cout << ans << endl;
	}

    return 0;
}