#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
char a[M],b[M];
int n;
struct node
{
	int l,r;
}ans[M];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		scanf("%s%s",a+1,b+1);
		int num=0,lenans=0;
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
			{
				for(int j=i+1;j<=n;j++)
					if(a[i]==a[j])
					{
						ans[++lenans].l=j;
						ans[lenans].r=i;
						swap(b[i],a[j]);
						break;
					}
				if(a[i]!=b[i])
				{
					for(int j=i+1;j<=n;j++)
						if(a[i]==b[j])
						{
							ans[++lenans].l=j;
							ans[lenans].r=j;
							swap(a[j],b[j]);
							ans[++lenans].l=j;
							ans[lenans].r=i;
							swap(a[j],b[i]);
							break;
						}
				}
				if(a[i]!=b[i])
					flag=0;
			}
		if(!flag)
			printf("No\n");
		else
		{
			printf("Yes\n");
			cout<<lenans<<endl;
			for(int i=1;i<=lenans;i++)
				cout<<ans[i].l<<" "<<ans[i].r<<endl; 
		}
	}
	return 0;
}