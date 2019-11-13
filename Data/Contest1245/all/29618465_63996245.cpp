#include <bits/stdc++.h>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define MAXN        200001
int main()
{
    ll int t;
    cin >> t;
    while(t--)
    {
        ll int a,b;
        cin >> a >> b;
        ll int g=__gcd(a,b);
        if (g==1)
        {
            cout << "Finite" << endl;
        }
        else
        {
            cout << "Infinite" << endl;
        }
    }
}