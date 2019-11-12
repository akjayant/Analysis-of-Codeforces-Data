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
int c1[150],c2[150],s[150];
void solve()
{
	int n;
	string a,b,c,d;
	cin>>n>>a>>b;
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	int tot=0;
	vector<pair<int,int> >vec;
	//for(int i=0;i<n;++i)if(a[i]!=b[i])c.push_back(a[i]),d.push_back(b[i]);
	for(int i=0;i<n;++i)++c1[a[i]],++c2[b[i]];
	for(int i='a';i<='z';++i)
	{
		s[i]=c1[i]+c2[i];
		if(((c1[i]+c2[i])&1))
		{
			cout<<"No"<<endl;
			return;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(a[i]==b[i])continue;
		int ptr=n+1;
		for(int j=n-1;j+1;--j)if(b[j]==b[i]&&a[j]!=b[j]&&j!=i){ptr=j;break;}
		if(ptr>=n)
		{
			++++tot;
			for(int j=n-1;j+1;--j)if(a[j]==b[i]&&a[j]!=b[j]&&j!=i){ptr=j;break;}
			swap(a[ptr],b[ptr]);
			swap(a[i],b[ptr]);
			vec.push_back({ptr+1,ptr+1});
			vec.push_back({i+1,ptr+1});
			continue;
		}
		++tot;
		vec.push_back({i+1,ptr+1});
		swap(a[i],b[ptr]);
	}
	/*for(int i='a';i<='z';++i)
	{
		if(c1[i]==c2[i])continue;
		if(c1[i]<c2[i])
		{
			int d=c2[i]-c1[i];d>>=1;
			while(d)
			{
				int ptr=n+1;
				for(int j=n-1;j+1;--j)
				{
					if(b[j]==i)
					{
						ptr=j;
						break;
					}
				}
				for(int j=0;j<n;++j)
				{
					if(b[j]==i&&a[j]!=i)
					{
						swap(a[j],b[ptr]);
						vec.push_back({j+1,ptr+1});
						++tot;
					}
				}
				--d;
			}
		}
	}*/
	cout<<"Yes"<<endl<<tot<<endl;
	for(int i=0;i<tot;++i)cout<<vec[i].first<<" "<<vec[i].second<<endl;
}
int main()
{
	int t;cin>>t;while(t--)solve();
	return 0;
}