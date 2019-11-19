#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int n,m;

vector<int>grf[100005];
bool vis[100005];
 
 
int main()
{
    //freopen("testcases.txt", "r", stdin);

    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }

    int ans=0;
    set<int>tot;

    for(int i=1;i<=n;i++) {
        tot.insert(i);
    }

    for(int i=1;i<=n;i++) {
        if(vis[i]) {
            continue;
        }

        ans++;
        
        queue<int>bfs;
        bfs.push(i);
        vis[i]=1;

        while(!bfs.empty()) {
            int now=bfs.front();
            bfs.pop();

            set<int>nxts;
            for(int j=0;j<grf[now].size();j++) {
                int nxt=grf[now][j];
                if(tot.find(nxt)!=tot.end()) {
                    tot.erase(nxt);
                    nxts.insert(nxt);
                }
            }

            for(set<int>::iterator i=tot.begin();i!=tot.end();i++) {
                bfs.push(*i);
                vis[*i]=1;
            }

            tot=nxts;

        }

    }

    printf("%d\n",ans-1);
 
 
    return 0;
}