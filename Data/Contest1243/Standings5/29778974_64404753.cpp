#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;

char a[N],b[N];
int vis[30];
vector<int>v[30];
vector<pair<int,int>>q;

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>a+1>>b+1;
        int cnt=0;
        int bj=0;
        memset(vis,0,sizeof vis);
        q.clear();
        for(int i=0; i<26; i++)
            v[i].clear();
        for(int i=1; i<=n; i++)
        {
            vis[a[i]-'a']++;
            vis[b[i]-'a']++;
            if(a[i]!=b[i])
                v[a[i]-'a'].push_back(i);
        }
        for(int i=0; i<26; i++)
        {
            if(vis[i]%2)
                bj=1;
        }
        if(bj)
            cout<<"No\n";
        else
        {
            for(int i=0; i<26; i++)
            {
                int len=v[i].size();
                if(len<=1)
                    continue;
                vector<int>g;
                for(int j=0; j<len; j++)
                {
                    int k=v[i][j];
                    if(a[k]==b[k])
                        continue;
                    else
                    {
                        g.push_back(k);
                    }
                }
                len=g.size();
                if(len<=1)
                    continue;
                for(int j=0; j<len; j+=2)
                {
                    if(j+1>=len)break;
                    q.push_back(make_pair(g[j],g[j+1]));
                    swap(a[g[j]],b[g[j+1]]);
                }
            }
            vector<int>p;
            for(int i=1;i<=n;i++){
                if(a[i]==b[i])continue;
                p.push_back(i);
            }
            int len=p.size();
            for(int i=0;i<len;i++){
                if(a[p[i]]==b[p[i]])continue;
                for(int j=i+1;j<len;j++){
                    if(b[p[j]]==a[p[i]]){
                        swap(b[p[j]],a[p[j]]);
                        q.push_back(make_pair(p[j],p[j]));
                        swap(a[p[j]],b[p[i]]);
                        q.push_back(make_pair(p[j],p[i]));
                        break;
                    }
                    else if(a[p[j]]==b[p[i]]){
                        swap(a[p[j]],b[p[j]]);
                        q.push_back(make_pair(p[j],p[j]));
                        swap(b[p[j]],a[p[i]]);
                        q.push_back(make_pair(p[i],p[j]));
                        break;
                    }
                    else if(a[p[i]]==a[p[j]]){
                        swap(b[p[i]],a[p[j]]);
                        q.push_back(make_pair(p[j],p[i]));
                    }
                    else if(b[p[i]]==b[p[j]])
                    {
                        swap(a[p[i]],b[p[j]]);
                        q.push_back(make_pair(p[i],p[j]));
                    }
                }
            }
            len=q.size();
            if(len>2*n)
            {
                cout<<"No\n";
                continue;
            }
            cout<<"Yes\n";
            cout<<len<<endl;
            for(int i=0; i<len; i++)
            {
                cout<<q[i].first<<" "<<q[i].second<<endl;
            }
        }
    }
    return 0;
}
