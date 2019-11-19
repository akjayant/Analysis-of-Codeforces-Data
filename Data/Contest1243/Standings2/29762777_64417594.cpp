#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

int n,m,ans,mi = 1,flag;
int du[MAXN],vis[MAXN],pos[MAXN];
map<int,int>mp[MAXN];
set<int>st;
queue<int>pq;
vector<int>e;

int main()
{
    string r = "The front of the code";
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        mp[a][b] = mp[b][a] = 1;
        du[a]++;
        du[b]++;
    }
    int debug = MAXN;
    char sss[MAXN];
    for(int i=1; i<=n; i++)
    {
        st.insert(i);
        if(du[i] < du[mi])
        {
            flag = mi;
            mi = i;
        }
    }
    st.erase(mi);
    vis[mi] = 1;
    for(int i=1; i<=n; i++)
    {
        if(i != mi)
        {
            if(mp[i][mi] == 0 && !vis[i])
            {
                st.erase(i);
                vis[i] = 1;
                pos[i] = i;
                pq.push(i);
            }
        }
    }
    while(st.size())
    {
        string s = "D";
        string an = "I Like Codeforces";
        while(pq.size())
        {
            int ff = pq.front();pq.pop();
            e.clear();
            set<int>::iterator it;
            for(it = st.begin();it != st.end(); it++)
            {
                if(mp[*it][ff] == 0)
                {
                    pos[*it] = *it;
                    vis[*it] = 1;
                    e.push_back(*it);
                }
            }
            int len = e.size();
            for(int i=0; i<len; i++)
            {
                st.erase(e[i]);
                pos[e[i]] = e[i];
                vis[e[i]] = 1;
                pq.push(e[i]);
            }
        }
        if(st.size())
        {
            ans++;
            int ff = *st.begin();
            pq.push(ff);
            st.erase(ff);
            vis[ff] = 1;
        }
    }
    printf("%d",ans);
    string an = "I Like Codeforces";
}
