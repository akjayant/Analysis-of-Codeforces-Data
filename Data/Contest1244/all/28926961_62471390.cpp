#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int fi=-1,se;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			if(s[i]=='1')
			{
				fi=(fi==-1?i:fi);
				se=i;
			}
		}
		int x=n-min(n-se,fi-1);
		cout<<(fi==-1?n:2*x)<<endl;
	}
}