#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define plll pair<pll,pll>
using namespace std;


/*ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}*/

int n;
int r,p,s;
string a;
string sol;
int r2,p2,s2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t>0)
    {
        sol.clear();
        t--;
        cin>>n;
        cin>>r>>p>>s;
        cin>>a;

        sol.resize(n);
        //cout<<sol<<endl;

        int maxx=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R')
            {
                if(p>0)
                {
                    sol[i]='P';
                    p--;
                    maxx++;
                }
                else
                {
                    sol[i]='?';
                }
            }

            if(a[i]=='S')
            {
                if(r>0)
                {
                    sol[i]='R';
                    r--;
                    maxx++;
                }
                else
                {
                    sol[i]='?';
                }
            }

            if(a[i]=='P')
            {
                if(s>0)
                {
                    sol[i]='S';
                    s--;
                    maxx++;
                }
                else
                {
                    sol[i]='?';
                }
            }
        }

        int potrebno;
        if(n%2==0)potrebno=n/2;
        else potrebno=(n+1)/2;

        if(maxx<potrebno)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";

            for(int i=0;i<n;i++)
            {
                if(sol[i]=='?')
                {
                    if(p>0)
                    {
                        sol[i]='P';
                        p--;
                    }
                    else if(s>0)
                    {
                        sol[i]='S';
                        s--;
                    }
                    else
                    {
                        sol[i]='R';
                        r--;
                    }
                }
            }
            cout<<sol<<"\n";
        }
    }


    return 0;
}
