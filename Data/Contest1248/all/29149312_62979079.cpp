/*
 _     _    ___  ___  __ __ 
| |   | |  |__ \|__ \/_ /_ |
| |__ | |__   ) |  ) || || |
| '_ \| '_ \ / /  / / | || |
| |_) | |_) / /_ / /_ | || |
|_.__/|_.__/____|____||_||_|

*/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

#define N  100005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        ll n;
        cin>>n;
        vi v;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            v.pb(x);
        }
        sort(all(v));
        ll a=0,b=0;
        rep(i,0,n/2)
        {
            a+=v[i];
        }
        rep(i,n/2,n)
        b+=v[i];
        ll ans=a*a+b*b;
        cout<<ans<<endl;
    }
    return 0;
}