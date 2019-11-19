#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
ll p;
ll t[maxn];
int od[maxn];
vector<ll> lsh;
vector<int> id[maxn];
queue<int> que;
priority_queue<ll,vector<ll>,greater<ll> > pq1;
priority_queue<int,vector<int>,greater<int> > pq2;
deque<pair<int,ll> > dq;
map<ll,bool> has;
ll ans[maxn];
struct BIT
{
	int bit[maxn];
	inline void add(int x,int v)
	{
		while(x<maxn)
		{
			bit[x]+=v;
			x+=x&-x;
		}
	}
	inline int sum(int x)
	{
		int ret=0;
		while(x>0)
		{
			ret+=bit[x];
			x-=x&-x;
		}
		return ret;
	}
}tree;
int main()
{
	int n;
	scanf("%d%I64d",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&t[i]);
		lsh.emplace_back(t[i]);
		tree.add(i+1,1);
	}
	sort(lsh.begin(),lsh.end());
	lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
	for(int i=0;i<lsh.size();i++)
	{
		pq1.push(lsh[i]);
		has[lsh[i]]=1;
	}
	for(int i=0;i<n;i++)
	{
		od[i]=lower_bound(lsh.begin(),lsh.end(),t[i])-lsh.begin();
		id[od[i]].emplace_back(i);
	}
	while(!pq1.empty())
	{
		ll tim=pq1.top();
		pq1.pop();
	//	cout<<"time "<<tim<<endl;
		int pos=lower_bound(lsh.begin(),lsh.end(),tim)-lsh.begin();
		if(lsh[pos]==tim)
		{
			for(int i=0;i<id[pos].size();i++)
			{
				pq2.push(id[pos][i]);
		//		cout<<"maytry "<<id[pos][i]<<endl;
			}
		}
		if(!dq.empty()&&dq.front().second==tim)
		{
		//	cout<<"back "<<dq.front().first<<endl;
			tree.add(dq.front().first+1,1);
			dq.pop_front();
		}
		if(!pq2.empty())
		{
			int id=pq2.top();
			if(tree.sum(id)==id)
			{
				pq2.pop();
				ll pret=(dq.empty()?tim:dq.back().second);
				pret+=p;
				if(!has.count(pret))
				{
					pq1.push(pret);
					has[pret]=1;
				}
				dq.push_back(make_pair(id,pret));
				ans[id]=pret;
				tree.add(id+1,-1);
			//	cout<<"go "<<id<<" "<<pret<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%I64d ",ans[i]);
	return 0;
}