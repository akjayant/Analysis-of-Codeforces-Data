#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

const int N = 1e5 + 5,mo = 1e9 + 7;

int n,cnt;
ll ans;
ll f[N];
char s[N];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	int flag = 0;
	f[1] = 1,f[2] = 2;
	ans = 1;
	for (int i = 3 ; i < N ; i++) f[i] = (f[i - 1] + f[i - 2]) % mo;
	for (int i = 1 ; i <= n ; i++) if (s[i] == 'm' || s[i] == 'w') { flag = 1; break; }
	if (flag) { printf("0\n"); return 0; }
	for (int i = 1 ; i <= n ; i++)
	{
		if (s[i] == 'n' || s[i] == 'u')
		{
			cnt = 1;
			while (s[i + 1] == s[i]) cnt++,i++;
			ans = ans * f[cnt] % mo;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
