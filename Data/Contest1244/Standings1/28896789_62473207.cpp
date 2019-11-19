#include<bits/stdc++.h>
#define maxn 200005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
using namespace std;


ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;


    while(t>0)
    {
        cin>>n;
        cin>>s;

        int sol=n;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                sol=max(n+1,sol);
                sol=max(2*i+2,sol);
                sol=max(2*(n-i),sol);
            }
        }

        cout<<sol<<"\n";

        t--;
    }
    return 0;
}
