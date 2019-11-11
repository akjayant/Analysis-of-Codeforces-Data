#include<bits/stdc++.h>
#define ll long long
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;

ll modexp(ll x, ll n)
{
    if(n==0)
        return 1LL;
    if(n%2==0)
    {
        ll y = modexp(x,n/2)%mod;
        return (y*y)%mod;
    }
    return (x*modexp(x,n-1)%mod)%mod;
}

ll powr(ll x, ll n)
{
    ll auxans = 1;
    for(int i=1;i<=n;i++)
        auxans=auxans*x;
    return auxans;
}

ll f[MAX];
int n, R, P, S;


int main() 
{    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    f[0] = 1;
    for(int i=1;i<MAX;i++)
    {
        f[i] = (f[i-1]*i)%mod;
    }
    int t;
    cin>>t;
    while(t--) 
    {
        cin>>n>>R>>P>>S;
        string st;
        cin>>st;

        int r = 0, p= 0,s = 0;
        for(int i=0;i<st.size();i++) 
        {
            if(st[i]=='R')
                r++;
            else if(st[i]=='P')
                p++;
            else 
                s++;
        }
        int auxans = min(R, s) + min(P, r) + min(S, p);
        int req = n/2;
        if(n%2)
            req++;
        if(auxans>=req) 
        {
            cout<<"YES\n";
            string res;
            for(int i=0;i<st.size();i++) 
            {
                if(st[i]=='R') 
                {
                    if(P!=0) 
                    {
                        res+='P';
                        P--;
                    }
                    else 
                    {
                        res+='$';
                    }

                }
                else if(st[i]=='P') 
                {
                    if(S!=0) 
                    {
                        res+='S';
                        S--;
                    }
                    else 
                    {
                        res+='$';
                    }
                }
                else 
                {
                    if(R!=0) 
                    {
                        res+='R';
                        R--;
                    }
                    else 
                    {
                        res+='$';
                    }
                }
            }
            for(int i=0;i<st.size();i++) 
            {
                if(res[i]=='$') 
                {
                    if(P!=0)
                    {
                        res[i]='P'; 
                        P--;
                    }
                    else if(R!=0)
                    {
                        res[i]='R'; 
                        R--;
                    }
                    else if(S!=0)
                    {
                        res[i]='S'; 
                        S--;
                    }
                }
            }
            cout<<res<<endl;
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}