#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int answ=0; int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			char c; cin>>c;
			if(c=='1') answ=max(max(i,n-i+1),answ);
		}printf("%d\n",max(answ*2,n));
	}
	return 0;
}