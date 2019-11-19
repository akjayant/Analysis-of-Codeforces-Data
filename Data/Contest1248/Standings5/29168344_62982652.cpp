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
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    int i=0,j=n-1;
    ll x=0,y=0;
    ll c=0;
    while(c<n)
    {
        if(c%2==0)
            x+=a[j--];
        else
            y+=a[i++];
        c++;
    }
    cout<<x*x+y*y;
}