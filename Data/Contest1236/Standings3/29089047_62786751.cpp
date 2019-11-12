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
          int n,m;
          cin>>n>>m;
          ll int ans=(power(2,m)-1+mod)%mod;
          ans=power(ans,n);
          cout<<ans<<endl;
        }