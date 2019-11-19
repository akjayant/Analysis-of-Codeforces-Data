#include<bits/stdc++.h>
#define int long long
int t, n, m;
int p[100001], q[100001];
int sum;
int x, y;
signed main() 
{
  scanf("%lld", &t);//ac
  while (t--) 
  {
    sum = 0;
    x = y = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) 
	{
      scanf("%lld", &p[i]);
      if (p[i] & 1)
        x++;
      else
        y++;
    }
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++) 
	{
      	scanf("%lld", &q[i]);
      	if (q[i] & 1)
      	  sum += x;
      	else
      	  sum += y;
    }
    printf("%lld\n", sum);
  }
  return 0;
}