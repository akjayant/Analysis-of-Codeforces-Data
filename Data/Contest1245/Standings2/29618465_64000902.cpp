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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll int t;
    cin >> t;
    while(t--)
    {
        ll int n;
        cin >> n;
        ll int a,b,c;
        cin >> a >> b >> c;
        char ans[n];
        rep(i,0,n) ans[i]='u';
        ll int wins=0;
        rep(i,0,n)
        {
            char c1;
            cin >> c1;
            if (c1=='R' and b>=1)
            {
                b=b-1;
                ans[i]='P';
                wins=wins+1;
            }
            if (c1=='P' and c>=1)
            {
                c=c-1;
                ans[i]='S';
                wins=wins+1;
            }
            if (c1=='S' and a>=1)
            {
                a=a-1;
                ans[i]='R';
                wins=wins+1;
            }
        }
        if ((2*wins)>=n)
        {
            cout << "Yes" << endl;
            rep(i,0,n)
            {
                if (ans[i]=='u')
                {
                    if (a>=1) {ans[i]='R';a=a-1;}
                    else if (b>=1) {ans[i]='P';b=b-1;}
                    else if (c>=1) {ans[i]='S';c=c-1;}
                }
                cout << ans[i];
            }
            cout << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}