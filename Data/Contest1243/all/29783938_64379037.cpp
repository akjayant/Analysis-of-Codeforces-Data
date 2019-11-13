#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int k;
	cin >> k;
	for (; k > 0; k--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int counter = 0;
		char cs1, cs2;
		char ct1, ct2;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				counter++;
				if (counter == 1)
				{
					cs1 = s[i];
					ct1 = t[i];
				}
				if (counter == 2)
				{
					cs2 = s[i];
					ct2 = t[i];
				}
			}
		}
		if (counter != 2)
		{
			cout << "No\n";
		}
		else
		{
			if (cs1 == cs2&&ct1 == ct2)
			{
				cout << "Yes\n";
			}
			else
			{
				cout << "No\n";
			}
		}
	}
}