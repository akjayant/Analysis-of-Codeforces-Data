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

int n, k;
string s, t;

string a, b;

int main() {
	cin >> k;
	while (k--)
	{
		cin >> n;
		cin >> s >> t;
		a = "";
		b = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != t[i])
			{
				a += s[i];
				b += t[i];
			}
		}

		if ((a.length() == 0) || ((a.length() == 2) && (a[0]==a[1]) && (b[0]==b[1])))
		{
			cout <<"Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		
	}


	return 0;
}
