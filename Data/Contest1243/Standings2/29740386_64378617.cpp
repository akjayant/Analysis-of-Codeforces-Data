#include<bits/stdc++.h>
using namespace std;
int k,n;
string s1, s2;
int main()
{
	cin >> k;
	while (k--)
	{
		cin >> n;
		cin >> s1 >> s2;
		int c = 0;
		int k1 = -1, k2 = -1;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i])
			{
				c++;
				if (k1 == -1)k1 = i;
				else k2 = i;
			}
		}
		if (c > 2 || c == 1)cout << "No" << endl;
		else if (c == 0)cout << "Yes" << endl;
		else
		{
			if (s1[k1] == s1[k2] && s2[k2] == s2[k1])
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}