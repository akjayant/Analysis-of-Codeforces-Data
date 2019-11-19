#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100005;
int c[MAXN][3],deg[MAXN],p[MAXN],n,cnt;
bool vis[MAXN];
vector<int> e[MAXN];
ll f[MAXN][3][3],ans[MAXN],g[MAXN][3][3];

int main()
{
    cin >> n;
    for(int i = 1; i<=n; i++)
        scanf("%d",&c[i][0]);
    for(int i = 1; i<=n; i++)
        scanf("%d",&c[i][1]);
    for(int i = 1; i<=n; i++)
        scanf("%d",&c[i][2]);
    if(n==1)
    {
        cout << min(c[1][0],min(c[1][1],c[1][2])) << endl;
        return 0;
	}
    int u,v;
    for(int i = 1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        deg[u]++, deg[v]++;
        if(deg[u]>=3||deg[v]>=3)
        {
            cout << -1 << endl;
            return 0;
		}    
		e[u].push_back(v);
		e[v].push_back(u);
	}    
	int s = 0;
	for(int i = 1; i<=n; i++)
	    if(deg[i]==1)
	        s = i;
	int pos = s;
	p[++cnt] = pos;
	vis[pos] = true;
	while(1)
	{ 
        for(int i = 0; i<e[pos].size(); i++)
        {
            if(vis[e[pos][i]])
                continue;
            pos = e[pos][i];
            break;
		}    
		p[++cnt] = pos;
		vis[pos] = true;
		if(deg[pos]==1)
		    break;
	}    
	memset(f,0x3f,sizeof(f));
	for(int i = 0; i<3; i++)
	    for(int j = 0; j<3; j++)
	        f[0][i][j] = 0;
	for(int i = 1; i<=n; i++)
        for(int j = 0; j<3; j++)
            for(int k = 0; k<3; k++)
                for(int l = 0; l<3; l++)
                    if(l!=j&&j!=k&&k!=l)
                    {
                    	if(f[i-1][j][k]+c[p[i]][l]<f[i][k][l])
                    	{
                            f[i][k][l] = f[i-1][j][k]+c[p[i]][l];
                            g[i][k][l] = j*3+k;
						}
					  //  cout << "test " << i << " " << k << " " << l << " " << f[i][k][l] << " " << g[i][k][l] << endl; 
					} 
	ll res = 1ll<<62, pp = 0;
	for(int i = 0; i<3; i++)
	    for(int j = 0; j<3; j++)
	        if(f[n][i][j]<res)
	        {
	            res = f[n][i][j];
	            pp = i*3+j;
			}
	//cout << "test " << pp << endl;
	cout << res << endl;
	for(int i = n; i>=1; i--)
	{
        ans[p[i]] = pp%3+1;
        pp = g[i][pp/3][pp%3];
	}
	for(int i = 1; i<=n; i++)
	    printf("%d ",ans[i]);
	cout << endl;
	return 0;
}
