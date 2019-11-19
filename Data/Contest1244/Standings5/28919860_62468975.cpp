#include <iostream>
#include <fstream>
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
#include <stack>


using namespace std;
using ll = long long;


#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)


int main() {
	//ifstream cin("input.txt");
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		int dif = 0;
		bool check = true;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				int dist = max(abs(n - i), i + 1);
				dif = max(dist, dif);
				check = false;
			}
		}
		if (check)
		{
			cout << n << '\n';
		}
		else
		{
			cout << dif * 2<<'\n';
		}
	}

	return 0;
}