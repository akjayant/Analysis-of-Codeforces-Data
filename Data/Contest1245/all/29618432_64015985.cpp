#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 3;
int a[4];
int n;
int f[MAXN][MAXN][MAXN];
string s;


int main() {
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= 3; ++i) cin >> a[i];
		cin >> s;
		string t = s;
		int Ans = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			t[i] = '0';
			if (s[i] == 'R' && a[2]>0)
			{
				t[i] = 'P';
				a[2]--;
				Ans++;
			}
			if (s[i] == 'P' && a[3]>0)
				{
					t[i] = 'S';
					a[3]--;
					Ans++;
				}
				
			if (s[i] == 'S' && a[1]>0)
				{
						t[i] = 'R';
						a[1]--;
						Ans++;
				}
		}

		for (int i = 0; i < t.size(); ++i)
		{
			if (t[i] == '0')
			{
				if (a[1] > 0)
				{
					a[1]--;
					t[i] = 'R';
				}
				else if (a[2] > 0)
				{
					a[2]--;
					t[i] = 'P';
				}
				else 
					if (a[3] > 0)
					{
						a[3]--;
						t[i] = 'S';
					}
			}
		}

		if (Ans >= (n + 1) / 2)
		{
			cout << "YES\n";
			cout << t << "\n";
		}
		else
		{
			cout << "NO\n";
		}

	}
	return 0;
}