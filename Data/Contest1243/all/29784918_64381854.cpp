#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s, t, s1, t1;
		cin >> s >> t;
		for (int i = 0; i < n; ++i) 
			if (s[i] != t[i]) {
				s1 += s[i];
				t1 += t[i];
			}
		if (s1.size() != 2)
			cout << "No" << endl;
		else {
			if (s1[0] == s1[1] && t1[0] == t1[1])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}