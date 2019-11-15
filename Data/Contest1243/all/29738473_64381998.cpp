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
#define sz(v) (int)((v).size())
#define vi vector<int>
#define vii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define clk1 clock_t start_time=clock()
#define clk2 cout<<(clock()-start_time)/(double)CLOCKS_PER_SEC
#define clean(arr) memset(arr,0,sizeof(arr))
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
        string s,p;
        cin>>s>>p;
        vi v;
        int c=0;
        rep(i,0,n)
        {
            if(s[i]!=p[i])
            {
                c++;v.pb(i);
            }
        }
        
        if(c==2)
        {
            i=v[0];
            j=v[1];
            if(s[i]==s[j] && p[i]==p[j])
            {

                cout<<"YES\n";continue;
            }
        }
        cout<<"NO\n";

        
    }

    return 0;
}

