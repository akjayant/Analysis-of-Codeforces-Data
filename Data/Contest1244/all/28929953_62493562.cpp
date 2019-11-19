
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v1,v2,v3,v[100005];
long long ans=9999999999999999,n,sum,x[100005];
bool vis[100005];
void dfs(int p,string s, int q){
    char c=s[q%3];
    if(c=='1'){
        sum+=v1[p];
    }
    else if(c=='2'){
        sum+=v2[p];
    }
    else sum+=v3[p];
    q++;
    if(q==n)return;
    vis[p]=1;
    //cout<<sum<<' ';
    for(int i=0;i<v[p].size();i++){
        if(!vis[v[p][i]]){
            dfs(v[p][i],s,q);
        }
    }
}
void dfs2(int p,string s, int q){
    char c=s[q%3];
    if(c=='1'){
        x[p]=1;
    }
    else if(c=='2'){
        x[p]=2;
    }
    else x[p]=3;
    q++;
    if(q==n)return;
    vis[p]=1;
    for(int i=0;i<v[p].size();i++){
        if(!vis[v[p][i]]){
            dfs2(v[p][i],s,q);
        }
    }
}
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,k,i,j,t,p,q;
    cin>>n;
    v1.push_back(0);
    v2.push_back(0);
    v3.push_back(0);
    ans=9999999999999999;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v1.push_back(a);
    }
    for(i=0; i<n; i++)
    {
        cin>>a;
        v2.push_back(a);
    }
    for(i=0; i<n; i++)
    {
        cin>>a;
        v3.push_back(a);
    }
    for(i=1; i<n; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        if(v[a].size()>2||v[b].size()>2)
        {
            cout<<-1;
            return 0;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(v[i].size()==1)
        {
            p=i;
            break;
        }
    }
    string s="123",sa;
    while(1)
    {

        sum=0;
        memset(vis,0,sizeof(vis));
        dfs(p,s,0);
        if(sum<ans){
            ans=sum;sa=s;
        }
        //cout<<s<<' '<<sum<<'\n';
        next_permutation(s.begin(),s.end());
        if(s=="123")break;
    }
    memset(vis,0,sizeof(vis));
    cout<<ans<<'\n';
    dfs2(p,sa,0);
    for(i=1;i<=n;i++){
        cout<<x[i]<<' ';
    }
    return 0;
}
