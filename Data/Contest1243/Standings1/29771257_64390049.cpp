#include <bits/stdc++.h>
using namespace std;
const int M = 100100;
char a[M],b[M];
int n;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		scanf("%s%s",a+1,b+1);
		int num=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
				num++;
		if(num==0)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		if(num!=2)
		{
			cout<<"No"<<endl;
			continue;
		} 
		int val=-1;
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
			{
				if(val==-1)
					val=(int)a[i]*100+b[i];
				if(val!=(int)a[i]*100+b[i])
					flag=0;
			}
		if(!flag)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}