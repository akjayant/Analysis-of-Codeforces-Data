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

long long  primediv(long long t)
{
	for (long long  i = 2; i <= sqrt(t) + 1; i++)
		if (t % i == 0)
			return i;
	return t;
}

long long n;

int  main() {
	cin >> n;

	long long divisor = primediv(n);

	if (divisor == n)
	{
		cout << n << endl;
		return 0;
	}

	while (n % divisor == 0)
		n /= divisor;
	if (n == 1)
	{
		cout << divisor << endl;
	}
	else
	{
		cout << 1 << endl;
	}


	return 0;
}
