#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 3;
string s;
const int BASE = 1000000000 + 7;
int f[MAXN];

int main() {
	cin >> s;
	s = '1' + s;
	f[0] = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			f[i] = 0;
			break;
		}
		f[i] = f[i - 1];
		if (i > 1)
		{
			if ((s[i - 1] == 'n' && s[i] == 'n') || (s[i - 1] == 'u' && s[i] == 'u'))
				f[i] = (f[i] + f[i - 2]) % BASE;
		}
	}
	cout << f[s.size()-1];
	return 0;
}