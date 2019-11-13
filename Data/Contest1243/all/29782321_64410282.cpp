#include <bits/stdc++.h>

using namespace std;
const int MAXN = 55;
char s[MAXN], t[MAXN];
int k, n, cnt[26], ok;
vector<pair<int, int>> ans;

int main()
{
	for(scanf("%d", &k); k--;)
	{
		scanf("%d %s %s", &n, s, t), ok = true;
		ans.clear();
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n; ++i)
			cnt[s[i] - 'a']++, cnt[t[i] - 'a']++;
		for(int i = 0; i < 26; ++i)
			if(cnt[i] % 2)
				ok = false;
		if(!ok)
		{
			printf("No\n");
			continue;
		}
		for(int i = 0; i < n; ++i)
		{
			if(s[i] == t[i])
				continue;
			int pos = find(s + i + 1, s + n, s[i]) - s;
			if(pos < n)
			{
				ans.emplace_back(pos, i);
				swap(s[pos], t[i]);
			}
			else
			{
				pos = find(t + i + 1, t + n, s[i]) - t;
				ans.emplace_back(i, i);
				swap(s[i], t[i]);
				ans.emplace_back(i, pos);
				swap(s[i], t[pos]);
			}
		}
		if(strcmp(s, t))
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n%d\n", ans.size());
		for(const auto[i, j] : ans)
			printf("%d %d\n", i + 1, j + 1);
	}
}