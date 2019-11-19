#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp(a,b) make_pair(a,b)

int n;
int l[2020];
long long power[2020],co[2020];
pair<int,int> node[2020];
priority_queue<pair<long long,pair<int,int> > > pq;

int fi(int nw)
{
	if(l[nw]==nw)return nw;
	return l[nw]=fi(l[nw]);
}

void uni(int l1,int l2)
{
	if(power[l1]<=power[l2])
	{
		l[l2]=l1;
		power[l2]=0;
	}
	else
	{
		l[l1]=l2;
		power[l1]=0;
	}
}

main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)l[i]=i;
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		node[i]=mp(a,b);
	}
	for(int i=0;i<n;i++)scanf("%I64d",&power[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&co[i]);
		for(int j=0;j<i;j++)
		{
			pq.push(mp(-((co[i]+co[j])*(long long)(abs(node[i].F-node[j].F)+abs(node[i].S-node[j].S))),mp(i,j)));
		}
	}
	long long ans=0;
	queue<int> ans1;
	queue<pair<int,int> > ans2;
	while(!pq.empty())
	{
		long long cost=-pq.top().F;
		int a=pq.top().S.F,b=pq.top().S.S;
		pq.pop();
		if(fi(a)!=fi(b))
		{
			if(cost<max(power[l[a]],power[l[b]]))
			{
				ans+=cost;
				//printf(":%lld:\n",cost);
				uni(l[a],l[b]);
				ans2.push(mp(a,b));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(power[i]==0)continue;
		ans+=power[i];
		ans1.push(i);
	}
	printf("%I64d\n%d\n",ans,ans1.size());
	while(!ans1.empty())
	{
		printf("%d ",ans1.front()+1);
		ans1.pop();
	}
	printf("\n%d\n",ans2.size());
	while(!ans2.empty())
	{
		printf("%d %d\n",ans2.front().F+1,ans2.front().S+1);
		ans2.pop();
	}
}
