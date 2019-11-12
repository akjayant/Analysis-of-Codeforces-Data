#include<bits/stdc++.h>

using namespace std;

vector<int> v[301];

main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			v[i].push_back(i*n+j+1);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", j&1 ? v[j][n-i-1] : v[j][i]);
		printf("\n");
	}
	return 0;
}