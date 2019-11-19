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
char a[100010];
int level[100010];
int l, r;

int calcCurCycle(const char *a, int szA)
{
	int minLevel = 0;
	int minLevelCount = 0;
	int curLevel = 0;
	for (int i = 0 ; i < szA ; i++)
	{
		if (a[i] == '(')
			curLevel++;
		else
			curLevel--;
			
		level[i] = curLevel;
			
		if (minLevel > curLevel) {
			minLevel = curLevel;
			minLevelCount = 1;
		}
		else if (minLevel == curLevel) {
			minLevelCount++;
		}
	}
	
	return minLevelCount;
}

int main()
{
	scanf("%d\n", &n);
	scanf("%s", a);

	//左右不相等就直接干死
	int level = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (a[i] == '(')
			level++;
		else if (a[i] == ')')
			level--;
	}

	//左右不相等就直接干死
	if (level != 0)
	{
		printf("0\n");
		printf("1 1\n");
		return 0;
	}
	
	int maxL = 1, maxR = 1;
	int maxCycle = 0;
	
	maxCycle = calcCurCycle(a, n);
	
	for (int l = 0 ; l < n ; l++)
		for (int r = l + 1 ; r < n ; r++)
		{
			char tmp;
			tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
			
			int curCycle = calcCurCycle(a, n);
			if (maxCycle < curCycle)
			{
				maxCycle = curCycle;
				maxL = l;
				maxR = r;
			}
			
			tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;			
		}
		
	printf("%d\n", maxCycle);
	printf("%d %d\n", maxL + 1, maxR + 1);
	
	return 0;
}
