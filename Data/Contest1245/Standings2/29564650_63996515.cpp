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
	int a,b;
	cin>>a>>b;
	while(b)
	{
		a%=b;
		a^=b^=a^=b;
	}
	if(a==1)cout<<"Finite"<<endl;
	else cout<<"Infinite"<<endl;
}
int main()
{
	int t;cin>>t;
	while(t--)solve();
}