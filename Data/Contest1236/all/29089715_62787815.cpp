#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int a,b,c,co=0;
		cin>>a>>b>>c;
		while(1)
		{
			if(b>=1&&c>=2)
				{	
					co++;
					b--;
					c-=2;
					
				}
				else
					break;
		}
		while(1)
		{
			if(a>=1&&b>=2)
			{
				co++;
				a--;
				b-=2;
				
			}
			else
				break;
		}
		cout<<3*co<<"\n";
	}
	return 0;
}