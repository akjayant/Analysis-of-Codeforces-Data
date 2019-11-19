#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+7;
char s[N];
vector<int> vec;
int sum[N], pre[N];
pair<int, int> q[N<<1];
int main()
{
	int n, m, ans = 0, fl = 1, fr = 1;
	scanf("%d%s", &n, s+1);
	for(int i = 1; i <= n; i++)
	{
		s[i+n] = s[i];
	}
	m = n*2;
	for(int l = 1; l <= n; l++)
	{
		for(int r = (l==1) ? 1 : l+1; r <= n; r++)
		{
			vec.clear();
			swap(s[l], s[r]);
			swap(s[l+n], s[r+n]);
			memset(pre, -1, sizeof(pre));
			for(int i = 1; i <= m; i++)
			{
				sum[i] = sum[i-1];
				if(s[i]=='(')
				{
					sum[i]++;
					vec.push_back(i);
				}
				else
				{
					sum[i]--;
					if(vec.size())
					{
						int nxt = vec.back();
						vec.pop_back();
						pre[nxt] = i;
						pre[i] = nxt;
					}
				}
			}
			int cnt = 0, pl = 1, pr = 0;
			for(int i = 1; i < n; i++)
			{
				while(pl<=pr&&pre[i]<q[pr].first)
				{
					pr--;
				}
				q[++pr] = make_pair(pre[i], i);
			}
			for(int i = 1; i <= n; i++)
			{
				while(pl<=pr&&q[pl].second+n-1<i+n-1)
				{
					pl++;
				}
				while(pl<=pr&&pre[i+n-1]<q[pr].first)
				{
					pr--;
				}
				q[++pr] = make_pair(pre[i+n-1], i+n-1);
				if(q[pl].first>=i&&sum[i+n-1]-sum[i-1]==0)
				{
					cnt++;
				}
			}
			if(cnt>ans)
			{
				ans = cnt;
				fl = l, fr = r;
			}
			swap(s[l], s[r]);
			swap(s[l+n], s[r+n]);
		}
	}
    printf("%d\n%d %d\n", ans, fl, fr);
	return 0;
}
