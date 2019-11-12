#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	char a = '!', b, c, d;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			cnt++;
			if (a == '!') {
				a = s[i];
				b = t[i];
			} else {
				c = s[i];
				d = t[i];
			}
		}
	}

	//cout << cnt << " ";
	if (cnt == 0) {
		cout << "Yes\n";
		return;
	}
	if (cnt == 2) {

		//cout << a << " " << b << " " << c << " " << d << endl;
		if (a == c && b == d) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	solve();
    }

    return 0;
}