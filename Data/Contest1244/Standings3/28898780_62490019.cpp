/*
 
author : Avi Mallick
 
          CSE'15 SUST
 
*/
#include <bits/stdc++.h>
//#include <sstream>
//#include <cstdlib>
//#include <cctype>
//#include <cmath>
//#include <algorithm>
//#include <set>
//#include <queue>
//#include <stack>
//#include <list>
//#include <iostream>
//#include <fstream>
//#include <numeric>
//#include <string>
//#include <vector>
//#include <cstring>
//#include <map>
//#include <iterator>
//#include<numeric>
// #include<complex>
#define pii                   pair<int,int>
#define tii                   pair<int,pair<int,int> >
#define mkp                   make_pair
#define fs                    first
#define sc                    second
#define pb                    push_back
#define ppb                   pop_back()
#define pcase(x)              printf("Case #%d: ",x)
#define hi                    cout<<"hi"<<endl;
#define mod                   1000000007
// #define inf                   1e18+1
#define pi                    acos(-1.0)
#define mem(arr,x)            memset((arr), (x), sizeof((arr)));
#define FOR(i,x)              for(int i=0;i<(x); i++)
#define FOR1(i,x)             for(int i = 1; i<=(x) ; i++)
#define jora(a,b)             make_pair(a,b)
#define tora(a,b,c)           jora(a,jora(b,c))
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%lld %lld\n",a,b)
#define pf3ll(a,b,c)          printf("%lld %lld %lld\n",a,b,c)
#define N 200000+5
#define level 26
#define eps 1e-9
 
// #define mat vector<vector<int> >
// #define m 6
using namespace std;
typedef long long lint;
vector<int>vt[N];
lint cost[4][N];
vector<int>a;
void dfs(int u,int p)
{
	a.push_back(u);
	for(int v : vt[u])
	{
		if(v!=p) dfs(v,u);
	}
}
int main()
{
	int n;
	sf1(n);
	for(int j=0;j<3;j++)
	for(int i=1;i<=n;i++)
		
			sf1ll(cost[j][i]);
		int f=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		sf2(u,v);
		vt[u].push_back(v);
		vt[v].push_back(u);
        if(vt[u].size()>2 || vt[v].size()>2) f=-1;
	}
	if(f==-1)
	{
		pf1(-1);
		return 0;
	}

	for(int i=1;i<=n;i++)
	{
		if(vt[i].size()==1)
		{
			dfs(i,0);
			break;
		}
	}
	lint ans=1e18;
	vector<int>p;
	vector<int>q;
	for(int i=0;i<3;i++)
	   p.push_back(i);
	do
	{
		lint tem=0ll;
         for(int i=0;i<n;i++)
         {
         	int col=p[i%3];
         	int id=a[i];
         	tem+=cost[col][id];
         }
         if(tem<ans)
         {
         	ans=tem;
         	q=p;
         }
	}
	while(next_permutation(p.begin(),p.end()));
    pf1ll(ans);
    int colors[n+4];
    for(int i=0;i<n;i++)
    {
    	int col=q[i%3];
        int id=a[i];
        colors[id]=col+1;
       // cout<<id<<" "<<col<<endl;
    }
    for(int i=1;i<=n;i++)
    {
    	if(i!=1) printf(" ");
    	printf("%d",colors[i]);
    }
    printf("\n");


	return 0;
}