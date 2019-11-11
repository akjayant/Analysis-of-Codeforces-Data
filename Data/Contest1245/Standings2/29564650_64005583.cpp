#include<bits/stdc++.h>
using namespace std;
namespace RNG{
    unsigned int seed;
    void init(int p){seed=p;}
    unsigned int rnd()
    {
        unsigned int res=(seed<<4)+(seed^0x23414326)-(seed>>4)-(seed^0x54378320);
        return (seed=((seed+res<<1)^res)>>1);
    }
}
long long ans=1,mod=1000000007,fib[100005];
long long count(int c)
{
	return fib[c];
}
int main()
{
	string s;
	cin>>s;
	if(s.find('m')!=s.npos||s.find('w')!=s.npos)
	{
		cout<<0<<endl;
		return 0;
	}
	int cnt=0;
	fib[0]=fib[1]=1;for(int i=2;i<=100000;++i)fib[i]=(fib[i-1]+fib[i-2])%mod;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='n')++cnt;
		else if(cnt)ans=(ans*count(cnt)%mod)%mod,cnt=0;
	}
	if(cnt)ans=(ans*count(cnt)%mod)%mod,cnt=0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='u')++cnt;
		else if(cnt)ans=(ans*count(cnt)%mod)%mod,cnt=0;
	}
	if(cnt)ans=(ans*count(cnt)%mod)%mod,cnt=0;
	cout<<ans<<endl;
	return 0;
}