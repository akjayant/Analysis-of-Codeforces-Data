#include<bits/stdc++.h>
#define int long long int
#define ull unsigned long long int
#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rev(i,n,init) for(int i=n;i>=init;i--)
#define MAXN 200005
#define MOD 1000000007
#define f first
#define s second
#define endl '\n'
#define pii pair<int,int>
#define precise(i) cout<<fixed<<setprecision(i)
using namespace std;
const double PI = atan(1.0)*4;
const int64_t INF=100000000000000003;
const int32_t LOG=21;
const int BIG=pow(2,20);
vector<int> v;
bool prime[1000005];
void sieve(int n)
{
    for(int i=2;i<=n;i++)
    {
       if(prime[i])
       {
          for(int j=2*i;j<=n;j+=i)
          {
               prime[j]=false;
          }
       } 
    }  
}
int32_t main(){
        getFaster;
        int n;
        cin>>n;
        fill(prime,prime+1000004,true);
        prime[1]=false;
        sieve(1000001);
        if(n==1)
        {
          cout<<1<<endl;
          return 0;
        }  
          for(int i=1;i*i<=n;i++)
          {
             if(n%i==0)
             {
                int x=i;
                int y=n/i;
                v.push_back(x);
                if(x!=y)v.push_back(y);
             } 
          }
          sort(v.begin(),v.end());  
          if(v.size()==2)
          {
             cout<<n<<endl;
             return 0;
          }
          int temp=-1;
          rep(i,0,v.size())
          {
              if(v[i]<1000000 && prime[v[i]])
              {
                 temp=v[i];
                 break;
              }  
          }
          int ans=temp;
          while(temp<n)
          {
             temp=temp*ans;  
          }
          if(temp==n)
          {
            cout<<ans<<endl;
          }
          else
          {
            cout<<1<<endl;
          }          
          return 0;
}