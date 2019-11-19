#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=a/c;
		if(a%c)x++;
		int y=b/d;
		if(b%d) y++;
		if(x+y<=k)
			cout<<x<<" "<<y<<endl;
		else puts("-1");
	}
}
