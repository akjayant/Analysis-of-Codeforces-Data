#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;



int main()
{
	int k;
	cin >> k;
	for(unsigned j = 0; j < k; j++)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		int count = 0;
		vector<char> sRepl, tRepl;
		for(unsigned i = 0; i < n; i++)
		{
			if(s[i] != t[i])
			{
				count++;
				sRepl.push_back(s[i]);
				tRepl.push_back(t[i]);
			}
		}
		if(count != 0 && count != 2)
		{
			cout << "No" << endl;
		}
		else if(count == 0)
		{
			cout << "Yes" << endl;
		}
		else if(sRepl[0] == sRepl[1] && tRepl[1] == tRepl[0])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}