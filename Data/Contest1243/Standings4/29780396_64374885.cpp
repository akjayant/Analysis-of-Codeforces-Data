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

int n, tmp, t;
int a[1005];


int main() {
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 1005; i++)
			a[i] = 0;
		
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			for (int j = 1; j <= tmp; j++)
			{
				a[j]++;
			}
		}

		int ans = 0;
		for (int i = 1; i <= 1001; i++)
		{
			if (a[i] >= i)
				ans = i;
		}
		cout << ans << endl;
	}


	return 0;
}
