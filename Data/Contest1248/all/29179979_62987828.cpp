#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main()
{
	long long n,t,m,ans1=0,ans2=0;
	cin>>t;
	while(t--){
	long long ans=0,ans1=0,ans2=0;	
	memset(a,0,sizeof(0));
	memset(b,0,sizeof(0));
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	cin>>m;
	
	for(int i=1;i<=m;i++)cin>>b[i];
	
	for(int i=1;i<=n;i++)
	   {
	   	if(a[i]%2==0)ans1++;
	   	else ans2++;
	   }
	   for(int i=1;i<=m;i++)
	   {
	   	if(b[i]%2==1)ans+=ans2;
	   	else ans+=ans1;
	   }
	   cout<<ans<<endl;
	
}
	return 0;
}
