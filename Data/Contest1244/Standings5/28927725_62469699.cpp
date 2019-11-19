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
        ll i,n,j,a=0,b=0;
        cin>>n;
        string s;
        cin>>s;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                break;
            a++;
        }
        for(j=n-1;j>=0;j--)
        {
            if(s[j]=='1')
                break;
            b++;
        }
        if(i==n)
        {
            cout<<n<<endl;
            continue;
        }
        if(a<=b)
        {
            cout<<2*(n-i)<<endl;
        }
        else
            cout<<2*(j+1)<<endl;
    }
    return 0;
}
