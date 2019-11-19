//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
long long n,x[2005],y[2005],g[2005],k[2005],d1[2005],d2[2005],vos[2005],fake[2005],ans=0;
vector<long long> s1;
vector<pair<long long,long long> >s2;
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(long long i=1;i<=n;i++){
       cin>>g[i];d1[i]=g[i],d2[i]=1e17;
   	}
    for(long long i=1;i<=n;i++)cin>>k[i];
    for(long long i=1;i<=n;i++)
    {
        long long minv=1e17,flag=0;
        for(long long j=1;j<=n;j++){
            if(!fake[j]&&minv>min(d1[j],d2[j]))minv=min(d1[j],d2[j]),flag=j;
        }
        if(!flag)break;
        fake[flag]=1;ans+=minv;
        if (d1[flag]<d2[flag])
		   s1.push_back(flag);
        else 
		   s2.push_back(make_pair(flag,vos[flag]));
        for (long long j=1;j<=n;j++)
        {
            if (!fake[j])
			{
    			long long va=(abs(x[j]-x[flag])+abs(y[j]-y[flag]))*(k[j]+k[flag]);
                if (va<d2[j])
				{
					d2[j]=va;
					vos[j]=flag;
				}
            }
        }
    }
    cout<<ans<<endl<<s1.size()<<endl;
    for (long long i=0;i<s1.size();i++)
        cout<<s1[i]<<' ';
    cout<<endl<<s2.size()<<endl;
    for (long long i=0;i<s2.size();i++)
	   cout<<s2[i].first<<' '<<s2[i].second<<endl;
	return 0;
}