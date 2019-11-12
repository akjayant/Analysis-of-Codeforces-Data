#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c,ans=0;
		cin>>a>>b>>c;
		while(b>0 && (c>1))
		{
			b--;
			ans+=3;
			c=c-2;
		}
		while(a>0 && (b>1))
		{
			a--;
			b=b-2;
			ans+=3;
		}
		cout<<ans<<endl;
	}
}