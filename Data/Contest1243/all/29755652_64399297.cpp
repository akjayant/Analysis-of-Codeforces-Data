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
        
        string s,t;
        
        cin>>s>>t;
        
        int fa[26]={0};
        
        rep(i,0,n)
        fa[s[i]-'a']++;
        
        rep(i,0,n)
        fa[t[i]-'a']++;
        
        int stop=0;
        
        rep(i,0,26)
        if(fa[i]&1)
        {
            printf("No\n");
            
            stop=1;
            
            break;
        }
        
        if(stop)
        continue;
        
        printf("Yes\n");
        
        vector<pair<int,int>> v;
        
        rep(i,0,n)
        {
            if(s[i]==t[i])
            continue;
            
            int flag=0;
            
            rep(j,i+1,n)
            if(s[j]==s[i])
            {
                swap(s[j],t[i]);
                
                v.pb(mp(j,i));
                
                flag=1;
                
                break;
            }
            
            if(flag)
            continue;
            
            rep(j,i+1,n)
            if(t[j]==t[i])
            {
                swap(t[j],s[i]);
                
                v.pb(mp(i,j));
                
                flag=1;
                
                break;
            }
            
            if(flag)
            continue;
            
            rep(j,i+1,n)
            if(t[j]==s[i])
            {
                swap(s[j],t[j]);
                
                v.pb(mp(j,j));
                
                swap(s[j],t[i]);
                
                v.pb(mp(j,i));
                
                flag=1;
                
                break;
            }
            
            if(flag)
            continue;
            
            rep(j,i+1,n)
            if(s[j]==t[i])
            {
                swap(s[j],t[j]);
                
                v.pb(mp(j,j));
                
                swap(s[i],t[j]);
                
                v.pb(mp(i,j));
                
                flag=1;
                
                break;
            }
            
            if(flag)
            continue;
        }
        
        int sz=(int)v.size();
        
        priln(sz);
        
        for(auto it:v)
        printf("%d %d\n",it.F+1,it.S+1);
    }
}