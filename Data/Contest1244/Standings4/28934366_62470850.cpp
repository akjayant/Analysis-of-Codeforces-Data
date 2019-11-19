#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXN 100100
int t, len, a[MAXN], cnt1, fir, lst, n;
char s[1100];
int main()
{
	cin>>t;
	while(t--)
	{
		cnt1 = fir = lst =  0;
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i] == '1') cnt1++;
			if(s[i] == '1' && fir == 0) fir = i;
		}
		for(int i=n;i>=1;i--) 
		{
			if(s[i] == '1' && lst == 0) lst = i;
		}
		if(cnt1 == 0) printf("%d\n",n);
		else printf("%d\n",2*n - 2*(min(fir-1, n-lst)));
	}
	
	
	return 0;
} 
