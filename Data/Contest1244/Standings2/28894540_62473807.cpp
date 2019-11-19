#include <bits/stdc++.h>
using namespace std;
int n;
string x;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		int pos1=0,pos2=0;
		for (int i=0;i<n;i++)
		{
			if(x[i]=='1')
			{
				pos1=i+1;
				break;
			}
		}
		for (int i=n-1;i>=0;i--)
		{
			if (x[i]=='1')
			{
				pos2=i+1;
				break;
			}
		}
		if (pos1==0&&pos2==0)
		{
			printf("%d\n",n);
			continue;
		}
		int tmp1=max(pos1,n-pos1+1);
		int tmp2=max(pos2,n-pos2+1);
		printf("%d\n",max(tmp1,tmp2)*2);
	}

	return 0;
}
