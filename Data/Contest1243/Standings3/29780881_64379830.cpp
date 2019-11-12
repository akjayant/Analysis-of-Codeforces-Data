// B
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector<int> p;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i]) p.push_back(i);
		bool ans = false;
		if (p.size() == 0) {
			ans = true;
		} else if (p.size() == 2) {
			if (s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]])
				ans = true;
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
