#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define mx 1000005

ll prime[mx],vis[mx],k;

void sieve(){
    prime[k++]=2;
    for(int i=4;i<=mx;i+=2) vis[i]=1;
    for(int i=3;i*i<=mx;i+=2){
        if(!vis[i]){
            for(int j=i*i;j<=mx;j+=2*i) vis[j]=1;
        }
    }
    for(int i=3;i<=mx;i+=2) if(!vis[i]) prime[k++]=i;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    sieve();
    //cout<<prime[k-1]<<endl;
    ll n;
    cin>>n;
    ll x=-1;
    for(int i=0;i<k && prime[i]<n;i++){
        if(n%prime[i]==0){
            x=prime[i];
            break;
        }
    }
    if(x==-1) cout<<n<<endl;
    else{
        ll z=n;
        ll y=1;
        while(z%x==0){
            z/=x;
            y*=x;
        }
        if(y==n) cout<<x<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
