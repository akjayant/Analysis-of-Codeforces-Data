#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
char a[maxn],b[maxn];
int n,t,vis[30];
vector<int>v[30];
vector<pair<int,int> >vec;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>a+1>>b+1;
        int sum=0,wz=0;
        memset(vis,0,sizeof vis);
        vec.clear();
        for(int i=0; i<26; i++)v[i].clear();
        for(int i=1; i<=n; i++)
        {
            vis[a[i]-'a']++;
            vis[b[i]-'a']++;
            if(a[i]!=b[i])v[a[i]-'a'].push_back(i);
        }
        for(int i=0; i<26; i++)
            if(vis[i]%2)wz=1;
        if(wz)cout<<"No"<<endl;
        else
        {
            for(int i=0; i<26; i++)
            {
                int len=v[i].size();
                if(len<=1)continue;
                vector<int>pos;
                for(int j=0; j<len; j++)
                {
                    int k=v[i][j];
                    if(a[k]==b[k])continue;
                    else pos.push_back(k);
                }
                len=pos.size();
                if(len<=1)continue;
                for(int j=0; j<len; j+=2)
                {
                    if(j+1>=len)break;
                    vec.push_back(make_pair(pos[j],pos[j+1]));
                    swap(a[pos[j]],b[pos[j+1]]);
                }
            }
            vector<int>p;
            for(int i=1; i<=n; i++)
            {
                if(a[i]==b[i])continue;
                p.push_back(i);
            }
            int len=p.size();
            for(int i=0; i<len; i++)
            {
                if(a[p[i]]==b[p[i]])continue;
                for(int j=i+1; j<len; j++)
                {
                    if(b[p[j]]==a[p[i]])
                    {
                        swap(b[p[j]],a[p[j]]);
                        vec.push_back(make_pair(p[j],p[j]));
                        swap(a[p[j]],b[p[i]]);
                        vec.push_back(make_pair(p[j],p[i]));
                        break;
                    }
                    else if(a[p[j]]==b[p[i]])
                    {
                        swap(a[p[j]],b[p[j]]);
                        vec.push_back(make_pair(p[j],p[j]));
                        swap(b[p[j]],a[p[i]]);
                        vec.push_back(make_pair(p[i],p[j]));
                        break;
                    }
                    else if(a[p[i]]==a[p[j]])
                    {
                        swap(b[p[i]],a[p[j]]);
                        vec.push_back(make_pair(p[j],p[i]));
                    }
                    else if(b[p[i]]==b[p[j]])
                    {
                        swap(a[p[i]],b[p[j]]);
                        vec.push_back(make_pair(p[i],p[j]));
                    }
                }
            }
            len=vec.size();
            if(len>2*n)
            {
                cout<<"No"<<endl;
                continue;
            }
            cout<<"Yes"<<endl;
            cout<<len<<endl;
            for(int i=0; i<len; i++)
                cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }
    }
    return 0;
}
