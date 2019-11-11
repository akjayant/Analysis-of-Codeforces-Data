
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
#define MOD 1000000007
#define N 100005

ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}
//Variables Start   
vector<ll> u,ni,e,d;
ll fibo[N];
int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
        ll n;
        string s;cin>>s;
        fibo[1]=1;
        fibo[0]=1;
        n=s.length();
        bool ok=false;
        rep(i,0,n)
        {
            if(s[i]=='u')u.push_back(i);
            else if(s[i]=='n')ni.push_back(i);
            else if(s[i]=='w'||s[i]=='m')ok=true;
        }
        if(ok)
        {
            cout<<"0"<<endl;
            return 0;
        }
        fibo[0]=1;fibo[1]=1;
        rep(i,2,n+1)fibo[i]=add(fibo[i-1],fibo[i-2]);

        ll cnt=1;

        rep(i,1,u.size())
        {
            if(u[i]!=u[i-1]+1)
            {
                e.push_back(cnt);
                cnt=1;
            }
            else
                cnt++;
        }
        e.push_back(cnt);



        cnt=1;
        rep(i,1,ni.size())
        {
            if(ni[i]!=ni[i-1]+1)
            {
                d.push_back(cnt);
                cnt=1;
            }
            else
                cnt++;
        }
        d.push_back(cnt);
        ll ans=1;
        for(auto i:d)ans=mul(ans,fibo[i]);
        for(auto i:e)ans=mul(ans,fibo[i]);

        cout<<ans<<endl;
        
    
    }
    return 0;
        
}