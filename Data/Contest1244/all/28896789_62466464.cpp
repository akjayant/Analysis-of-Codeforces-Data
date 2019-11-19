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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;

    int lec,prac,pen,pencil,pernica;
    while(t>0)
    {
        cin>>lec>>prac>>pen>>pencil>>pernica;

        int min_pen=(lec+pen-1)/pen;
        int min_pencil=(prac+pencil-1)/pencil;

        if(min_pen+min_pencil<=pernica)
        {
            cout<<min_pen<<" "<<min_pencil<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        t--;
    }
    return 0;
}
