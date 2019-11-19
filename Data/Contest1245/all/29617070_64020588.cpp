/*Author: ADITYA SHETH*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
int find_parent(int parent[],int a)
{
    if(parent[a]>=0)
    {
        parent[a]=find_parent(parent,parent[a]);
        return parent[a];
    }
    else
    {
        return a;
    }    
}
void merge_sets(int parent[],int a,int b)
{
    int p1=find_parent(parent,a);
    int p2=find_parent(parent,b);
    if(p1==p2)
    {
        return;
    }
    else
    {
        if(abs(parent[p1])>abs(parent[p2]))
        {
            parent[p1]-=abs(parent[p2]);
            parent[p2]=p1;
        }   
        else
        {
            parent[p2]-=abs(parent[p1]);
            parent[p1]=p2;
        }        
    }       
}
/*
Explanation:
1) Parent[] array stores the information of the parent of the index position.
2) if The parent of the index pos is not there then it contains the total number of nodes it has as its children and grand children with negative sign.
*/

const int N=2e3+10;
int x[N];
int y[N];
int k[N];
int c[N];
int parent[N];
int dis(int i,int j)
{
	int ret=abs(x[i]-x[j])+abs(y[i]-y[j]);
	return ret;
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	vector<pair<int,pair<int,int>>>edges;
	for(int i=1;i<=n;i++)
	{
		edges.push_back({c[i],{0,i}});
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			edges.push_back({(k[i]+k[j])*dis(i,j),{i,j}});
		}
	}
	int ans=0;
	memset(parent,-1,sizeof(parent));
	sort(edges.begin(),edges.end());
	vector<int> ve;
	vector<pair<int,int>> e;
	for(int i=0;i<edges.size();i++)
	{
		int cost=edges[i].first;
		int u=edges[i].second.first;
		int v=edges[i].second.second;
		if(find_parent(parent,u)!=find_parent(parent,v))
		{
			ans+=cost;
			merge_sets(parent,u,v);
			if(u==0)
			{
				ve.push_back(v);
			}
			else
			{
				e.push_back({u,v});
			}		
		}
	}
	cout<<ans<<endl;
	cout<<ve.size()<<endl;
	for(auto x: ve)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<e.size()<<endl;
	for(int i=0;i<e.size();i++)
	{
		cout<<e[i].first<<" "<<e[i].second<<endl;
	}
}
