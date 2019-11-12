#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

void doSwap (string &s, string &t, int inS, int inT) {
	char c = s[inS];
	s[inS] = t[inT];
	t[inT] = c;
}

int main (void) {
	int tests; cin >> tests;
	while (tests--) {
		int n; cin >> n;
		string s, t;
		cin >> s >> t;

		vector <int> countChar(26, 0);
		for (int i = 0; i < n; ++i) {
			countChar[s[i]-'a']++;
			countChar[t[i]-'a']++;
		}

		bool flag = true;

		for (int i = 0; i < 26; ++i)
			if (countChar[i] % 2 == 1)
				flag = false;

		if (!flag) {
			cout << "No\n";
			continue ;
		}

		int curPos = 0;
		vector <ii> swaps;
		while (true) {
			bool same = true;
			for (int i = 0; i < n; ++i)
				if (s[i] != t[i])
					same = false;

			if (same)
				break ;

			if (s[curPos] == t[curPos]) {
				++curPos;
				continue ;
			}

			int inS = 0, inT = 0;
			for (int i = curPos + 1; i < n; ++i) {
				if (s[i] == s[curPos])
					inS = i;
				if (t[i] == s[curPos])
					inT = i;
			}

			if (inS) {
				doSwap(s, t, inS, curPos);
				swaps.push_back(make_pair(inS, curPos));
			} else {
				doSwap(s, t, curPos+1, inT);
				swaps.push_back(make_pair(curPos+1, inT));

				doSwap(s, t, curPos+1, curPos);
				swaps.push_back(make_pair(curPos+1, curPos));
			}

			++curPos;
		}

		cout << "Yes\n";
		cout << swaps.size() << "\n";
		for (int i = 0; i < swaps.size(); ++i)
			cout << swaps[i].first+1 << " " << swaps[i].second+1 << "\n";
	}
}