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
		int cnt = 0;
		vector <int> cnt1(100);
		vector <int> cnt2(100);
		int ind1, ind2;
		ind1 = ind2 = -1;
		for (int i = 0; i < n; i++)
		{
			if (str1[i] != str2[i])
			{
				if (ind1>=0)
				{
					ind2 = i;
				}
				else
				{
					ind1 = i;
				}
				cnt++;
			}
			cnt1[str1[i] - '0']++;
			cnt2[str2[i] - '0']++;
		}
		if (cnt > 2||cnt==1)
		{
			cout << "NO\n";
		}
		else
		{
			if (cnt == 0)
			{
				cout << "NO\n";
			}
			else
			{
				if (str1[ind1] == str1[ind2] && str2[ind1] == str2[ind2])
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}

	}
	return 0;
}