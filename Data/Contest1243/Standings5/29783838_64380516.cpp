#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 10000;
int T,n;
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> n;
		cin >> s;
		cin >> t;
		int id1 = -1, id2 = -1;

		for (int i = 0;i<s.length();++i)
			if (s[i] != t[i])
			{
				if (id1 == -1) id1 = i;
				else
					id2 = i;
			}

		bool flag = 0;

		if (id1 != -1 && id2 != -1)
		{
			swap(s[id1], t[id2]);
			if (s == t)
				flag = 1;
			else
			{
				swap(s[id1], t[id2]);
				swap(s[id2], t[id1]);
				if (s == t)
					flag = 1;
			}
		}

		if (flag) cout << "Yes\n"; else cout << "No\n";
	}
	return 0;
}