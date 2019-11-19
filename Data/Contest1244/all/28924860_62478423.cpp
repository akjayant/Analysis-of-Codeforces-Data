
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
       
  int32_t main()
  {
      IOS
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
      
      int t;
      cin>>t;
      while(t--)
      {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int check=0,ans=0,ans1=0;;
        for(int i=1;i<=k-1;++i)
        {
            int pe=i*c;
            int pe1=(k-i)*d;
            if(pe>=a and pe1>=b)
            {
                check=1;
                ans=i;
                ans1=k-i;
            }
        }
        if(check==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<ans<<" "<<ans1<<endl;
        }
      }
      

  }   