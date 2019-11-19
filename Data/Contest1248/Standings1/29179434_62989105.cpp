#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <memory.h>
#include <memory>

using namespace std;

#define MODP 1000000007

vector<int> cache;

long long rp(int n)
{
	if(n <= 1) return 1;
	if(n == 2) return 2;

	if(!cache[n])
		cache[n] = (rp(n/2)*rp((n+1)/2) + rp((n-2)/2)*rp((n-1)/2))%MODP;

	return cache[n];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cache.resize(100001);

	cout << (2*(rp(n)+rp(m) - 1))%MODP;

	return 0;
}