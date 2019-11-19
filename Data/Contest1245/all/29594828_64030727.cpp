    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    typedef long long ll;
    const ll mod = 1e9+7;
    class Matrix
    {
      
       public:
          ll size=0;
          ll m[200][200];
          Matrix(ll n)
          {
             size = n;
            
             for(ll i = 0; i<n ; i++)
                for(ll j = 0; j<n ; j++)
                   m[i][j]=0;
          }
          ll n = size;
          void printer()
          {
             for(ll i = 0; i<size ; i++)
                {
                   for(ll j = 0; j<size ; j++)
                   cout<<m[i][j]<<' ';
                   cout<<endl;
                }
          }
       Matrix mul(Matrix A, Matrix B)
       {
          Matrix ans(A.size);
          for(ll i = 0; i<size ; i++)
          {
             for(ll j = 0; j<size ; j++)
             {
                for(ll k = 0; k<size ; k++)
                { 
                   ans.m[i][j] = max(A.m[i][k]+B.m[(k+1)%size][j],ans.m[i][j]);
                }
             }
          }
          return ans;
       }
    Matrix power(Matrix A,ll k)
    {
         // cout<<"called : k : "<<k<<endl;
          Matrix ans(A.size);
          
          if(k == 1)
             ans = A;
          else if(k == 0)
          {
             for(ll i = 0; i<size ; i++)
                for(ll j =0 ; j<size; j++)
                   ans.m[i][j]=0;
          }
          else
          {
             ans = A.power(A,k/2);
             ans = ans.mul(ans,ans);
             if(k%2 == 1)
                ans=ans.mul(ans,A);
          }
          return ans;
    }
  };
 const ll N =2001;
 ll par[N];
 ll find_set(ll v)
 {
  if(par[v]==v)
    return v;
  else
    return par[v] = find_set(par[v]);
 }

 void union_find(ll a, ll b)
 {
    a = find_set(a);
    b = find_set(b);
    if(a == b)
      return;
    else
      par[a] = b;
    return;
 }


  int  main()
  {
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
       ll n,yen = 0;
       cin>>n;
       vector<pair<ll,pair<ll,ll>>> edge;
       vector<pair<ll,ll>> sel;
       ll c[n+1],k[n+1],x[n+1],y[n+1];
       for(ll i = 1; i<=n ; i++) 
       {
          cin>>x[i]>>y[i];
         
       }
      for(ll i = 1; i<=n ; i++) 
       {
          cin>>c[i];
          pair<ll,pair<ll,ll>> p = mp(c[i],mp(0,i));
          edge.pb(p);
       }
       for(ll i = 1; i<=n ; i++) 
       {
          cin>>k[i];
          
        
       }
       for(ll i = 1; i<=n ; i++)
        for(ll j = i+1; j<=n ; j++)
        {
          ll cost = (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
          pair<ll,pair<ll,ll>> p = mp(cost,mp(i,j));
          edge.pb(p);
        }

      sort(edge.begin(),edge.end());
      for(ll i = 0; i<=n ; i++)
        par[i] = i;

      vector<ll> supp;
      for(ll i=0; i<edge.size() ; i++)
      {
        ll u = edge[i].ss.ff;
        ll v = edge[i].ss.ss;
        if(find_set(u)!=find_set(v))
        {
          union_find(u,v);
          
          yen+=edge[i].ff;
          if(u == 0)
            supp.pb(v);
          else
            sel.pb(mp(u,v));

        }
      }

      cout<<yen<<endl;
      cout<<supp.size()<<endl;
      for(auto e: supp)
        cout<<e<<' ';
      cout<<endl;

      cout<<sel.size()<<endl;
      for(auto e: sel)
        cout<<e.ff<<' '<<e.ss<<endl;

       


       return 0;
      
      
      
  }