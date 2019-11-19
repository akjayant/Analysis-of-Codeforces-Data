#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,s,f) for(i=s;i<f;i++)
#define print(v) for(auto &z:v) cout<<z<<' ';cout<<'\n'
#define hi cout<<'h'<<'i'<<'\n' 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define B begin()
#define E end()
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int main()
{
    int n,i,j,t;
    boost;

    cin>>t;
    while(t--)
    {
        cin>>n;
        ll odd=0;
        rep(i,0,n)
        {
            cin>>j;
            if(j%2)odd++;
        }
        int m;
        cin>>m;
        ll oddb=0;

        rep(i,0,m)
        {
            cin>>j;
            if(j%2)oddb++;
        }
        ll ans= odd*oddb + (n-odd)*(m-oddb);
        cout<<ans<<'\n';

    }

    return 0;
}

