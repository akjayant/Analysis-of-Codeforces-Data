#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    long long n,pos=0,cnt,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pos+=a[i];
	
	sort(1+a,1+a+n);
	
	cnt=0;
	for(int i=1;i<=n/2;i++)cnt+=a[i];
	ans=cnt*cnt+(pos-cnt)*(pos-cnt);	
	cout<<ans;
	
			
	return 0;
}
