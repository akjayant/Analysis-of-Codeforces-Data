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
int main()
{
	int n;
	sf1(n);
	lint k;
	sf1ll(k);
    lint a[n+5];
    for(int i=0;i<n;i++)
    	sf1ll(a[i]);
    sort(a,a+n);
    deque< pair<lint,lint> >q;
    for(int i=0;i<n;i++)
    {
    	q.push_back(jora(a[i],1ll));
    	//cout<<a[i]<<endl;
    }
    while(k>0 && q.size()>1)
    {
    	// cout<<q.front().fs<<" "<<q.back().fs<<endl;
    	lint mn=q.front().fs;
    	lint cnt=0;
    	while(q.size() && q.front().fs==mn)
    	{
    		cnt+=q.front().sc;
            q.pop_front();
    	}
    	if(cnt)
    		q.push_front(jora(mn,cnt));

    	cnt=0;
    	lint mx=q.back().fs;
    	cnt=0;
    	while(q.size() && q.back().fs==mx)
    	{
    		cnt+=q.back().sc;
            q.pop_back();
    	}
    	if(cnt)
    		q.push_back(jora(mx,cnt));
    	if(q.size()==1)
    		break;
    	lint x=1ll*q.front().sc;
    	lint y=1ll*q.back().sc;
    	// cout<<x<<" "<<y<<endl;
    	if(k<x && k<y) break;

    	if(x<y)
    	{
            lint nxt=q[1].fs;
            lint rem=nxt-q.front().fs;
            lint add=min(k,rem*(1ll*x));
            // cout<<nxt<<" "<<q.front().fs<<" "<<rem<<" "<<add<<endl;
            add = add-(add%x);
            k-=add;
            add/=x;
            q.front().fs+=add;
    	}
    	else
    	{
    		lint nxt=q[q.size()-2].fs;
    		lint rem=q.back().fs-nxt;
            lint add=min(k,rem*(1ll*y));
            // cout<<nxt<<" "<<q.back().fs<<" "<<rem<<" "<<add<<endl;
            add = add-(add%y);
            k-=add;
            add/=y;
            q.back().fs-=add;
    	}
    }
    lint ans=q.back().fs-q.front().fs;
    pf1ll(ans);
	return 0;
}