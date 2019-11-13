#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const int N = 100010;
ll f[N];
const int mod = 1000000007;
int main()
{
	string s;
	cin>>s;
	s+=',';
	ll ans=1;
	int l = s.size();
	f[0]=1,f[1]=1,f[2]=2;
	for(int i=3;i<=l;i++) f[i]=(f[i-1]+f[i-2])%mod;
	ll now = 0,nn = -1;
	int c=1;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='m' || s[i]=='w') {c=0;break;}
		if(s[i]=='u')
		{
			if(nn==1) now++;
			else 
			{
				ans = ans*f[now]%mod; now = 1,nn=1;
			}
		} 
		else if(s[i]=='n')
		{
			if(nn==2) now++;
			else 
			{
				ans = ans*f[now]%mod; now = 1,nn=2;
			}
		}
		else 
		{
			ans = ans*f[now]%mod; now=0,nn=-1;
		}
	}
	if(c==0) cout<<"0\n";
	else cout<<ans%mod<<endl;
	return 0;
}

/*
Cn,0 + Cn-1,1 + Cn-2,2 + Cn-3,3
1
2
3
5
8
13
*/