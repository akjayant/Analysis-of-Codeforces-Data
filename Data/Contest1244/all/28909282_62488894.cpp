#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <set>
#include <queue>
using namespace std;
long long con[200005]={0};
char all[200005];
char fin[200005];
queue < pair < pair < int , int > ,pair < int , char > > >L;

int main()
{
	long long N,K,l,r,t,i,nxt;
	char what;
	scanf("%lld %lld %s",&N,&K,all);
	for(i=0;i<N;i++) con[i]=1e18;
	for(i=0;i<N;i++)
    {
        if(con[i]==-1) continue;
        if(all[i]==all[(i+1)%N])
        {
            l=(i+N-1)%N;
            r=(i+2)%N;
            con[i]=-1;
            con[(i+1)%N]=-1;
            while(1)
            {
                if(con[l]==-1) break;
                if(all[l]==all[(l+1)%N]) con[l]=-1;
                else break;
                l=(l+N-1)%N;
            }
            while(1)
            {
                if(con[r]==-1) break;
                if(all[r]==all[(r+N-1)%N]) con[r]=-1;
                else break;
                r=(r+1)%N;
            }
            L.push(make_pair(make_pair(l,1),make_pair(-1,all[i])));
            L.push(make_pair(make_pair(r,1),make_pair(1,all[i])));
        }
    }
    while(!L.empty())
    {
        auto x=L.front();
        L.pop();
        what=x.second.second;
        l=x.first.first;
        t=x.first.second;
        nxt=x.second.first;
        //printf("%lld %lld\n",t,l);
        if(con[l]!=1000000000000000000) continue;
        if(all[l]!=all[(l+N+nxt)%N])
        {

            con[l]=t;
            fin[l]=what;
            L.push(make_pair(make_pair((l+N+nxt)%N,t+1),make_pair(nxt,what)));
        }
        else continue;
    }
    for(i=0;i<N;i++)
    {
        if(con[i]==-1) printf("%c",all[i]);
        else if(con[i]<=K) printf("%c",fin[i]);
        else
        {
            if(all[i]=='W'&&K%2==0||all[i]=='B'&&K%2==1) printf("W");
            else printf("B");
        }
    }
    //for(i=0;i<N;i++) printf("%lld %lld\n",i,con[i]);
	return 0;
}
