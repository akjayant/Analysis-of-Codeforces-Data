#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define mp make_pair
set<pi>edges;
set<int>s;
vector<int>v[200005];
int main()
{
    int i,j,k;
    int n;
    sd(n);
    int m;
    sd(m);
    while(m--)
    {
        sd(i);
        sd(j);
        edges.insert(mp(i,j));
        edges.insert(mp(j,i));
    }
    int grp=0;
    for(i=1;i<=n;i++)
        s.insert(i);
    queue<int>q;
    while(s.size()!=0)
    {
        if(!q.size())
        {
            grp++;
            int x=*s.begin();
            s.erase(x);
            v[grp].pb(x);
            // printf("%d\n",x );
            q.push(x);
        }
        int x=q.front();
        q.pop();
        vector<int>temp;
        for(auto it:s)
        {
            if(edges.find(mp(x,it))==edges.end())
            {
                temp.pb(it);
                v[grp].pb(it);
                // printf("%d\n", it);
                q.push(it);
            }
        }
        for(i=0;i<temp.size();i++)
            s.erase(temp[i]);
        temp.clear();
    }
    printf("%d\n",max(0,grp-1 ));
    
    return 0;
}
