#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int a[500050];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		int ans=z/2;
		ans=min(ans,y);
		y-=ans;
		
		int t=y/2;
		t=min(t,x);
		
		
		ans+=t;
		cout<<ans*3<<endl;
	}
	return 0;
}