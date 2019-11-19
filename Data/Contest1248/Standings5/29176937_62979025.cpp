#include<bits/stdc++.h>
using namespace std;
long long n,t,m; 
long long a[1000001],b[1000001],s1,s2,s3,s4;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		s1=0;
		s2=0;
		s3=0;
		s4=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
			s1++;
			else
			s2++;
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
			if(b[i]%2==0)
			s3++;
			else
			s4++;
		}
		
		cout<<s1*s3+s2*s4<<endl;
	}
}
