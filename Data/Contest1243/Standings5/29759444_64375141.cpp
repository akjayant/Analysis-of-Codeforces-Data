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

int arr[1005];
int main()
{

	int k;
	cin >> k;
	while (k--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0;i < n;i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		int maxi = 0;
		for (int i = n - 1;i >= 0;i--)
		{
			int t = min(n - i, arr[i]);
			if (t > maxi)
				maxi = t;
		}
		printf("%d\n", maxi);
	}
}