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
int tag[10005],c1[150],c2[150];
int aabs(int x){return x>0?x:-x;}
void solve()
{
	int n;
	string a,b,c,d;
	cin>>n>>a>>b;
	//memset(tag,0,sizeof(tag));
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	int tot=0;
	for(int i=0;i<n;++i)if(a[i]!=b[i])c.push_back(a[i]),d.push_back(b[i]);
	for(int i=0;i<n;++i)++c1[a[i]],++c2[b[i]];
	for(int i='a';i<='z';++i)
	{
		if(((c1[i]+c2[i])&1)||aabs(c1[i]-c2[i])>2)
		{
			cout<<"No"<<endl;
			return;
		}
	}
	if(c.size()>2||c.size()==1){cout<<"No"<<endl;return;}
	if(c.size()==0){cout<<"Yes"<<endl;return;}
	for(int i=0;i<c.size();++i)
	{
		for(int j=0;j<c.size();++j)
		{
			swap(c[i],d[j]);
			if(c==d)
			{
				cout<<"Yes"<<endl;
				return;
			}
			swap(c[i],d[j]);
		}
	}
	cout<<"No"<<endl;
}
int main()
{
	int t;cin>>t;while(t--)solve();
	return 0;
}