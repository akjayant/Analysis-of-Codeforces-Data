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
    cin>>TESTS;
    while(TESTS--)
    {
        ll n;
        cin>>n;
        ll a=0,b=0,c=0,d=0;
        for(int i=0;i<n;i++)
        {
        	ll x;
        	cin>>x;
        	if(x%2)
        		a++;
        	else
        		b++;
        }
        ll m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
        	ll x;
        	cin>>x;
        	if(x%2)
        		c++;
        	else
        		d++;
        }
        ll ans=0;
        ans=a*c+b*d;
        cout<<ans<<endl;
    }
    return 0;
}