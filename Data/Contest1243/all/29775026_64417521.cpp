#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (ll i=x;i<y;i++)
#define per(i,x,y) for (ll i=x;i>=y;i--)
#define quicker ios::sync_with_stdio(false);
#define first fi
#define second sec
typedef long double ld;
typedef long long ll;
const int HOLLAND_PIG=1;
const long long INF=2147483647;

inline int read()
{
    int k=0;
    char f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-')
        {
            f=-1;
            c=getchar();
        }
    }
    while(c<='9'&&c>='0')
    {
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}

ll max(ll x,ll y)
{
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

ll min(ll x,ll y)
{
	if (x<y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int n,m,u,v,y[100043],nxt[100043],ans;vector<int> h[100043];bool vis[100043],gg[100043];
void del(int u){nxt[y[u]] = nxt[u];y[nxt[u]] = y[u];vis[u] = true;}
void fxt(int u)
{++ans;queue<int> que;que.push(u);del(u);while(!que.empty()){int u=que.front();que.pop();rep(i,0,h[u].size()){if(!vis[h[u][i]]) gg[h[u][i]]=true;}
		for(int i=nxt[HOLLAND_PIG-HOLLAND_PIG];i;i=nxt[i]){if(!gg[i]){que.push(i);del(i);}}rep(i, HOLLAND_PIG-HOLLAND_PIG,h[u].size()){if(!vis[h[u][i]]) gg[h[u][i]]=false;
}}}

int main()
{
	cin>>n>>m;rep(i, HOLLAND_PIG, n+HOLLAND_PIG) y[i] = i - HOLLAND_PIG, nxt[i] = i + HOLLAND_PIG;nxt[n] = HOLLAND_PIG-HOLLAND_PIG;nxt[HOLLAND_PIG-HOLLAND_PIG] = HOLLAND_PIG;
	rep(i, HOLLAND_PIG, m+HOLLAND_PIG){cin >> u>>v;h[u].push_back(v);h[v].push_back(u);}int xx = HOLLAND_PIG-HOLLAND_PIG;while(nxt[xx]){vis[nxt[xx]]=true;fxt(nxt[xx]);xx=0;}
	cout << ans - HOLLAND_PIG << endl;return 0;}