#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
vector<int> v;
set<pair<int,int> >st;
int bfs(int x)
{
    queue<int> q;
    q.push(x);
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cnt++;
        int len=v.size();
        for(int i=0;i<len;i++,len=v.size())
        {
            int p=v[i];
            if(st.find(make_pair(u,p))!=st.end()) continue;
            else swap(v[i],v.back()),v.pop_back(),q.push(p),i--;
        }
    }
    return cnt;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        st.insert(make_pair(u,v));
        st.insert(make_pair(v,u));
    }
    for(int i=1;i<=n;i++) v.push_back(i);
    int ans=0;
    while(!v.empty())
    {
        int x=v.back();
        v.pop_back();
        bfs(x);
        ans++;
    }
    printf("%d\n",ans-1);
    return 0;
}
