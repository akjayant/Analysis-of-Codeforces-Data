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
   cin>>TESTS;
    while(TESTS--)
    {
        ll n;
        cin>>n;
        ll o1=0,e1=0;
        rep(i,0,n)
        {
            ll x;
            cin>>x;
            if(x%2==1)
                o1++;
            else
                e1++;
        }
        ll o2=0,e2=0;
        ll m;
        cin>>m;
        rep(i,0,m)
        {
            ll x;
            cin>>x;
            if(x%2==1)
                o2++;
            else
                e2++;
        }
        ll ans=o1*o2+e1*e2;
        cout<<ans<<endl;
    }
    return 0;
}