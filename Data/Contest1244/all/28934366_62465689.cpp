#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int t, a, b, c, d, k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>a>>b>>c>>d>>k;
		int cnt1 = (a-1)/c+1, cnt2 = (b-1)/d+1;
		{
			if(cnt1+cnt2 > k) printf("-1\n");
			else printf("%d %d\n",cnt1,k-cnt1);
		}
	}
	return 0;
 } 
