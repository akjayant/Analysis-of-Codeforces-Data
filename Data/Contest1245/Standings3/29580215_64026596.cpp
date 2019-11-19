#include <bits/stdc++.h>
using namespace std;
#define inta long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back

int n;
inta x[3000],y[3000],cost[3000],k[3000];


int tab[3000],level[3000],on[3000];


int findBase(int a)
{
	if(tab[a]==a) return a;
	return findBase(tab[a]);
}

void connect(int i,int j)
{
	int x2=findBase(i),y2=findBase(j);
	if(x2==y2) return;
	if(level[x2]>level[y2]) tab[y2]=x2;
	else
	{
		tab[x2]=y2;
		if(level[x2]==level[y2]) level[y2]++;
	}
	on[x2]=max(on[x2],on[y2]);
	on[y2]=max(on[x2],on[y2]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	priority_queue<pair<inta,ii>,vector<pair<inta,ii> >, greater<pair<inta,ii> > >pq;	
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++) cin>>cost[i];
	for(int i=0;i<n;i++) cin>>k[i];
	for(int i=0;i<=n;i++) tab[i]=i,level[i]=1;
	vector<int>v;// on lights
	vector<ii>v2; // vasl shodan
	inta ans=0;
	
	for(int i=0;i<n;i++)
	{
		pq.push(mp(cost[i],mp(-1,i)));
		for(int j=i+1;j<n;j++)
		{
			pq.push(mp((abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),mp(i,j)));
		}
	}
	while(!pq.empty())
	{
		pair<inta,ii> r=pq.top();
		pq.pop();
		if(r.second.first==-1)
		{
			if(on[findBase(r.second.second)]) continue;
			else {on[findBase(r.second.second)]=1; ans+=r.first;v.pb(r.second.second);}
		}
		else
		{
			
			if(findBase(r.second.first)!=findBase(r.second.second)&&(on[findBase(r.second.first)]==0||on[findBase(r.second.second)]==0))
			{
				connect(r.second.first,r.second.second);
				ans+=r.first;
				v2.pb(mp(r.second.first,r.second.second));
			}
		}
		
	}
	cout<<ans<<endl;
	cout<<v.size()<<endl;
	for(auto i:v)
	{
		cout<<i+1<<" ";
	}cout<<endl;
	cout<<v2.size()<<endl;
	for(auto i:v2)
	{
		cout<<i.first+1<<" "<<i.second+1<<"\n";
	}
	
	
}