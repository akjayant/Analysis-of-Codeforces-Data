#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <map>
#define ll long long
#define mm 1000000007
using namespace std;

char arr[10005];
char brr[10005];
int main()
{

	int k;
	cin >> k;
	while (k--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", arr);
		getchar();
		scanf("%s", brr);
		getchar();
		int cnt = 0;
		vector<int> tem;
		for (int i = 0;i < n;i++)
		{
			if (arr[i] != brr[i])
			{
				tem.push_back(i);
				cnt++;
			}
		}
		if (cnt != 2)
		{
			printf("No\n");
			continue;
		}
		if (arr[tem[0]] == arr[tem[1]] && brr[tem[0]] == brr[tem[1]])
			printf("Yes\n");
		else
			printf("No\n");

	}
}