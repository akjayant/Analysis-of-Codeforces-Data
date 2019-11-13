#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long
int l,r,t;
LL ans=1,fib[100010];
char a[100010];
int main()
{
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<=100000;i++)
      fib[i]=(fib[i-1]+fib[i-2])%MOD;
	scanf("%s",a+1);
	int n = strlen(a+1);
	for (int i=1;i<=n;i++)
	  if(a[i]=='w' || a[i]=='m') return 0*printf("0\n");
	for(int i=1; i<=n; i++)
	{
		if(a[i] != 'u' && a[i] != 'n') continue;
		int j;
		t = 1;
		for(j=i+1; j<=n; j++)
		{
			if(a[j] != a[i]) break;
			t++;
		}
		i = j-1;
		if(t == 1) continue;
		ans = (ans*fib[t])%MOD;
	}
    cout<<ans<<endl;
	return 0;
} 