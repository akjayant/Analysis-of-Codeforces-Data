#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
#define plll pair<pll,pll>
#define xx first.first
#define yy first.second
#define zz second.first
#define br second.second
#define INF 1000000000
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
    while(t>0)
    {
        int a,b,c;
        cin>>a>>b>>c;

        int tre_a=a,tre_b=b,tre_c=c;
        int sol=0;
        for(int i=0;i<=a && 2*i<=b;i++)
        {
            tre_a-=i;
            tre_b-=2*i;

            int tre=3*i + 3*min(tre_b, tre_c/2);
            sol=max(sol,tre);

            tre_a=a;
            tre_b=b;
            tre_c=c;
        }

        cout<<sol<<"\n";

        t--;
    }

    return 0;
}
