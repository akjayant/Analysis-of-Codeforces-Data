
  #pragma comment(linker, "/stack:200000000")
  #pragma GCC optimize ("Ofast")
  #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


  #include<bits/stdc++.h>
  #include <unordered_map> 
  using namespace std;
  #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  typedef long long int ll; 

  ll mod=1e9+7;
  ll mod1=998244351;
    ll power(ll a,ll b)
        {
            if(b==0) return 1;
            else if(b%2==0)
                return power((((a%mod)*(a%mod))%mod),b/2)%mod;
         else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
        }

  
  #define endl '\n'

  #define int ll
        vector<int> v[100001];
        int co[100001][4];
        int x[100001];
        int temp=0;
        void dfs(int u,int par)
        {
            int x1=-1;
            for(int i=0;i<v[u].size();++i)
            {
                if(v[u][i]!=par)
                {
                    x1=v[u][i];
                }
            }
            if(x1==-1)
                return;

            if(x[u]==1 and x[par]==2)
            {
                x[x1]=3;
            }

            if(x[u]==2 and x[par]==1)
            {
                x[x1]=3;
            }
            
            if(x[u]==1 and x[par]==3)
            {
                x[x1]=2;
            }
            
            if(x[u]==3 and x[par]==1)
            {
                x[x1]=2;
            }
            
            if(x[u]==2 and x[par]==3)
            {
                x[x1]=1;
            }
            
            if(x[u]==3 and x[par]==2)
            {
                x[x1]=1;
            }
            dfs(x1,u);
            
        }
  
  int32_t main()
  {
      IOS
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
      

      int n;
      cin>>n;
      for(int i=1;i<=n;++i)
        cin>>co[i][1];
       for(int i=1;i<=n;++i)
        cin>>co[i][2];
    for(int i=1;i<=n;++i)
        cin>>co[i][3];
        
    int deg[n+1];
    memset(deg,0,sizeof(deg)); 
      for(int i=0;i<n-1;++i)
      {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++;
        deg[b]++;
      }
      for(int i=1;i<=n;++i)
      {
        if(deg[i]>=3)
        {
            cout<<-1;
            return 0;
        }
      }
      int s=v[1][0];
      
      int pe[]={1,2,3};
      int cas=-1;
      int p=0;
      int temp=1e18;
      vector<int> te;
      do{

        int cp,cp1;
        memset(x,-1,sizeof(x));
        x[1]=pe[0];
        x[s]=pe[1];
        dfs(s,1);
        dfs(1,s);
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ans+=co[i][x[i]];
        }
        if(temp>ans)
        {
            temp=ans;
            te.clear();
            te.push_back(pe[0]);
            te.push_back(pe[1]);
            te.push_back(pe[2]);
        }

      }
      while(next_permutation(pe,pe+3));
      memset(x,-1,sizeof(x));
        x[1]=te[0];
        x[s]=te[1];
        dfs(s,1);
        dfs(1,s);
        
        cout<<temp<<endl;
        for(int i=1;i<=n;++i)
            cout<<x[i]<<" ";



  }   