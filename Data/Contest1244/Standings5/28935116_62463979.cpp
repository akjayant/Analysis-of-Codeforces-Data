 #include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define IOS1 ios_base::sync_with_stdio(false);
#define IOS2    cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll power(ll a,ll b)
{
    ll res =1;
    while(b)
    {
        if(b&1) res = (res%mod*a%mod)%mod;
        b/=2;
        a = (a%mod*a%mod)%mod;
    }
    return res;
}
ll sieve[1000005];
void pre()
{
    sieve[0]=1;
    sieve[1]=1;
    for(int i=2;i<1000005;i++)
    {
        if(sieve[i]==0)
        {
            for(int j=2*i;j<1000005;j+=i)
            {
                sieve[j]=1;
            }
        }
    }
}
signed main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
      
      IOS1
      IOS2
      
      ll q;
      cin>>q;
      while(q--){
      ll a,b,c,d,k;
      cin>>a>>b>>c>>d>>k;
      ll ans1 = (a+c-1)/c;
      ll ans2=(b+d-1)/d;
      if(ans1+ans2>k) cout<<"-1"<<endl;
      else cout<<ans1<<" "<<ans2<<endl;}
      
      
      
      
}


















