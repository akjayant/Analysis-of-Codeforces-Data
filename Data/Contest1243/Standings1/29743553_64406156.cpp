/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
map<long long,long long>mp;
long long vis[200005],x[200005];
set<pair<long long,long long> >st;
vector<long long>v;
void dfs(long long p)
{
    if(vis[p])
        return;
    vis[p]=1;
    set<pair<long long,long long> >::iterator it,jt;
    vector<long long>qu;
    it=st.begin();
    while(it!=st.end())
    {
        long long q=it->second;
        q*=10000000;
        q+=p;
        if(!mp[q])
        {
            qu.push_back(it->second);
            jt=it;
            jt++;
            st.erase(it);
            it=jt;
        }
        else it++;
    }
    for(int i=0;i<qu.size();i++)dfs(qu[i]);
}
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b;
        c=a*10000000+b;
        d=b*10000000+a;
        mp[c]=1;
        mp[d]=1;
        x[a]++;
        x[b]++;
    }
    for(i=1; i<=n; i++)
    {
        st.insert({x[i],i});
    }
    set<pair<long long,long long> >::iterator it;
    it=st.begin();
    while(it!=st.end())
    {
        v.push_back(it->second);
        it++;
    }
    for(i=0; i<n; i++)
    {
        if(!vis[v[i]])
        {
            it=st.begin();
            st.erase(it);
            dfs(v[i]);
            f++;
        }
    }
    cout<<f-1;
    return 0;
}
