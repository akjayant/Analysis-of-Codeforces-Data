#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);

int tt;

int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> tt;
	while (tt--) {
		int n;
		string s, t;
		cin >> n;
		cin >> s >> t;
		vector <pii> moves;
		int i = 0;
		int cnt = 0;
		int pos1 = -1, pos2 = -1;
		for (i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				cnt++;
				if (cnt == 3) {
					break;
				}
				if (pos1 == -1) {
					pos1 = i;
				}
				else if (pos2 == -1) {
					pos2 = i;
				}
			}
		}
		if (cnt == 3 || cnt == 1) {
			cout << "No" << endl;
		}
		else {
			if (s[pos1] == s[pos2] && t[pos1] == t[pos2]) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}

		//for (i = 0; i < n; i++) {
		//	if (s[i] == t[i])
		//		continue;
		//	else {
		//		int pos = -1;
		//		for (int j = i + 1; j < n; j++) {
		//			if (t[j] == t[i]) {
		//				pos = j;
		//				break;
		//			}
		//		}
		//		if (pos == -1) {
		//			for (int j = i + 1; j < n; j++) {
		//				if (s[j] == t[i]) {
		//					pos = j;
		//					break;
		//				}
		//			}
		//			if (pos == -1) {
		//				break;
		//			}
		//			else {
		//				swap(s[pos], t[pos]);
		//				moves.pb({ pos + 1,pos + 1 });
		//				swap(s[i], t[pos]);
		//				moves.pb({ i + 1,pos + 1 });
		//			}
		//		}
		//		else {
		//			swap(s[i], t[pos]);
		//			moves.pb({ i + 1,pos + 1 });
		//		}
		//	}
		//}
		//if (i == n) {
		//	if ((int)moves.size() == 1) {
		//		cout << "Yes" << endl;
		//	}
		//	else {
		//		cout << "No" << endl;
		//	}
		//	//cout << "Yes" << endl;
		//	/*cout << int)moves.size() << endl;
		//	for (int i = 0; i < (int)moves.size(); i++) {
		//		cout << moves[i].first << " " << moves[i].second << endl;
		//	}*/
		//}
		//else {
		//	cout << "No" << endl;
		//}
	}


	return 0;
}