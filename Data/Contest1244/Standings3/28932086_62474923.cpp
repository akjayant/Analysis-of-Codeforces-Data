#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		string a;
		cin>>n>>a;
		int maxx=n,nla=0;
		for(int i=n-1;i>=0;i--)
			if(a[i]=='1')
			{
				maxx=max(maxx,(i+1)*2);
				break;
			}
		for(int i=0;i<n;i++)
			if(a[i]=='1')
			{
				maxx=max((n-i)*2,maxx);
				break;
			}
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='1')
				k++;
		}
		maxx=max(maxx,n+k);
		cout<<maxx<<endl;
	}
	return 0;
}