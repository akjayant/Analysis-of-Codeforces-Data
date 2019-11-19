/* ****mittal**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
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
        ll a[n+3];
        ll x=0,y=0;
        for(int i=0;i<n;i++)
        {
        	cin>>a[i];
        	y+=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n/2;i++)
        {
        	x+=a[i];
        }
        cout<<x*x+(y-x)*(y-x);

    }
    return 0;
}