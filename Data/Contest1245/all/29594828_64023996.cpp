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
  ll vis[200000]={};
  ll dp[200000]={};
  ll fx(ll n)
  {
    if(vis[n])
      return dp[n];
    if(n == 0 || n == 1)
      return 1;
    if(n == 2)
      return 2;
    else
    {
      ll ans = 1;
        // if(n==0)
        // for(ll i = n-2; i>=0 ; i--)
        // {
        //   ans = (ans+fx(i))%mod;
        // }
        // else
        //{
          ans = (ans + fx(n-2)+fx(n-1)-1+mod)%mod;
        //}
      vis[n]=1;
      dp[n]=ans;
      return ans;
    }
  }

    int  main()
    {
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
        
      string s;
      cin>>s;
      ll chk = 1;
      ll n = s.size();
      
      ll cur = 0;
      ll store = 0;
      ll truans = 1;
      for(ll i = 0; i<n ; i++)
      {
        if(s[i]=='w' || s[i]=='m')
          chk=0;

        if((s[i]=='u' && cur == 2)||(s[i]=='n' && cur==1))
          store++;
        else
        {
          truans = (truans*fx(store))%mod;
          store = 0;
          if(s[i]=='u')
          {
            cur = 2;
            store++;
          }
          else if(s[i]=='n')
          {
            cur = 1;
            store++;
          }
          else
            cur = 0;
        }
        
        if(i == n-1 && store>0)
          truans = (truans*fx(store))%mod;
       
      }

      if(chk)
      cout<<truans<<endl;

      else
        cout<<0<<endl;








       return 0;
      
      
      
    }