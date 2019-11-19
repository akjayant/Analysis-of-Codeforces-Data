 #pragma comment(linker, "/stack:200000000")
 #pragma GCC optimize("Ofast")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 #include<bits/stdc++.h>
 #define int long long
 using namespace std;

int c[2005];
int k[2005];
int dis[2005][2005];
vector<pair<int,pair<int,int> > >mm;
int parent[2005];
int sz[2005];
pair<int,int> ans[2005];
int cost=0;
vector<pair<int,int> >res;

int find_parent(int a)
{
    if(parent[a]==a)
        return a;
    return parent[a]=find_parent(parent[a]);
}

void merge(int a,int b,int dd)
{
    int x1,y1;
    x1=a;
    y1=b;
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b)
    {
        if(sz[b]>sz[a])
            swap(a,b);
        int x=ans[a].first,y=ans[b].first;
        if(dd<x || dd<y)
        {
            ans[a]=min(ans[a],ans[b]);
            cost+=dd;
            res.push_back({x1,y1});
            sz[a]+=sz[b];
            parent[b]=a;
        }
    }
}


signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
 #ifndef ONLINE_JUDGE
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
 #endif
 
     clock_t clk;
 	clk = clock();
 
// -------------------------------------Code starts here--------------------------------------------------------------------- 

    int n;
    cin>>n;
    pair<int,int>p[n+1];
    for(int i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;

    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>k[i];
    
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
        ans[i].first=c[i];
        ans[i].second=i;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=(k[i]+k[j])*(abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second));
    
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            mm.push_back({dis[i][j],{i,j}});

    sort(mm.begin(),mm.end());
    for(auto i:mm)
    {
        merge(i.second.first,i.second.second,i.first);
    }
    vector<int>res2;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==i)
            {
                res2.push_back(ans[i].second);
                cost+=ans[i].first;
            }
    }
    cout<<cost<<"\n";
    cout<<res2.size()<<"\n";
    for(auto i:res2)
        cout<<i<<" ";
    cout<<"\n";
    cout<<res.size()<<"\n";
    for(auto i:res)
        cout<<i.first<<" "<<i.second<<"\n";
// -------------------------------------Code ends here------------------------------------------------------
 
     clk = clock() - clk;
 	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
 	return 0;
 }