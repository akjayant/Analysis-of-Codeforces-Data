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
void solve()
{
	int n,r,p,s,wins=0;
	string str;
	char str2[105]="";
	cin>>n>>r>>p>>s>>str;
	for(int i=0;i<n;++i)
	{
		if(str[i]=='R')
		{
			if(p)--p,++wins,str2[i]='P';
			//else if(r)--r,str2.push_back('R');
			//else --s,str2.push_back('S');
		}
		if(str[i]=='S')
		{
			if(r)--r,++wins,str2[i]='R';
			//else if(s)--s,str2.push_back('S');
			//else --p,str2.push_back('P');
		}
		if(str[i]=='P')
		{
			if(s)--s,++wins,str2[i]='S';
			//else if(p)--p,str2.push_back('P');
			//else --r,str2.push_back('R');
		}
	}
	if(wins*2>=n)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;++i)
		{
			if(!str2[i])
			{
				if(r)--r,str2[i]='R';
				else if(s)--s,str2[i]='S';
				else --p,str2[i]='P';
			}
		}
		cout<<str2<<endl;
	}
	else cout<<"NO"<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)solve();
}