#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		ans=min(c/2,b);
		int tot=ans*2+ans;
		b-=ans;
		ans=min(b/2,a);
		tot+=2*ans+ans;
		cout<<tot<<'\n';
	}
 } 