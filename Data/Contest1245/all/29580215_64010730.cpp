#include <bits/stdc++.h>
using namespace std;
#define inta long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back

inta mo=1e9+7;

int main()
{
	ios_base::sync_with_stdio(0);
	inta fib[100005];
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<100005;i++) fib[i]=fib[i-1]+fib[i-2],fib[i]%=mo;
	string s;
	cin>>s;
	char d='-';
	int n=s.size();
	inta co=1;
	int bo=0;
	inta ans=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='w'||s[i]=='m') bo=1;
		if(s[i]=='u'||s[i]=='n')
		{
			co=1;
			for(int j=i+1;j<n;j++)
			{
				if(s[j]==s[j-1]) co++;
				else break;
			}
			i+=co;
			i--;
			ans*=fib[co];
			ans%=mo;
		}
	}
	if(bo==1) ans=0;
	cout<<ans<<endl;
}