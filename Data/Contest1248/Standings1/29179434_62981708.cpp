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

int main()
{
	int n = 0;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i<n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	long long dx = 0, dy = 0;
	for(int i = 0; i<n/2; i++)
		dx += a[i];
	for(int i = n/2; i<n;  i++)
		dy += a[i];
	cout << dx*dx+dy*dy;

	return 0;
}