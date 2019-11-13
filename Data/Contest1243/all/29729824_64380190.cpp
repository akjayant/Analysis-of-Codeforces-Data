#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100010
using namespace std;
int k,n,a[MAX_N],b[MAX_N];
char s[MAX_N],t[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>k;
	while(k--)
	{
		int cnt=0;
		cin>>n>>s+1>>t+1;
		for(int i=1;i<=n;++i)
			if(s[i]!=t[i])a[++cnt]=s[i]-'a',b[cnt]=t[i]-'a';
		if(cnt==0||(cnt==2&&(a[1]==a[2]&&b[2]==b[1])))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
