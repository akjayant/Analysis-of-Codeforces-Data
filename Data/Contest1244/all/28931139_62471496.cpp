#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
char s[1100];
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		int i=0;
		while(i<n&&s[i]!='1')i++;
		int ans=(n-i)*2;
		i=n-1;
		while(i>=0&&s[i]!='1')i--;
		ans=max(ans,(i+1)*2);
		ans=max(ans,n);
		printf("%d\n",ans);
	}
	return 0;
	return 0;
}