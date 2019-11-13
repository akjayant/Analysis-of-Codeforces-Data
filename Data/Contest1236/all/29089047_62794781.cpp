        #include<bits/stdc++.h>
        using namespace std;
        const int mod=1e9+7;
        const int mex=1e5+1;
        #define ll long long 
        #define test int t;cin>>t;while(t--)
        #define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
        #define fo(i,a,n) for(int i=a;i<n;i++)
        #define rfo(i,a,b) for(int i=a;i>=b;i--)
        #define bg begin()
        #define en end()
        #define fi first
        #define se second
        #define ub upper_bound
        #define lb lower_bound
        #define pb push_back
        #define veci vector<int>
        #define veclli vector<long long int> 
        #define all(x) x.begin(),x.end()
        #define sci(x) scanf("%d",&x);
        #define scc(x) scanf("%c",&x);
        #define scs(x) scanf("%s",x);
        #define sclli(x) scanf("%lld",&x);
        #define pii pair<int,int>
        #define plli pair<long long int ,lont long int>
        #define foit(it,x) for(auto it=x.begin();it!=x.end();it++)
        #define debug(arr,n) for(int i=0;i<n;i++) printf("%d ",arr);
        #define sz(x) x.size()
        int power(int n,int l)
        {
            ll int ans=1,t=n;
            while(l)
            {
                if(l&1) ans=(ans*t)%mod;
                t=(t*t)%mod;
                l=l>>1;
            }
            return ans;
        }
        
        int main()
        {
          ll int n;
          cin>>n;
          ll int k=n*n;
          vector<int> v[n+1];
          bool b=true;
          int i=1;
          while(i<=k)
          {
            fo(j,1,n+1)
            {
                if(b)
                v[j].pb(i);
                else 
                {
                    v[n+1-j].pb(i);
                }
                i++;
            }
            b=!b;
            
          }
          fo(i,1,n+1)
          {
              fo(j,0,n)
              cout<<v[i][j]<<" ";
              cout<<endl;
          }
        }