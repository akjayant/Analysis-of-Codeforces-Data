#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define MOD 1000000009

#define MED 1250



int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());


	int smaller = n / 2;
	long long a = 0, b = 0;
	for (int i = 0; i < smaller; i++)
		a += arr[i];

	for (int i = smaller; i < n; i++)
		b += arr[i];

	cout << a * a + b * b;
	


	return 0;
}