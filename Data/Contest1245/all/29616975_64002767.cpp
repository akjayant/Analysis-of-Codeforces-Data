//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
const long long md=1e9+7;
string s;
long long f[101010],ans=1;
int main()
{
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='w' || s[i]=='m')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	f[0]=1;
	f[1]=1;
	for(int i=2;i<100100;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=md;
	}
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='n' && s[i+1]=='n')
		{
			int now=2;
			i+=2;
			while(s[i]=='n')
			{
				now++;
				i++;
			}
			i--;
			ans*=f[now];
			ans%=md;
		}
		if(s[i]=='u' && s[i+1]=='u')
		{
			int now=2;
			i+=2;
			while(s[i]=='u')
			{
				now++;
				i++;
			}
			i--;
			ans*=f[now];
			ans%=md;
		}
	}
	cout<<ans<<endl;
	return 0;
}