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
#define clean(arr) memset(arr,0,sizeof(arr))
#define mod 1000000007
#define mod2 998244353
#define space 100005
//<<fixed << setprecision(9)

int fun(string &s)
{
    int n=s.size(),i,j;
    vii v;
    int open=0,close=0;
    for(i=n-1;i>=0;i--)
    {
        if(s[i]==')')close++;
        else
        {
            if(close!=0)
            {
                close--;
            }
            else open++;
        }
        v.pb({open,close});
    }
    int ans=0;
    if(open==0 && close==0)ans++;
    int o=0,c=0;
    rep(i,0,n-1)
    {
        if(s[i]=='(')o++;
        else
        {
            if(o!=0)
            {
                o--;
            }
            else c++;
        }

        open=v[n-1-i-1].F;
        close=v[n-1-i-1].S;

        if(o==0 && close==0 && c==open)ans++;
    }
    v.clear();
    return ans;
}

int main()
{
    int n,i,j,t;
    boost;

    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    pii p={1,1};
    rep(i,0,n)
    {
        rep(j,i,n)
        {
            swap(s[i],s[j]);
            fun(s);
            int temp=fun(s);
            if(temp>ans)
            {
                ans=temp;
                p={i+1,j+1};
            }
            swap(s[i],s[j]);
        }
    }
    cout<<ans<<'\n';
    cout<<p.F<<' '<<p.S;
    return 0;
}

