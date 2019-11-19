#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

int n;
int a[100010];

bool compare(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	scanf("%d", &n);
	
	long long totalLength = 0;
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d", &(a[i]));
		totalLength = totalLength + a[i];
	}
		
	sort(a, a + n, compare);
	
	long long longSite = 0;
	long long shortSite = 0;
	
	int limit = n / 2;
	if (n % 2 == 0)
		limit--;
		
	for (int i = 0 ; i <= limit ; i++)
		longSite = longSite + a[i];
		
	shortSite = totalLength - longSite;
	
	long long ans = longSite * longSite + shortSite * shortSite;
	printf("%I64d\n", ans);

		
	
	return 0;
}
