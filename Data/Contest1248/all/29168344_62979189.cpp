#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define M 1000000007
#define Fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
ll po(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return po((x*x)%M,n/2);
    else
        return (x*po((x*x)%M,(n-1)/2))%M;

}
ll GCD(ll A, ll B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
int main()
{
    Fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        ll p[n];
        ll o=0;
        ll e=0;
        for(int i=0;i<n;++i)
        {
            cin>>p[i];
            if(p[i]%2==0)
                ++e;
            else
                ++o;
        }
        cin>>m;
        ll q[m]={0};
        ll an=0;
        for(int i=0;i<m;++i)
        {
            cin>>q[i];
            if(q[i]%2==0)
                an+=e;
            else
                an+=o;
        }
        cout<<an<<"\n";
        
    }
}