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
const int N=1e5+4;
int main()                  
{
    int t;
    
    scn(t);
    
    while(t--)
    {
        int n;
        
        scn(n);
        
        int a[n],fa[n+4]={0};
        
        rep(i,0,n)
        {
            scn(a[i]);
            
            fa[a[i]]++;
        }
        
        rep(i,1,n+1)
        fa[i]+=fa[i-1];
        
        int val=1;
        
        rep(i,1,n+1)
        if(fa[n]-fa[i-1]>=i)
        val=i;
        
        priln(val);
    }
}