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
		int countSym[26] = {0};
		vector<pair<int, int>> ops;
		for(unsigned i = 0; i < n; i++)
		{
			if(s[i] != t[i])
			{
				countSym[s[i] - 'a']++;
				countSym[t[i] - 'a']++;
			}
		}
		bool yes = true;
		for(unsigned i = 0; i < 26; i++)
		{
			if(countSym[i] % 2 != 0)
				yes = false;
		}
		if(yes)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		if(yes)
		{
			for(unsigned i = 0; i < n; i++)
			{
				if(s[i] != t[i])
				{
					bool correct = false;
					for(unsigned k = i + 1; k < n; k++)
					{
						if(s[k] == s[i])
						{
							ops.push_back(make_pair(k, i));
							swap(s[k], t[i]);
							correct = true;
							break;
						}
					}
					if(!correct)
					{
						for(unsigned k = i + 1; k < n; k++)
						{
							if(s[i] == t[k])
							{
								ops.push_back(make_pair(k, k));
								swap(s[k], t[k]);
								ops.push_back(make_pair(k, i));
								swap(s[k], t[i]);
								break;
							}
						}
					}
				}
			}
			cout << ops.size() << endl;
			for(auto op : ops)
			{
				cout << op.first + 1 << " " << op.second + 1 << endl;
			}
		}

	}
	return 0;
}