#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstdio>
#include <iterator>
#include <cmath>
#include <cassert>
#include <unordered_map>


using namespace std;


int k,n;
string s, t;
int a[28];

vector<pair<int, int>> path;

int  main() {
	cin >> k;
	while (k--)
	{
		path.clear();
		for (int i = 0; i < 28; i++)
			a[i] = 0;

		cin >> n;
		cin >> s >> t;

		for (int i = 0; i < n; i++)
		{
			a[s[i] - 'a']++;
			a[t[i] - 'a']++;
		}

		for (int i = 0; i < 28; i++)
			if (a[i] % 2 != 0)
			{
				cout << "No" << endl;
				goto prts;
			}
		cout << "Yes" << endl;

		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				int loc = -1;
				for (int j = i + 1; j < n; j++)
					if (s[j] == s[i])
						loc = j;
				if (loc != -1)
				{
					swap(s[loc], t[i]);
					path.push_back(make_pair(loc+1,i+1));
				}
				else
				{
					for (int j = i + 1; j < n; j++)
						if (t[j] == s[i])
							loc = j;
					swap(s[loc], t[loc]);
					path.push_back(make_pair(loc+1, loc+1));

					swap(s[loc], t[i]);
					path.push_back(make_pair(loc+1, i+1));

				}
			}
		}
		cout << path.size() << endl;

		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i].first << " " << path[i].second << endl;
		}



	prts: continue;
	}


	return 0;
}
