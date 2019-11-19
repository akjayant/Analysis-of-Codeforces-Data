#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		string s;cin>>s;int len=s.length();
		int fl=1;int ans=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='1')
			{
				ans=max(ans,2*(i+1));
				ans=max(ans,2*(len-i));
			}
		}
		ans=max(ans,len);
		cout<<ans<<endl;
	}
 } 