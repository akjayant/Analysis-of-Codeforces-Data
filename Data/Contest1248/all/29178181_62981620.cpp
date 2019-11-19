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

int t;
int n;
int p[100010];
long long oddP, evenP;

int m;
int q[100010];
long long oddQ, evenQ;

int main()
{
	scanf("%d", &t);
	
	for (int ii = 0 ; ii < t ; ii++)
	{
		oddP = 0;
		evenP = 0;
		scanf("%d", &n);
		for (int i = 0 ; i < n ; i++)
		{
			scanf("%d", &(p[i]));
			
			if (p[i] % 2 == 0)			
				evenP++;
			else
				oddP++;
		}
			
		scanf("%d", &m);
		evenQ = 0;
		oddQ = 0;
		for (int i = 0 ; i < m ; i++)
		{
			scanf("%d", &(q[i]));
			
			if (q[i] % 2 == 0)
				evenQ++;
			else
				oddQ++;
		}
		
		long long total = evenP * evenQ + oddP * oddQ;
		
		printf("%I64d\n", total);
	}
	
	return 0;
}
