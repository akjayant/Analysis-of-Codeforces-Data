#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;


#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)

const ll mod = 1000000000 + 7;

int main() {
	//ifstream cin("input.txt");
	int k;
	cin >> k;
	while (k--)
	{
		int n;
		cin >> n;
		string str1, str2;
		cin >> str1 >> str2;
		vector <pair<int, int>> ans;
		for (int i = 0; i < n; i++)
		{
			if (str1[i] != str2[i])
			{
				for (int j = i + 1; j < n; j++)
				{
					if (str1[j] == str2[i])
					{
						swap(str1[j],str2[j]);
						ans.pb(mp(j + 1, j + 1));
						swap(str1[i], str2[j]);
						ans.pb(mp(i + 1, j + 1));
						break;
					}
					if (str2[j] == str2[i])
					{
						swap(str1[i], str2[j]);
						ans.pb(mp(i + 1, j + 1));
						break;
					}

				}
			}
		}

		if (str1 == str2)
		{
			cout << "YES\n" << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i].first << " " << ans[i].second << '\n';
			}
		}
		else
		{
			cout << "NO\n";
		}


	}
	return 0;
}