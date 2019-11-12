#include <bits/stdc++.h>
using namespace std;
int n, k;
char t[100000], s[100000];
int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		vector <int> index;
		int cnt = 0;
		scanf("%d", &n);
		scanf("%s", s);
		scanf("%s", t);
		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				cnt++;
				index.push_back(i);
			}
		}
		if (cnt == 2)
		{
			int in1 = index[0], in2 = index[1];
			if (s[in1] == s[in2] && t[in1] == t[in2])
				printf("Yes\n");
			else
				printf("No\n");

		}
		else if (cnt == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}