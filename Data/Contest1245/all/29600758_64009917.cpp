#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
typedef pair<int,int> pii;
const ll mod=1e9+7;
set<int> se;
vector<int> vec;
queue<int> q;
ll f[maxn];
void init()
{
	f[1]=1;f[0]=1;
	for(int i=2;i<=1e5+1;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=mod;
	}
}
int main()
{
	string s;cin>>s;init();
	int len=s.length();int ok=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			ok=0;break;
		}
	}
	if(ok==0)
	{
		cout<<0<<endl;
		return 0;
	}
	int id=0;int lst=0;ll ans=1;
	while(id<len)
	{
		if(s[id]!='u') 
		{
			id++;lst=id;continue;
		}
		while(id<len&&s[id]=='u') id++;
		id--;
		//cout<<id<<endl;
		ans*=f[id+1-lst];
		ans%=mod;id++;
		lst=id;
	}
	id=0;lst=0;
	while(id<len)
	{
		if(s[id]!='n') 
		{
			id++;lst=id;continue;
		}
		while(id<len&&s[id]=='n') id++;
		id--;
		//cout<<id<<endl;
		ans*=f[id+1-lst];
		ans%=mod;id++;
		lst=id;
	}
	cout<<ans<<endl;
	return 0;
 } 