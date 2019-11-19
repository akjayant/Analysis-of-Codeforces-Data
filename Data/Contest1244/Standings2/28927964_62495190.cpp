#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
ll a[maxn];
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    ll i=0, j=n-1;
    ll x=1, y=1;
    ll c=0, d=0;
    while(k>0)
    {
        if(i==j) break;
        c=a[i+1]-a[i];
        d=a[j]-a[j-1];
        if(x<y)
        {
            if(k>=c*x){ k-=c*x; i++; x++; }
            else{ a[i]+=(k/x); break;}
        }
        else
        {
            if(k>=d*y){ k-=d*y; j--; y++; }
            else{ a[j]-=k/y; break; }
        }
    }
    //cout<<i<<" "<<j<<endl;
    cout<<a[j]-a[i]<<endl;
    return 0;
}

