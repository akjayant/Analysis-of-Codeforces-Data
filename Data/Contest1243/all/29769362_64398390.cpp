/**
Code by Nitin1184
**/
# include <bits/stdc++.h>
# define ll long long
# define pi 3.14159265358979323846
# define M 1000000007
# define pb push_back
# define mp make_pair
# define ff first
# define ss second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> v;
    unordered_map<ll,ll> m;
    ll x=n;
    while(x%2==0)
    {
        m[2]++;
        x=x/2;
    }
    for(ll i=3;i*i<=x;i+=2)
    {
        while(x%i==0)
        {
            m[i]++;
            x=x/i;
        }
    }
    if(x>2)
        m[x]++;
    ll f=0,c=0,val=-1;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->ff==1 || it->ff==n)
            continue;
        else
        {
            c++;
            val=it->ff;
        }
    }
    if(c==0)
        cout<<n<<endl;
    else
    {
        if(c==1)
            cout<<val<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}