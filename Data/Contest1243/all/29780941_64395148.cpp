#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[1000], t[1000];
int engl[30];
vector <pair <int, int>> output;
//int cnt;
//vector <int> sengindex[30],tengindex[30];
void printyes()
{
	output.clear();
	printf("Yes\n");
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				swap(s[j], t[i]);
				output.push_back({ j,i });
//				printf("//%d %d//\n", j, i);
				break;
			}
			if (s[i] == t[j])
			{
				swap(t[j], s[n - 1]);
				swap(t[i], s[n - 1]);
				output.push_back({ n - 1,j });
				output.push_back({ n - 1,i });
//				printf("tt%d %dtt\n", n - 1, j);
//				printf("tt%d %dtt\n", n - 1, i);
				break;
			}
		}
	}
	int sizz = output.size();
	printf("%d\n", sizz);
	for (int i = 0; i < sizz; i++)
		printf("%d %d\n", output[i].first+1, output[i].second+1);
}
int main()
{
	scanf("%d", &k);
	for (int p = 0; p < k; p++)
	{
//		sengindex[i].clear();
//		tengindex[i].clear();
//		cnt = 0;
		scanf("%d", &n);
		scanf("%s", s);
		scanf("%s", t);
		for (int i = 0; i < 26; i++)
			engl[i] = 0;
		for (int i = 0; i < n; i++)
		{
			engl[s[i] - 'a']++;
//			sengindex[s[i] - 'a'].push_back(i);
			engl[t[i] - 'a']++;
//			tengindex[t[i] - 'a'].push_back(i);
		}
		bool isodd = false;
		for (int i = 0; i < 26; i++)
		{
			if (engl[i] & 1)
				isodd = true;
		}
		if (isodd)
			printf("No\n");
		else
			printyes();
	}
}