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
        vii ans;
        bool ok=1;
        rep(i,0,n-1)
        {
            if(s[i]!=p[i])
            {
                rep(j,i+1,n)
                {
                    if(s[j]==s[i])
                    {
                        ans.pb({j,i});
                        swap(s[j],p[i]);break; 
                    }
                }
                if(j==n)
                {
                    rep(j,i+1,n)
                    {
                        if(p[j]==s[i])
                        {
                            ans.pb({i+1,j});
                            swap(s[i+1],p[j]);
                            ans.pb({i+1,i});
                            swap(s[i+1],p[i]);break;
                        }
                    }
                    if(j==n)
                    {
                        ok=0;break;
                    }
                }
            }
        }
        if(s[n-1]!=p[n-1])ok=0;
        if(!ok)cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            cout<<sz(ans)<<'\n';
            for(auto z:ans)
            {
                cout<<z.F+1<<' '<<z.S+1<<'\n';
            }
        }
    }

    return 0;
}

