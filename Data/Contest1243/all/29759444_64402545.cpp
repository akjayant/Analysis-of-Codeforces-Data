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
	int p[28];
	while (k--)
	{
		int n;
		for (int i = 0;i < 28;i++)
			p[i] = 0;
		scanf("%d", &n);
		scanf("%s", arr);
		getchar();
		scanf("%s", brr);
		getchar();
		int cnt = 0;
		for (int i = 0;i < n;i++)
		{
			p[arr[i] - 'a']++;
			p[brr[i] - 'a']++;
		}
		int chk = 0;
		for(int i=0;i<26;i++)
			if (p[i] % 2 != 0)
			{
				chk = 1;
				break;
			}
		if (chk == 1)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		vector<pair<int, int>> tem;
		for (int i = 0;i < n;i++)
		{
			if (arr[i] != brr[i])
			{
				int c = 0;
				for (int j = i + 1;j < n;j++)
				{
					if (arr[j] == arr[i])
					{
						c = j;
						arr[j] = brr[i];
						brr[i] = arr[i];
						
						break;
					}
				}
				if(c!=0)
					tem.push_back(make_pair( c + 1,i + 1 ));
				else
				{
					for (int j = i + 1;j < n;j++)
					{
						if (brr[j] == arr[i])
						{
							tem.push_back(make_pair( j + 1,j + 1 ));
							tem.push_back(make_pair( j + 1,i + 1 ));
							brr[j] = arr[j];
							arr[j] = brr[i];
							brr[i] = arr[i];
							break;
						}
					}
				}
			}
		}
		int sizi = tem.size();
		printf("%d\n", sizi);
		for (int i = 0;i < sizi;i++)
		{
			printf("%d %d\n", tem[i].first, tem[i].second);
		}
	}
}