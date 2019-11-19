#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,k;
int main() {
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>c>>d>>a>>b>>k;
		if (d%b==0)
			d/=b;
		else d=d/b+1;
		if (c%a==0)
			c/=a;
		else c=c/a+1;
		if (c+d>k) puts("-1");
		else printf("%d %d\n",c,d);
	}
	
}
