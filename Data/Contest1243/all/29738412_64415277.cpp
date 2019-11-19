#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl '\n'
#define pw(x) (1ll<<(x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=1e5+1;
int n,m;
vi e[N];
int f[N];
set<int>ss,ts;
set<int>::iterator it;
queue<int>que;
 
int main() 
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	while(cin>>n>>m)
	{
		rep(i,1,n+1)
		{
			ss.insert(i);
			f[i]=i;
		}
		rep(i,1,m+1)
		{
			int a,b;
			cin>>a>>b;
			e[a].pb(b);
			e[b].pb(a);
		}
		rep(i,1,n+1)
		{
			if(f[i]==i)
			{
				que.push(i);
				while(!que.empty())
				{
					int p=que.front();
					que.pop();
					rep(j,0,e[p].size())
					{
						if(ss.find(e[p][j])!=ss.end())
						{
							ts.insert(e[p][j]);
							ss.erase(e[p][j]);
						}
					}
					for(it=ss.begin();it!=ss.end();it++)
					{
						f[*it]=f[p];
						que.push(*it);
					}
					ss=ts;
					ts.clear();
				}
			}
		}
		ss.clear();
		rep(i,1,n+1)ss.insert(f[i]);
		cout<<ss.size()-1<<endl;
	}
	
	return 0;
}