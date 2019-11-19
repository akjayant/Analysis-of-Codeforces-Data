#include<bits/stdc++.h>
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
using namespace std;
const ll mod=1e9+7;         
const int N=2e5+4;
int main()                  
{
    int n;
    
    scn(n);
    
    ll a[n],x=0,y=0,ans;
    
    int flag=0,l=0,r=n-1;
    
    rep(i,0,n)
    lscn(a[i]);
    
    sort(a,a+n,greater<ll>());
    
    while(l<=r)
    {
        if(flag==0)
        x+=a[l++];
        else
        y+=a[r--];
        
        flag^=1;
    }
    
    //cout<<x<<" "<<y<<endl;
    
    ans=(x*x)+(y*y);
    
    lpri(ans);
}