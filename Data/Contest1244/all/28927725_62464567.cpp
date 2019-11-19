#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
#define ex exit(0)
#define For for(i=0;i<n;++i)
ll Min(ll a,ll b)
{
    if(a>=b)
        return b;
    else
        return a;
}
ll Max(ll a,ll b)
{
    if(a>=b)
        return a;
    else
        return b;
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll l,p,a,b,k,x,y;
        cin>>l>>p>>a>>b>>k;
        if(l%a==0)
            x=l/a;
        else
            x=(l/a)+1;
        
        if(p%b==0)
            y=p/b;
        else
            y=(p/b)+1;
        if(x+y<=k)
            cout<<x<<" "<<y<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
