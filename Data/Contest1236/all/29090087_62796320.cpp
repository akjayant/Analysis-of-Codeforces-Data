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
#define MAXN        100001
int main()
{
    ll int n;
    cin >> n;
    rep(i,1,n+1)
    {
        rep(j,0,n)
        {
            if (j%2==0)
            {
                cout << i+n*j << " ";
            }
            else
            {
                cout << n*j+(n+1-i) << " ";
            }
        }
        cout << endl;
    }
}